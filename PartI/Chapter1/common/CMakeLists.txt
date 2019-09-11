cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME CHAPTER1_COMMON)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)

# 设置全局属性
# set_property(GLOBAL PROPERTY Sales_item_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Sales_item.cc")

set(LIBSALES_ITEM_SRC "Sales_item.cc")

# 生产动态库
add_library(Sales_item SHARED ${LIBSALES_ITEM_SRC})

# 设置动态版本，VERSION指代动态库版本，SOVERSION指代API版本
set_target_properties(Sales_item PROPERTIES VERSION 1.0 SOVERSION 1)

# 生成静态库
add_library(Sales_item_static STATIC ${LIBSALES_ITEM_SRC})

# 设置静态库与动态库输出同名
set_target_properties (Sales_item_static PROPERTIES OUTPUT_NAME "Sales_item")

# 安装设置
install(FILES Sales_item.h DESTINATION include/Sales_item.h)
install(TARGETS Sales_item Sales_item_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
