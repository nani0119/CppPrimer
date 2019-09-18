cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S10-2)

# 添加动态或者静态链接库路径
# link_directories(${PROJECT_BINARY_DIR}/PartI/Chapter1/common)

# 添加链接库
# set(EXTRA_LIBS ${EXTRA_LIBS} "libSales_item.a")
# set(EXTRA_LIBS ${EXTRA_LIBS} "libSales_item.so")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 获取全局属性
# get_property(Sales_item_FILE  GLOBAL PROPERTY "Sales_item_FILE") 

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s11_2_associative_container_FILE "s11_2_associative_container.cc")

# 生成可执行文件
add_executable(s11_2_associative_container ${s11_2_associative_container_FILE})

# 链接库文件
target_link_libraries(s11_2_associative_container ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s11_2_associative_container DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

