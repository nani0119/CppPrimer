cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME PartI)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter2)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter3)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter4)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter5)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter6)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter7)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Chapter8)

# 添加子目录
add_subdirectory(Chapter1)
add_subdirectory(Chapter2)
add_subdirectory(Chapter3)
add_subdirectory(Chapter4)
add_subdirectory(Chapter5)
add_subdirectory(Chapter6)
add_subdirectory(Chapter7)
add_subdirectory(Chapter8)

