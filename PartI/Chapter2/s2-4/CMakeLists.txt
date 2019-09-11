cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S2-1)

# 添加链接库
# set(EXTRA_LIBS ${EXTRA_LIBS} "pthread")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(S2_4_const_FILE "S2_4_const.cc" "S2_4_const_aux.cc")

# 生成可执行文件
add_executable(S2_4_const ${S2_4_const_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(S2_4_const ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS S2_4_const DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(E231_Const_level_FILE "E231_Const_level.cc")

# 生成可执行文件
add_executable(E231_Const_level ${E231_Const_level_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(E231_Const_level ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS E231_Const_level DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(S2_5_3_decltype_FILE "S2_5_3_decltype.cc")

# 生成可执行文件
add_executable(S2_5_3_decltype ${S2_5_3_decltype_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(S2_5_3_decltype ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS S2_5_3_decltype DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

