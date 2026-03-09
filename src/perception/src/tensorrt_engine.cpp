#include "perception/tensorrt_engine.hpp"
#include <iostream>

namespace perception{

    void TensorRTEngine::Logger::log(Severity severity, const char* msg) noexcept {
        if(severity <= Severity::kWARNING) std::cout << "[TensorRT] " <<  msg << std::endl;
    }

    TensorRTEngine::TensorRTEngine()
    : runtime_(nullptr),
      engine_(nullptr),
      context_(nullptr),
      input_size_(0),
      output_size_(0){
        buffers_[0] = nullptr;
        buffers_[1] = nullptr;
        cudaStreamCreate(&stream_);
      }

    TensorRTEngine::~TensorRTEngine(){
        if(buffer_[0]) cudaFree(buffers_[0]);
        if(buffer_[1]) cudaFree(buffers_[1]);
        if(stream_) cudaStreamDestroy(stream_);
        if(context_) context_->destroy();
        if(engine_) engine_->destroy();
        if(runtime_) runtime_->destroy();
    }

    bool TensorRTEngine::load_engine(const std::string& engine_path){
        std::ifstream file(engine_path, std::ios::binary);
        if(!file.good()){
            std::cerr << "Failed to open engine file: " << engine_path << std::endl;
            return false;
        }

        file.seekg(0, std::ios::end);
        size_t size = file.tellg();
        file.seekg(0, std::ios::beg);

        std::vector<char> engine_data(size);
        file.read(engine_data.data(), size);
        file.close();

        runtime_ = nvinfer1::createInferRuntime(logger_);
        engine_ = runtime_->deserializeCudaEngine(engine_data.data(), size);
        context_ = engine_->createExecutionContext();

        if(!engine || !context_) {
            std::cerr << "Failed to create engine or context" << std::endl;
            return false;
        }

        // Get input/output dims
        auto input_dims = engine_->getBindingDimensions(0);
        auto output_dims = engine_->getBindingDimensions(1);

        input_size_ = 1;
        for(int i = 0; i < input_dims.nbDims; ++i)
            input_size_ *= input_dims.d[i];

        output_size_ = 1;
        for(int i = 0; i < output_dims.nbDims; ++i)
            output_size_ *= output_dims.d[i];

        // Allocate GPU Memory
        cudaMalloc(&buffers_[0], input_size_ * sizeof(float));
        cudaMalloc(&buffers_[1], output_size_ * sizeof(float));

        std::cout << "TensorRT engine loaded successfully" << std::endl;
        std::cout << " Input Size: " << input_size_ << std::endl;
        std::cout << " Output Size: " << output_size_ << std::endl;
        
        return true;
    }

    bool TensorRTEngine::infer(const std::vector<float>& input, std::vector<float>& output){
        if(input.size() != input_size_){
            std::cerr << "Input size mismatch" << std::endl;
            return false;
        }

        output.resize(output_size_);

        // Copy input to GPU
        cudaMemcpyAsync(buffers_[0], input.data(), input_size_ * sizeof(float),
                        cudaMemcpyHostToDevice, stream_);

        // Run inference
        context_->enqueueV2(buffers_, stream_, nullptr);

        // Copy output back to CPU
        cudaMemcpyAsync(output.data, buffers_[1], output_size_ * sizeof(float),
                        cudaMemcpyHostToDevice, stream_);

        cudaStreamSynchronize(stream_);

        return true;
    }

} // namespace perception
