cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S2)

# 添加链接库
set(EXTRA_LIBS ${EXTRA_LIBS} "pthread")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_2_Thread_1_mutex_FILE "Thread_1_mutex.cc")

# 生成可执行文件
add_executable(s20_2_Thread_1_mutex ${s20_2_Thread_1_mutex_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_2_Thread_1_mutex ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_2_Thread_1_mutex DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_2_Thread_3_lock_FILE "Thread_3_lock.cc")

# 生成可执行文件
add_executable(s20_2_Thread_3_lock ${s20_2_Thread_3_lock_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_2_Thread_3_lock ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_2_Thread_3_lock DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_2_Thread_2_thread_safe_stack_FILE "Thread_2_thread_safe_stack.cc")

# 生成可执行文件
add_executable(s20_2_Thread_2_thread_safe_stack ${s20_2_Thread_2_thread_safe_stack_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_2_Thread_2_thread_safe_stack ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_2_Thread_2_thread_safe_stack DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

