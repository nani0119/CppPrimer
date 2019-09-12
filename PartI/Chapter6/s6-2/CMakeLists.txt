cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S6-2)

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
set(s6_2_passing_arg_FILE "s6_2_passing_arg.cc")

# 生成可执行文件
add_executable(s6_2_passing_arg ${s6_2_passing_arg_FILE})

# 链接库文件
target_link_libraries(s6_2_passing_arg ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s6_2_passing_arg  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s6_2_5_handing_cmd_line_FILE "s6_2_5_handing_cmd_line.cc")

# 生成可执行文件
add_executable(s6_2_5_handing_cmd_line ${s6_2_5_handing_cmd_line_FILE})

# 链接库文件
target_link_libraries(s6_2_5_handing_cmd_line ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s6_2_5_handing_cmd_line  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s6_2_6_vary_paramter_FILE "s6_2_6_vary_paramter.cc")

# 生成可执行文件
add_executable(s6_2_6_vary_paramter ${s6_2_6_vary_paramter_FILE})

# 链接库文件
target_link_libraries(s6_2_6_vary_paramter ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s6_2_6_vary_paramter  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

