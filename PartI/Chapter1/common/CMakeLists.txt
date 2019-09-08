cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S1-5)

# 添加链接库
# set(EXTRA_LIBS ${EXTRA_LIBS} "pthread")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)

# 设置全局属性
set_property(GLOBAL PROPERTY Sales_item_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Sales_item.cc")
