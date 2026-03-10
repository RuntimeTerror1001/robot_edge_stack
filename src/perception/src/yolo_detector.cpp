#include "perception/yolo_detector.hpp"
#include <algorithm>

namespace perception{

    YOLODetector::YOLODetector()
    : input_width_(640),
      input_height_(640),
      conf_thresh_(0.25),
      nms_thresh_(0.45)
    {}

    bool YOLODetector::initialize(const std::string& engine_path, float conf_thresh, float nms_thresh){
        conf_thresh_ = conf_thresh;
        nms_thresh_ = nms_thresh;

        engine_ = std::make_unique<TensorRTEngine>();
        if(!engine_->load_engine(engine_path)){
            std::cerr << "Failed to load TensorRT Engine" << std::endl;
            return false;
        }

        std::cout << "YOLO Detector Initialized" << std::endl;
        return true;
    }

    cv::Mat YOLODetector::preprocess(const cv::Mat& image){
        cv::Mat resized;
        cv::resize(image, resized, cv::Size(input_width_, input_height_));

        // Convert BGR to RGB and normalize to [0,1]
        cv::Mat rgb;
        cv::cvtColor(resized, rgb, cv::COLOR_BGR2RGB);
        rgb.convertTo(rgb, CV_32F, 1.0 / 255.0);

        return rgb;
    }

    std::vector<Detection> YOLODetector::detect(const cv::Mat& image){
        cv::Mat preprocessed = preprocess(image);

        // Convert to CHW format (TensorRT expects channels first)
        std::vector<float> input(3 * input_width_ * input_height_);
        std::vector<cv::Mat> channels(3);
        cv::split(preprocessed, channels);

        for(int c = 0; c < 3; ++c){
            std::memcpy(
                input.data() + c * input_width_ * input_height_,
                channels[c].data,
                input_width_ * input_height_ * sizeof(float)
            );
        }

        // Run Inference
        std::vector<float> output;
        if(!engine_->infer(input, output)){
            std::cerr << "Inference Failed" << std::endl;
            return {};
        }

        // Post-process
        return postprocess(output, image.size());
    }

    std::vector<Detection> YOLODetector::postprocess(
        const std::vector<float> & output,
        const cv::Size & original_size)
    {
    // YOLOv8 TensorRT output: [8400, 84] 
    // Each row: [cx, cy, w, h, class0_score, class1_score, ..., class79_score]
    const int num_classes = 80;
    const int num_predictions = 8400;
    const int output_stride = 84;  // 4 bbox + 80 classes

    std::vector<Detection> detections;
    std::vector<cv::Rect> boxes;
    std::vector<float> confidences;
    std::vector<int> class_ids;

    float x_scale = static_cast<float>(original_size.width) / input_width_;
    float y_scale = static_cast<float>(original_size.height) / input_height_;

    for (int i = 0; i < num_predictions; ++i) {
        int base = i * output_stride;
        
        // Extract bbox (center format)
        float cx = output[base + 0];
        float cy = output[base + 1];
        float w = output[base + 2];
        float h = output[base + 3];

        // Find max class score
        float max_score = 0.0f;
        int max_class_id = 0;
        for (int c = 0; c < num_classes; ++c) {
        float score = output[base + 4 + c];
        if (score > max_score) {
            max_score = score;
            max_class_id = c;
        }
        }

        if (max_score > conf_thresh_) {
        // Convert center format to corner format and scale to original size
        float x1 = (cx - w / 2.0f) * x_scale;
        float y1 = (cy - h / 2.0f) * y_scale;
        float x2 = (cx + w / 2.0f) * x_scale;
        float y2 = (cy + h / 2.0f) * y_scale;

        // Clamp to image bounds
        x1 = std::max(0.0f, std::min(x1, static_cast<float>(original_size.width)));
        y1 = std::max(0.0f, std::min(y1, static_cast<float>(original_size.height)));
        x2 = std::max(0.0f, std::min(x2, static_cast<float>(original_size.width)));
        y2 = std::max(0.0f, std::min(y2, static_cast<float>(original_size.height)));

        int width = static_cast<int>(x2 - x1);
        int height = static_cast<int>(y2 - y1);

        // Skip degenerate boxes
        if (width > 0 && height > 0) {
            boxes.push_back(cv::Rect(static_cast<int>(x1), static_cast<int>(y1), width, height));
            confidences.push_back(max_score);
            class_ids.push_back(max_class_id);
        }
        }
    }

    // Apply NMS
    std::vector<int> indices;
    cv::dnn::NMSBoxes(boxes, confidences, conf_thresh_, nms_thresh_, indices);

    for (int idx : indices) {
        Detection det;
        det.box = boxes[idx];
        det.conf = confidences[idx];
        det.class_id = class_ids[idx];
        detections.push_back(det);
    }

    return detections;
    }

} // namespace perception