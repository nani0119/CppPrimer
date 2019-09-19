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
set(s12_1_smart_pointer_FILE "s12_1_smart_pointer.cc")

# 生成可执行文件
add_executable(s12_1_smart_pointer ${s12_1_smart_pointer_FILE})

# 链接库文件
target_link_libraries(s12_1_smart_pointer ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s12_1_smart_pointer  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s12_1_sp_error_prone_FILE "s12_1_sp_error_prone.cc")

# 生成可执行文件
add_executable(s12_1_sp_error_prone ${s12_1_sp_error_prone_FILE})

# 链接库文件
target_link_libraries(s12_1_sp_error_prone ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s12_1_sp_error_prone  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s12_1_5_unique_ptr_FILE "s12_1_5_unique_ptr.cc")

# 生成可执行文件
add_executable(s12_1_5_unique_ptr ${s12_1_5_unique_ptr_FILE})

# 链接库文件
target_link_libraries(s12_1_5_unique_ptr ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s12_1_5_unique_ptr  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s12_allocator_FILE "s12_allocator.cc")

# 生成可执行文件
add_executable(s12_allocator ${s12_allocator_FILE})

# 链接库文件
target_link_libraries(s12_allocator ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s12_allocator  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StrBlob)

# 添加子目录
add_subdirectory(StrBlob)

