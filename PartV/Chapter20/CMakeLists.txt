cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter20)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s20-1)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s20-2)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s20-3)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s20-4)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s20-6)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libconcurrent)

# 添加子目录
add_subdirectory(s20-1)
add_subdirectory(s20-2)
add_subdirectory(s20-3)
add_subdirectory(s20-4)
add_subdirectory(s20-6)
add_subdirectory(libconcurrent)


