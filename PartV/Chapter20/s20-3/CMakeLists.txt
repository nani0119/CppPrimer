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

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_3_Thread_4_async_FILE "Thread_4_async.cc")

# 生成可执行文件
add_executable(s20_3_Thread_4_async ${s20_3_Thread_4_async_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_3_Thread_4_async ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_3_Thread_4_async  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_3_Thread_5_packed_task_FILE "Thread_5_packed_task.cc")

# 生成可执行文件
add_executable(s20_3_Thread_5_packed_task ${s20_3_Thread_5_packed_task_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_3_Thread_5_packed_task ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_3_Thread_5_packed_task DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_3_Thread_6_promise_FILE "Thread_6_promise.cc")

# 生成可执行文件
add_executable(s20_3_Thread_6_promise ${s20_3_Thread_6_promise_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_3_Thread_6_promise ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_3_Thread_6_promise DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_3_Thread_7_exception_FILE "Thread_7_exception.cc")

# 生成可执行文件
add_executable(s20_3_Thread_7_exception ${s20_3_Thread_7_exception_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_3_Thread_7_exception ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_3_Thread_7_exception DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_3_Thread_8_share_future_FILE "Thread_8_share_future.cc")

# 生成可执行文件
add_executable(s20_3_Thread_8_share_future ${s20_3_Thread_8_share_future_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_3_Thread_8_share_future ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_3_Thread_8_share_future DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_3_Thread_9_async_timeout_FILE "Thread_9_async_timeout.cc")

# 生成可执行文件
add_executable(s20_3_Thread_9_async_timeout ${s20_3_Thread_9_async_timeout_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_3_Thread_9_async_timeout ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_3_Thread_9_async_timeout DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_3_Thread_10_sync_timeout_FILE "Thread_10_sync_timeout.cc")

# 生成可执行文件
add_executable(s20_3_Thread_10_sync_timeout ${s20_3_Thread_10_sync_timeout_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_3_Thread_10_sync_timeout ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_3_Thread_10_sync_timeout DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_3_Thread_11_simplify_program_FILE "Thread_11_simplify_program.cc")

# 生成可执行文件
add_executable(s20_3_Thread_11_simplify_program ${s20_3_Thread_11_simplify_program_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_3_Thread_11_simplify_program ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_3_Thread_11_simplify_program DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

