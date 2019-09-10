cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S2-1)

# 添加链接库
# set(EXTRA_LIBS ${EXTRA_LIBS} "pthread")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(S2_1_2_Type_Conversion_FILE "S2_1_2_Type_Conversion.cc")

# 生成可执行文件
add_executable(S2_1_2_Type_Conversion ${S2_1_2_Type_Conversion_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(S2_1_2_Type_Conversion ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS S2_1_2_Type_Conversion DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

