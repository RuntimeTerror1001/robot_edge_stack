#include "perception/perception_node.hpp"

namespace perception{

    PerceptionNode::PerceptionNode()  
    : Node("perception_node"), 
      last_process_time_(std::chrono::steady_clock::now())
    {
        // Declare parameters
        this->declare_parameter<int>("target_fps", 15);
        this->declare_parameter<std::string>("camera_topic", "/front_camera/image_raw");
        this->declare_parameter<std::string>("engine_path", "/ws/models/yolov8n.engine");
        this->declare_parameter<float>("conf_thresh", 0.25);
        this->declare_parameter<float>("nms_thres", 0.45);

        // Get parameters
        this->get_parameter("target_fps", target_fps_);
        this->get_parameter("camera_topic", camera_topic_);
        this->get_parameter("engine_path", engine_path_);
        this->get_parameter("conf_threshold", conf_thresh_);
        this->get_parameter("nms_threshold", nms_thresh_);

        // Calculate preprocessing interval
        process_interval_ms_ = 1000.0 / static_cast<double>(target_fps_);

        // Register parameter callback for dynamic FPS updates 
        auto param_cb = [this](const std::vector<rclcpp::Parameter>& parameters){
            rcl_interfaces::msg::SetParametersResult result;
            result.successful = true;

            for(const auto& param : parameters){
                if(param.get_name() == "target_fps"){
                    target_fps_ = param.as_int();
                    process_interval_ms_ = 1000.0 / static_cast<double>(target_fps_);

                    RCLCPP_INFO(this->get_logger(), "Target FPS updated to %d", target_fps_);
                }
            }

            return result;
        };
        param_callback_handle_ = this->add_on_set_parameters_callback(param_cb);

        // Initialize YOLO Detector
        detector_ = std::make_unique<YOLODetector>();
        if(!detector_->initialize(engine_path_, conf_thres_, nms_thres_)){
            RCLCPP_ERROR(this->get_logger(), "Failed to initialize YOLO Detector");
            rclcpp::shutdown();
            return;
        }

        // Subscriber
        image_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
            camera_topic_,
            10,
            std::bind(&PerceptionNode::image_callback, this, std::placeholders::_1)
        );

        // Publishers
        debug_pub_ = this->create_publisher<sensor_msgs::msg::Image>(
            "perception/debug_image",
            10
        );

        detection_pub_ = this->create_publisher<vision_msgs::msg::Detection2DArray>(
            "perception/detections",
            10
        );

        RCLCPP_INFO(this->get_logger(),
            "Perception Node Started | camera: %s | target_fps: %d",
            camera_topic_.c_str(), target_fps_);
    }

    void PerceptionNode::image_callback(const sensor_msgs::msg::Image::SharedPtr msg){
        // FPS Throttling
        auto now = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration<double, std::milli>(now - last_process_time_).count();

        if(elapsed_ms < process_interval_ms_) return; // Skip frame if we're processing too fast

        auto start_time = std::chrono::steady_clock::now();
        last_process_time_ = now;

        // Convert ROS image to OpenCV
        cv_bridge::CvImagePtr cv_ptr;
        try{
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        } catch(cv_bridge::Exception& e){
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
            return;
        }

        // Run YOLO Detection
        std::vector<Detection> detections = detector_->detect(cv_ptr->image);

        // Publish Detection2DArray
        auto det_array_msg = vision_msgs::msg::Detection2DArray();
        det_msg_array.header = msg->header;

        for(const auto& det : detections){
            vision_msgs::msg::Detection2D det_msg;
            det_msg.header = msg->header;

            // Bounding Box (Center + size)
            det_msg.bbox.center.position.x = det.box.x + det.box.width / 2.0;
            det_msg.bbox.center.position.y = det.box.y + det.box.height / 2.0;
            det_msg.bbox.size_x = det.box.width;
            det_msg.bbox.size_y = det.box.height;

            // Class Hypothesis
            vision_msgs::msg::ObjectHypothesisWithPose hyp;
            hyp.hypothesis.class_id = std::to_string(det.class_id);
            hyp.hypothesis.score = det.conf;
            det_msg.results.push_back(hyp);

            // Source ID
            det_msg.id = std::to_string(det.class_id);
            det_array_msg.detections.push_back(det_msg);
        }

        auto end_time = std::chrono::steady_clock::now();
        auto inference_time = std::chrono::duration<double, std::milli>(end_time - start_time).count();

        detection_pub_->publish(det_array_msg);

        // Draw and publish debug image
        cv::Mat debug_image = draw_detections(cv_ptr->image, detections);
        sensor_msgs::msg::Image::SharedPtr debug_msg = 
            cv_bridge::CvImage(msg->header, "bgr8", debug_image).toImageMsg();
        debug_pub_->publish(*debug_msg);

        uint32_t fps = static_cast<uint32_t>(1000.0 / inference_time);

        RCLCPP_INFO(this->get_logger(),
            "Detected %zu objects | inference: %.1fms | actual FPS: %d",
            detections.size(), inference_time, fps);
    }

    cv::Mat PerceptionNode::draw_detections(
        const cv::Mat& image,
        const std::vector<Detection>& detections)
    {
        cv::Mat output = image.clone();

        for(const auto& det: detections){
            // Draw bounding box
            cv::rectangle(output, det.box, cv::Scalar(0,255,0), 2);

            // Draw Label
            std::string label = COCO_CLASSES[det.class_id] + " " + 
                                std::to_string(static_cast<int>(det.conf * 100)) + "%";

            int baseline;
            cv::Size label_size = cv::getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseline);

            cv::rectangle(output,
                          cv::Point(det.box.x, det.box.y - label_size.height - 5),
                          cv::Point(det.box.x + label_size.width, det.box.y),
                          cv::Scalar(0, 255, 0), -1);

            cv::putText(output, label,
                        cv::Point(det.box.x, det.box.y - 5),
                        cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0), 1);
        }

        return output;
    }
}// namespace perception

int main(int argc, char ** argv){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<perception::PerceptionNode>());
    rclcpp::shutdown();
    return 0;
}
