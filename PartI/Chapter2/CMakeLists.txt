cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter1)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s2-1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s2-4)

# 添加子目录
add_subdirectory(s2-1)
add_subdirectory(s2-4)


