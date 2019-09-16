cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter9)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s9-1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s9-3)

# 添加子目录
add_subdirectory(s9-1)
add_subdirectory(s9-3)


