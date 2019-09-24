cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S17-1)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sales_data)

# 添加子目录
add_subdirectory(sales_data)


