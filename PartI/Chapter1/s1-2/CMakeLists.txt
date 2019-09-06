cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S1-2)

# 添加链接库
# set(EXTRA_LIBS ${EXTRA_LIBS} "pthread")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(E13_Hello_World_FILE "E13_Hello_World.cc")

# 生成可执行文件
add_executable(E13_Hello_World ${E13_Hello_World_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(E13_Hello_World ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS E13_Hello_World DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(E14_Multi_Operatand_FILE "E14_Multi_Operatand.cc")

# 生成可执行文件
add_executable(E14_Multi_Operatand  ${E14_Multi_Operatand_FILE})

# 指定安装的文件信息
install(TARGETS E14_Multi_Operatand DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
