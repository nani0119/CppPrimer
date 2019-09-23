cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S16-2)

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
set(s16_2_template_argument_FILE "s16_2_template_argument.cc")

# 生成可执行文件
add_executable(s16_2_template_argument ${s16_2_template_argument_FILE})

# 链接库文件
target_link_libraries(s16_2_template_argument ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s16_2_template_argument  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s16_2_template_deduction_FILE "s16_2_template_deduction_pointer.cc")

# 生成可执行文件
add_executable(s16_2_template_deduction ${s16_2_template_deduction_FILE})

# 链接库文件
target_link_libraries(s16_2_template_deduction ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s16_2_template_deduction  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s16_2_template_deduction_reference_FILE "s16_2_template_deduction_reference.cc")

# 生成可执行文件
add_executable(s16_2_template_deduction_reference ${s16_2_template_deduction_reference_FILE})

# 链接库文件
target_link_libraries(s16_2_template_deduction_reference ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s16_2_template_deduction_reference  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s16_2_template_forward_FILE "s16_2_template_forward.cc")

# 生成可执行文件
add_executable(s16_2_template_forward ${s16_2_template_forward_FILE})

# 链接库文件
target_link_libraries(s16_2_template_forward ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s16_2_template_forward  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
