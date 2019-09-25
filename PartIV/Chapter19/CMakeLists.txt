cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME Chapter18)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s19-2)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s19-3)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/s19-4)

# 添加子目录
add_subdirectory(s19-2)
add_subdirectory(s19-3)
add_subdirectory(s19-4)

