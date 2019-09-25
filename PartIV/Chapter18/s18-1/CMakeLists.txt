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
set(s18_1_exception_sample_FILE "exception_sample.cc")

# 生成可执行文件
add_executable(s18_1_exception_sample ${s18_1_exception_sample_FILE})

# 链接库文件
target_link_libraries(s18_1_exception_sample ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s18_1_exception_sample DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s18_1_exception_scliced_down_FILE "exception_scliced_down.cc")

# 生成可执行文件
add_executable(s18_1_exception_scliced_down ${s18_1_exception_scliced_down_FILE})

# 链接库文件
target_link_libraries(s18_1_exception_scliced_down ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s18_1_exception_scliced_down DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s18_1_exception_noexcept_FILE "noexcept.cc")

# 生成可执行文件
add_executable(s18_1_exception_noexcept ${s18_1_exception_noexcept_FILE})

# 链接库文件
target_link_libraries(s18_1_exception_noexcept ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s18_1_exception_noexcept DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s18_1_exception_construct_rethrow_FILE "exception_construct_rethrow.cc")

# 生成可执行文件
add_executable(s18_1_exception_construct_rethrow ${s18_1_exception_construct_rethrow_FILE})

# 链接库文件
target_link_libraries(s18_1_exception_construct_rethrow ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s18_1_exception_construct_rethrow DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

