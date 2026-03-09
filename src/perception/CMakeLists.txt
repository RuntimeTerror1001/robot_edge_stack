cmake_minimum_required(VERSION 3.8)
project(perception)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(image_transport REQUIRED)
find_package(vision_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(CUDA REQUIRED)

# TensorRT (manually specify paths for Jetson)
set(TensorRT_INCLUDE_DIRS /usr/include/aarch64-linux-gnu)
set(TensorRT_LIBRARIES
  /usr/lib/aarch64-linux-gnu/libnvinfer.so
  /usr/lib/aarch64-linux-gnu/libnvonnxparser.so
)

include_directories(
  include
  ${CUDA_INCLUDE_DIRS}
  ${TensorRT_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

# TensorRT Engine Wrapper
add_library(tensorrt_engine
  src/tensorrt_engine.cpp
)
target_link_libraries(tensorrt_engine
  ${CUDA_LIBRARIES}
  ${TENSORRT_LIBRARIES}
)

# YOLO Detector
add_library(yolo_detector
  src/yolo_detector.cpp
)
target_link_libraries(yolo_detector
  tensorrt_engine
  ${OpenCV_LIBRARIES}
  ${CUDA_LIBRARIES}
)

add_executable(perception_node
  src/perception_node.cpp
)
ament_target_dependencies(perception_node
  rclcpp
  sensor_msgs
  cv_bridge
  image_transport
  vision_msgs
)
target_link_libraries(perception_node
  yolo_detector
  ${OpenCV_LIBRARIES}
)

install(TARGETS
  perception_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
