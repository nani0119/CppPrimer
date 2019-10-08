cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter20)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s20-1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s20-2)

# 添加子目录
add_subdirectory(s20-1)
add_subdirectory(s20-2)


