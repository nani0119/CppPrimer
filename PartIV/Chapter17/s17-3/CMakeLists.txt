cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S17-3)

# 添加动态或者静态链接库路径
# link_directories(${PROJECT_BINARY_DIR}/PartI/Chapter1/common)

# 添加链接库
# set(EXTRA_LIBS ${EXTRA_LIBS} "libSales_item.a")
# set(EXTRA_LIBS ${EXTRA_LIBS} "libSales_item.so")


# 获取全局属性
# get_property(Sales_item_FILE  GLOBAL PROPERTY "Sales_item_FILE") 

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s17_3_regex_sample_FILE "regex_sample.cc")

# 生成可执行文件
add_executable(s17_3_regex_sample  ${s17_3_regex_sample_FILE})

# 链接库文件
target_link_libraries(s17_3_regex_sample ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s17_3_regex_sample DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s17_3_regex_smatch_operations_FILE "regex_smatch_operations.cc")

# 生成可执行文件
add_executable(s17_3_regex_smatch_operations  ${s17_3_regex_smatch_operations_FILE})

# 链接库文件
target_link_libraries(s17_3_regex_smatch_operations ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s17_3_regex_smatch_operations DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s17_3_regex_USPhoneNum_sub_match_FILE "USPhoneNum_sub_match.cc")

# 生成可执行文件
add_executable(s17_3_regex_USPhoneNum_sub_match  ${s17_3_regex_USPhoneNum_sub_match_FILE})

# 链接库文件
target_link_libraries(s17_3_regex_USPhoneNum_sub_match ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s17_3_regex_USPhoneNum_sub_match DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s17_3_regex_USPhoneNum_replace_FILE "USPhoneNumConvert_replace.cc")

# 生成可执行文件
add_executable(s17_3_regex_USPhoneNum_replace  ${s17_3_regex_USPhoneNum_replace_FILE})

# 链接库文件
target_link_libraries(s17_3_regex_USPhoneNum_replace ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s17_3_regex_USPhoneNum_replace DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
