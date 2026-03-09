#include "perception/yolo_detector.hpp"
#include <algorithm>

namespace perception{

    YOLODetector::YOLODetector():
    : input_width_(640),
      input_height_(480),
      conf_thres_(0.25),
      nms_thresh_(0.45)
    {}

    bool YOLODetector::initialize(const std::string& engine_path, float conf_thresh, float nms_thresh){
        conf_thres_ = conf_thresh;
        nms_thres_ = nms_thresh;

        engine_ = std::make_unique<TensorRTEngine()>;
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

        retrun rgb;
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
        const std::vector<float>& output,
        const cv::Size& original_size)
    {
        // YOLOv8 output format: [batch, 84, 8400]
        // 84 = 4 (bbox) + 80 (classes)
        // 8400 = number of predictions

        const int num_classes = 80;
        const int num_predictions = 8400;

        std::vector<Detection> detections;
        std::vector<cv::Rect> boxes;
        std::vector<float> confs;
        std::vector<int> class_ids;

        float x_scale = static_cast<float>(original_size.width) / input_width_;
        float y_scale = static_cast<float>(original_size.height) / input_height_;

        for(int i = 0; i < num_predictions; ++i){
            // Extract bboxes and class scores
            float cx = output[i];
            float cy = output[num_predictions + i];
            float w = output[2 * num_predictions + i];
            float h = output[3 * num_predictions + i];

            // Find max class score
            float max_score = 0.0f;
            int max_class_id = 0;
            for(int c = 0; c < num_classes; ++c){
                float score = output[(4 * c) * num_predictions + i];
                if(score > max_score){
                    max_score = score;
                    max_class_id = c;
                }
            }

            if(max_score > conf_thresh_){
                int x = static_cast<int>((cx - w / 2) * x_scale);
                int y = static_cast<int>((cy - h / 2) * y_scale);
                int width = static_cast<int>(w * x_scale);
                int height = static_cast<int>(h * y_scale);

                boxes.push_back(cv::Rect(x, y, width, height));
                confs.push_back(max_score);
                class_ids.push_back(max_class_id);
            }
        }

        std::vector<int> indices;
        cv::dnn::NMSBoxes(boxes, confs, conf_thresh_, nms_thresh_, indices);

        for(int idx: indices){
            Detection det;
            det.box = boxes[idx];
            det.confidence = confs[idx];
            det.class_id = class_ids[idx];
            detections.push_back(det);
        }

        return detections;
    }

} // namespace perception