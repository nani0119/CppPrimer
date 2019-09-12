cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter6)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s6-1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s6-2)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s6-3)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s6-5)

# 添加子目录
add_subdirectory(s6-1)
add_subdirectory(s6-2)
add_subdirectory(s6-3)
add_subdirectory(s6-5)


