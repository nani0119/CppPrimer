cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter1)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s1-2)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s1-4)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s1-5)

# 添加子目录
add_subdirectory(common)
add_subdirectory(s1-2)
add_subdirectory(s1-4)
add_subdirectory(s1-5)

