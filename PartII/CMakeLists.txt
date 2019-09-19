cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME PartI)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter9)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter10)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter11)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter12)

# 添加子目录
add_subdirectory(Chapter9)
add_subdirectory(Chapter10)
add_subdirectory(Chapter11)
add_subdirectory(Chapter12)

