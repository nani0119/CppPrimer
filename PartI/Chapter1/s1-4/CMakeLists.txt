cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S1-2)

# 添加链接库
# set(EXTRA_LIBS ${EXTRA_LIBS} "pthread")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(E19_Calc_Sum_FILE "E19_Calc_Sum.cc")

# 生成可执行文件
add_executable(E19_Calc_Sum ${E19_Calc_Sum_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(E19_Calc_Sum ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS E19_Calc_Sum DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(E111_List_Num_Range_FILE "E111_List_Num_Range.cc")

# 生成可执行文件
add_executable(E111_List_Num_Range ${E111_List_Num_Range_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(E111_List_Num_Range ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS E111_List_Num_Range DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

