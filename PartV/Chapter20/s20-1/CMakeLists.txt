cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S1)

# 添加链接库
set(EXTRA_LIBS ${EXTRA_LIBS} "pthread")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_1_thread_hello_world_FILE "Thread_hello_world.cc")

# 生成可执行文件
add_executable(s20_1_thread_hello_world ${s20_1_thread_hello_world_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_1_thread_hello_world ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_1_thread_hello_world DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_1_thread_0_launching_FILE "Thread_0_launching.cc")

# 生成可执行文件
add_executable(s20_1_thread_0_launching ${s20_1_thread_0_launching_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_1_thread_0_launching ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_1_thread_0_launching DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_1_thread_1_join_err_FILE "Thread_1_join_err.cc")

# 生成可执行文件
add_executable(s20_1_thread_1_join_err ${s20_1_thread_1_join_err_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_1_thread_1_join_err ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_1_thread_1_join_err DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_1_thread_2_guard_FILE "Thread_2_guard.cc")

# 生成可执行文件
add_executable(s20_1_thread_2_guard ${s20_1_thread_2_guard_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_1_thread_2_guard ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_1_thread_2_guard DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_1_thread_3_background_FILE "Thread_3_background.cc")

# 生成可执行文件
add_executable(s20_1_thread_3_background ${s20_1_thread_3_background_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_1_thread_3_background ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_1_thread_3_background DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_1_thread_4_pass_args_FILE "Thread_4_pass_args.cc")

# 生成可执行文件
add_executable(s20_1_thread_4_pass_args ${s20_1_thread_4_pass_args_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_1_thread_4_pass_args ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_1_thread_4_pass_args DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_1_thread_5_scoped_thread_FILE "Thread_5_scoped_thread.cc")

# 生成可执行文件
add_executable(s20_1_thread_5_scoped_thread ${s20_1_thread_5_scoped_thread_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_1_thread_5_scoped_thread ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_1_thread_5_scoped_thread DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_1_thread_6_spawn_thread_FILE "Thread_6_spawn_thread")

# 生成可执行文件
add_executable(s20_1_thread_6_spawn_thread ${s20_1_thread_6_spawn_thread_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_1_thread_6_spawn_thread ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_1_thread_6_spawn_thread DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)
