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
        if(buffers_[0]) cudaFree(buffers_[0]);
        if(buffers_[1]) cudaFree(buffers_[1]);
        if(stream_) cudaStreamDestroy(stream_);
        if(context_) delete context_;
        if(engine_) delete engine_;
        if(runtime_) delete runtime_;
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
        if (!runtime_) {
            std::cerr << "Failed to create TensorRT runtime" << std::endl;
            return false;
        }

        engine_ = runtime_->deserializeCudaEngine(engine_data.data(), size);
        if (!engine_) {
            std::cerr << "Failed to deserialize TensorRT engine" << std::endl;
            return false;
        }

        context_ = engine_->createExecutionContext();
        if (!context_) {
            std::cerr << "Failed to create TensorRT execution context" << std::endl;
            return false;
        }

        // Get input/output dims
        auto input_dims = engine_->getTensorShape(engine_->getIOTensorName(0));
        auto output_dims = engine_->getTensorShape(engine_->getIOTensorName(1));

        input_size_ = 1;
        for(int i = 0; i < input_dims.nbDims; ++i)
            input_size_ *= input_dims.d[i];

        output_size_ = 1;
        for(int i = 0; i < output_dims.nbDims; ++i)
            output_size_ *= output_dims.d[i];

        // Allocate GPU memory
        cudaError_t err = cudaMalloc(&buffers_[0], input_size_ * sizeof(float));
        if (err != cudaSuccess) {
            std::cerr << "Failed to allocate input buffer: " << cudaGetErrorString(err) << std::endl;
            return false;
        }

        err = cudaMalloc(&buffers_[1], output_size_ * sizeof(float));
        if (err != cudaSuccess) {
            std::cerr << "Failed to allocate output buffer: " << cudaGetErrorString(err) << std::endl;
            cudaFree(buffers_[0]);  // Clean up the first allocation
            buffers_[0] = nullptr;
            return false;
        }

        std::cout << "TensorRT engine loaded successfully" << std::endl;
        std::cout << " Input Size: " << input_size_ << std::endl;
        std::cout << " Output Size: " << output_size_ << std::endl;
        
        return true;
    }

    bool TensorRTEngine::infer(const std::vector<float> & input, std::vector<float> & output)
    {
        if (input.size() != input_size_) {
            std::cerr << "Input size mismatch: expected " << input_size_ 
                    << ", got " << input.size() << std::endl;
            return false;
        }

        output.resize(output_size_);

        // Copy input to GPU
        cudaError_t err = cudaMemcpyAsync(buffers_[0], input.data(), 
                                            input_size_ * sizeof(float),
                                            cudaMemcpyHostToDevice, stream_);
        if (err != cudaSuccess) {
            std::cerr << "CUDA memcpy H2D failed: " << cudaGetErrorString(err) << std::endl;
            return false;
        }

        // Run inference
        context_->setTensorAddress(engine_->getIOTensorName(0), buffers_[0]); 
        context_->setTensorAddress(engine_->getIOTensorName(1), buffers_[1]); 
        if (!context_->enqueueV3(stream_)) {
            std::cerr << "TensorRT enqueueV3 failed" << std::endl;
            return false;
        }

        // Copy output back to CPU
        err = cudaMemcpyAsync(output.data(), buffers_[1], 
                                output_size_ * sizeof(float),
                                cudaMemcpyDeviceToHost, stream_);
        if (err != cudaSuccess) {
            std::cerr << "CUDA memcpy D2H failed: " << cudaGetErrorString(err) << std::endl;
            return false;
        }

        // Synchronize and check for any errors
        err = cudaStreamSynchronize(stream_);
        if (err != cudaSuccess) {
            std::cerr << "CUDA stream sync failed: " << cudaGetErrorString(err) << std::endl;
            return false;
        }

        return true;
    }

} // namespace perception
