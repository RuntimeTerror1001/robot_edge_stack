#ifndef PERCEPTION__YOLO_DETECTOR_HPP_
#define PERCEPTION__YOLO_DETECTOR_HPP_

#include "perception/tensorrt_engine.hpp"
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

namespace perception{

    struct Detection{
        int class_id;
        float conf;
        cv::Rect box;
    };

    class YOLODetector{
        public:
            YOLODetector();
            ~YOLODetector() = default;

            bool initialize(const std::string& engine_path, float conf_threshold = 0.25, float nms_threshold = 0.45);
            std::vector<Detection> detect(const cv::Mat& image);

        private:
            cv::Mat preprocess(const cv::Mat& image);
            std::vector<Detection> postprocess(const std::vector<float>& output, const cv::Size& original_size);

            std::unique_ptr<TensorRTEngine> engine_;
            int input_width_;
            int input_height_;
            float conf_thresh_;
            float nms_thresh_;
    };

} // namespace perception

#endif