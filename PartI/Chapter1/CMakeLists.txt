cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter1)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s1-2)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s1-4)

# 添加子目录
add_subdirectory(s1-2)
add_subdirectory(s1-4)

