cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME function_template)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/function_template)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/class_template)

# 添加子目录
add_subdirectory(function_template)
add_subdirectory(class_template)


