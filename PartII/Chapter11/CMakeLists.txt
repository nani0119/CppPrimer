cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter10)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s11-1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s11-2)

# 添加子目录
add_subdirectory(s11-1)
add_subdirectory(s11-2)


