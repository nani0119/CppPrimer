cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter18)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s18-1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s18-2)

# 添加子目录
add_subdirectory(s18-1)
add_subdirectory(s18-2)

