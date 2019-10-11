cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S1)

# 添加链接库
set(EXTRA_LIBS ${EXTRA_LIBS} "pthread")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_3_Thread_1_contion_FILE "Thread_1_contion.cc")

# 生成可执行文件
add_executable(s20_3_Thread_1_contion ${s20_3_Thread_1_contion_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_3_Thread_1_contion ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_3_Thread_1_contion  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_3_Thread_2_condtion_notify_all_FILE "Thread_2_condtion_notify_all.cc")

# 生成可执行文件
add_executable(s20_3_Thread_2_condtion_notify_all ${s20_3_Thread_2_condtion_notify_all_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_3_Thread_2_condtion_notify_all ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_3_Thread_2_condtion_notify_all  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_3_Thread_3_thread_safe_queue_FILE "Thread_3_thread_safe_queue.cc")

# 生成可执行文件
add_executable(s20_3_Thread_3_thread_safe_queue ${s20_3_Thread_3_thread_safe_queue_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_3_Thread_3_thread_safe_queue ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_3_Thread_3_thread_safe_queue  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

