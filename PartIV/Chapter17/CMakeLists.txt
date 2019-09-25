cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter16)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s17-1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s17-2)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s17-3)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s17-4)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s17-5)

# 添加子目录
add_subdirectory(s17-1)
add_subdirectory(s17-2)
add_subdirectory(s17-3)
add_subdirectory(s17-4)
add_subdirectory(s17-5)


