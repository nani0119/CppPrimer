cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S1-5)

# 添加链接库
# set(EXTRA_LIBS ${EXTRA_LIBS} "pthread")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 获取全局属性
get_property(Sales_item_FILE  GLOBAL PROPERTY "Sales_item_FILE") 

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(E120_show_sales_items_FILE "E120_show_sales_items.cc")
set(E120_show_sales_items_FILE ${E120_show_sales_items_FILE} ${Sales_item_FILE})

# 生成可执行文件
add_executable(E120_show_sales_items ${E120_show_sales_items_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(E120_show_sales_items ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS E120_show_sales_items DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
