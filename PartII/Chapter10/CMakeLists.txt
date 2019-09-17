cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter10)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s10-2)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s10-3)

# 添加子目录
add_subdirectory(s10-2)
add_subdirectory(s10-3)


