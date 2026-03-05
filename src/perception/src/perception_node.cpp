#include "perception/perception_node.hpp"

namespace perception{

    PerceptionNode::PerceptionNode()  
    : Node("perception_node"), 
      last_process_time(std::chrono::steady_clock::now())
    {
        // Declare parameters
        this->declare_parameter<int>("target_fps", 15);
        this->declare_parameter<std::string>("camera_topic", "/front_camera/image_raw");

        // Get parameters
        this->get_parameter("target_fps", target_fps_);
        this->get_parameter("camera_topic", camera_topic_);

        // Calculate preprocessing interval
        process_interval_ms = 1000.0 / static_cast<double>(target_fps_);

        auto param_cb = [this](const std::vector<rclcpp::Parameter>& parameters){
            rcl_interfaces::msg::SetParametersResult result;
            result.successfull = true;

            for(const auto& param : parameters){
                if(param.get_name() == "target_fps"){
                    target_fps_ = param.as_int();
                    process_interval_ms_ = 1000.0 / static_cast<double>(target_fps_);

                    RCLCPP_INFO(this->get_logger(), "Target FPS updated to %d", target_fps_);
                }
            }

            return result;
        };
        this->add_on_set_parameters_callback(param_cb);

        // Subscriber
        image_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
            camera_topic_,
            10,
            std::bind(&PerceptionNode::image_callback, this, std::placeholders::_1)
        );

        // Publisher for debug viz
        debug_pub_ = this->create_publisher<sensor_msgs::msg::Image>(
            "perception/debug_image",
            10
        );

        RCLCPP_INFO(this->get_logger(),
            "Perception Node Started | camera: %s | target_fps: %d",
            camera_topic_.c_str(), target_fps_);
    }

    void PerceptionNode::image_callback(const sensor_msgs::msg::Image::SharedPtr msg){
        // FPS Throttling
        auto now = std::chrono::steady_clock::now();
        auto elapsed_ms = std::chrono::duration<double, std::milli>(now - last_processed_time_).count();

        if(elapsed_ms < process_interval_ms) return; // Skip frame if we're processing too fast

        last_processed_time_ = now;

        // Convert ROS image to OpenCV
        cv_bridge::CvImagePtr cv_ptr;
        try{
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        } catch(cv_bridge::Exception& e){
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
            return;
        }

        cv::Mat processed = process_frame(cv_ptr->image);

        // Publish debug image
        sensor_msgs::msg::Image::SharedPtr debug_msg = 
            cv_bridge::CvImage(msg->header, "bgr8", processed).toImageMsg();
        debug_pub_-publish(*debug_msg);
        
        // TODO: Run YOLO inference here
        // TODO: Publish DetectionArray

        RCLCPP_DEBUG(this->get_logger(), "Processed frame at %d FPS", target_fps_);
    }

    cv::Mat PerceptionNode::process_frame(const cv::Mat& input){
        // Placeholder processing - just Canny edge detection
        // Replace this with YOLO inference in Stage 2
        cv::Mat edges;
        cv::Canny(input, edges, 50, 150);
        
        // Convert back to BGR for visualization
        cv::Mat output;
        cv::cvtColor(edges, output, cv::COLOR_GRAY2BGR);
        
        return output;
    }
}// namespace perception

int main(int argc, char ** argv){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<perception::PerceptionNode>());
    rclcpp::shutdown();
    return 0;
}