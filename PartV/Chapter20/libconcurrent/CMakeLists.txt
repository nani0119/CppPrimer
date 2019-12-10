cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME CONCURRENT)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)



# 设置全局属性
# set_property(GLOBAL PROPERTY Sales_item_FILE "${CMAKE_CURRENT_SOURCE_DIR}/Sales_item.cc")

set(EXTRA_LIBS "pthread")

set(LIBSALES_CONCURRENT_SRC "concurrent.cc")

# 生产动态库
add_library(concurrent SHARED ${LIBSALES_CONCURRENT_SRC})
target_link_libraries(concurrent ${EXTRA_LIBS})

# 设置动态版本，VERSION指代动态库版本，SOVERSION指代API版本
set_target_properties(concurrent PROPERTIES VERSION 1.0 SOVERSION 1)

# 生成静态库
add_library(concurrent_static STATIC ${LIBSALES_CONCURRENT_SRC})
target_link_libraries(concurrent_static ${EXTRA_LIBS})

# 设置静态库与动态库输出同名
set_target_properties (concurrent_static PROPERTIES OUTPUT_NAME "concurrent")

# 安装设置
install(FILES concurrent.h DESTINATION include/concurrent.h)
install(TARGETS concurrent concurrent_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(CONCURRENT_TEST_FILE "concurrent_test.cc")

# 生成可执行文件
add_executable(concurrent_test ${CONCURRENT_TEST_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(concurrent_test ${EXTRA_LIBS} concurrent)

# 添加库和头文件搜索路径
set(CMAKE_INCLUDE_PATH "../include")
set(CMAKE_LIBRARY_PATH "../lib")

# 指定安装的文件信息
install(TARGETS concurrent_test DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
