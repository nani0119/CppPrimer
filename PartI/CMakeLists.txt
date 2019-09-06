cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME PartI)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter1)

# 添加子目录
add_subdirectory(Chapter1)

