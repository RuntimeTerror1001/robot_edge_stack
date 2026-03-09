#ifndef PERCEPTION__PERCEPTION_NODE_HPP
#define PERCEPTION__PERCEPTION_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <chrono>

#include "perception/yolo_detector.hpp"
#include "vision_msgs/msg/detection2_d.hpp"
#include "vision_msgs/msg/detection2_d_array.hpp"
#include "vision_msgs/msg/object_hypothesis_with_pose.hpp"

namespace perception{

    // COCO class names
    const std::vector<std::string> COCO_CLASSES = {
        "person", "bicycle", "car", "motorcycle", "airplane", "bus", "train", "truck", "boat",
        "traffic light", "fire hydrant", "stop sign", "parking meter", "bench", "bird", "cat",
        "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe", "backpack",
        "umbrella", "handbag", "tie", "suitcase", "frisbee", "skis", "snowboard", "sports ball",
        "kite", "baseball bat", "baseball glove", "skateboard", "surfboard", "tennis racket",
        "bottle", "wine glass", "cup", "fork", "knife", "spoon", "bowl", "banana", "apple",
        "sandwich", "orange", "broccoli", "carrot", "hot dog", "pizza", "donut", "cake", "chair",
        "couch", "potted plant", "bed", "dining table", "toilet", "tv", "laptop", "mouse", "remote",
        "keyboard", "cell phone", "microwave", "oven", "toaster", "sink", "refrigerator", "book",
        "clock", "vase", "scissors", "teddy bear", "hair drier", "toothbrush"
    };

    class PerceptionNode: public rclcpp::Node{
        public:
            PerceptionNode();

        private:
            void image_callback(const sensor_msgs::msg::Image::SharedPtr msg);
            cv::Mat draw_detections(const cv::Mat& image, const std::vector<Detection>& detections);

	        // Param Callback Handler
	        rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr param_callback_handle_;

            // Subscriptions
            rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;

            // Publishers
            rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr debug_pub_;
            rclcpp::Publisher<vision_msgs::msg::Detection2DArray>::SharedPtr detection_pub_;

            // YOLO Detector
            std::unique_ptr<YOLODetector> detector_;

            // Parameters
            int target_fps_;
            std::string camera_topic_;
            std::string engine_path_;
            float conf_thresh_;
            float nms_thresh_;

            // FPS Tracking
            std::chrono::steady_clock::time_point last_process_time_;
            double process_interval_ms_;
    };
} // namespace perception
 
#endif // PERCEPTION__PERCEPTION_NODE_HPP
