cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Message)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Message)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Screen)

# 添加子目录
add_subdirectory(Message)
add_subdirectory(Screen)


