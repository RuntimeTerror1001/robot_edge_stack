#ifndef PERCEPTION__TENSORRT_ENGINE_HPP
#define PERCEPTION__TENSORRT_ENGINE_HPP

#include <NvInfer.h>
#include <cuda_runtime_api.h>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

namespace perception{
    class TensorRTEngine{
        public:
            TensorRTEngine();
            ~TensorRTEngine();

            bool load_engine(const std::string& engine_path);
            bool infer(const std::vector<float>& input, std::vector<float>& output);

            size_t get_input_size() const {return input_size_;}
            size_t get_output_size() const {return output_size_;}

        private:
            class Logger : public nvinfer1::ILogger{
                void log(Severity severity, const char* msg) noexcept override;
            };

            Logger logger_;
            nvinfer1::IRuntime* runtime_;
            nvinfer1::ICudaEngine* engine_;
            nvinfer1::IExecutionContect* context_;

            void* buffers_[2]; // input and output
            size_t input_size_;
            size_t output_size_;
            cudaStream_t stream_;
    };
} // namespace perception

#endif