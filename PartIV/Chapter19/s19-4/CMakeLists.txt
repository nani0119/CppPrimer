cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S19-4)

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
set(s19_4_pointer_to_class_member_FILE "pointer_to_class_member.cc")

# 生成可执行文件
add_executable(s19_4_pointer_to_class_member ${s19_4_pointer_to_class_member_FILE})

# 链接库文件
target_link_libraries(s19_4_pointer_to_class_member ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s19_4_pointer_to_class_member DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s19_4_member_func_as_call_obj_FILE "member_func_as_call_obj.cc")

# 生成可执行文件
add_executable(s19_4_member_func_as_call_obj ${s19_4_member_func_as_call_obj_FILE})

# 链接库文件
target_link_libraries(s19_4_member_func_as_call_obj ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s19_4_member_func_as_call_obj DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
