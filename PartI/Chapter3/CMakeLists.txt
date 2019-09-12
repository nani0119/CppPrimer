cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter3)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s3-2)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s3-3)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s3-4)

# 添加子目录
add_subdirectory(s3-2)
add_subdirectory(s3-3)
add_subdirectory(s3-4)


