#ifndef PERCEPTION__PERCEPTION_NODE_HPP
#define PERCEPTION__PERCEPTION_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <chrono>

namespace perception{
    class PerceptionNode: public rclcpp::Node{
        public:
            PerceptionNode();

        private:
            void image_callback(const sensor_msgs::msg::Image::SharedPtr msg);
            cv::Mat process_frame(const cv::Mat & input);

	    // Param Callback Handler
	    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr param_callback_handle_;

            // Subscriptions
            rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;

            // Publishers
            rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr debug_pub_;

            // Parameters
            int target_fps_;
            std::string camera_topic_;

            // FPS Tracking
            std::chrono::steady_clock::time_point last_process_time_;
            double process_interval_ms_;
    };
} // namespace perception
 
#endif // PERCEPTION__PERCEPTION_NODE_HPP
