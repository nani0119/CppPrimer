cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S16-4)

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
set(s16_4_var_template_FILE "var_template.cc")

# 生成可执行文件
add_executable(s16_4_var_template ${s16_4_var_template_FILE})

# 链接库文件
target_link_libraries(s16_4_var_template ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s16_4_var_template DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s16_4_var_template_print_FILE "print.cc")

# 生成可执行文件
add_executable(s16_4_var_template_print ${s16_4_var_template_print_FILE})

# 链接库文件
target_link_libraries(s16_4_var_template_print ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s16_4_var_template_print DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s16_4_var_template_err_msg_FILE "err_msg.cc")

# 生成可执行文件
add_executable(s16_4_var_template_err_msg ${s16_4_var_template_err_msg_FILE})

# 链接库文件
target_link_libraries(s16_4_var_template_err_msg ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s16_4_var_template_err_msg DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
