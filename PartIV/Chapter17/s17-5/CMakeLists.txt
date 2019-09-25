cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S17-1)

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
set(s17_5_formatedIO_FILE "formatedIO.cc")

# 生成可执行文件
add_executable(s17_5_formatedIO ${s17_5_formatedIO_FILE})

# 链接库文件
target_link_libraries(s17_5_formatedIO ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s17_5_formatedIO DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s17_5_unformatedIO_FILE "unformatedIO.cc")

# 生成可执行文件
add_executable(s17_5_unformatedIO ${s17_5_unformatedIO_FILE})

# 链接库文件
target_link_libraries(s17_5_unformatedIO ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s17_5_unformatedIO DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s17_5_unformatedIO_multi_bytes_FILE "unformatedIO_multi_bytes.cc")

# 生成可执行文件
add_executable(s17_5_unformatedIO_multi_bytes ${s17_5_unformatedIO_multi_bytes_FILE})

# 链接库文件
target_link_libraries(s17_5_unformatedIO_multi_bytes ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s17_5_unformatedIO_multi_bytes DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s17_5_stream_random_access_FILE "stream_random_access.cc")

# 生成可执行文件
add_executable(s17_5_stream_random_access ${s17_5_stream_random_access_FILE})

# 链接库文件
target_link_libraries(s17_5_stream_random_access ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s17_5_stream_random_access DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s17_5_stream_random_access_sample_FILE "stream_random_access_sample.cc")

# 生成可执行文件
add_executable(s17_5_stream_random_access_sample ${s17_5_stream_random_access_sample_FILE})

# 链接库文件
target_link_libraries(s17_5_stream_random_access_sample ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s17_5_stream_random_access_sample DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

