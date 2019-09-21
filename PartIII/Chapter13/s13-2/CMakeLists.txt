cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S13-2)

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
set(s13_2_HasPtr_FILE "s13_2_HasPtr.cc")

# 生成可执行文件
add_executable(s13_2_HasPtr ${s13_2_HasPtr_FILE})

# 链接库文件
target_link_libraries(s13_2_HasPtr ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s13_2_HasPtr  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s13_2_HasPtrPointer_FILE "s13_2_HasPtrPointer.cc")

# 生成可执行文件
add_executable(s13_2_HasPtrPointer ${s13_2_HasPtrPointer_FILE})

# 链接库文件
target_link_libraries(s13_2_HasPtrPointer ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s13_2_HasPtrPointer  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
