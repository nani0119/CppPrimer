cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME PartI)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter13)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter15)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter16)

# 添加子目录
add_subdirectory(Chapter13)
add_subdirectory(Chapter15)
add_subdirectory(Chapter16)

