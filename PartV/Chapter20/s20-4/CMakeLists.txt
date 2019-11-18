cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S4)

# 添加链接库
set(EXTRA_LIBS ${EXTRA_LIBS} "pthread")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s20_4_Thread_1_spinlock_FILE "Thread_1_spinlock.cc")

# 生成可执行文件
add_executable(s20_4_Thread_1_spinlock  ${s20_4_Thread_1_spinlock_FILE})

# 添加可执行文件使用的链接库
target_link_libraries(s20_4_Thread_1_spinlock ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s20_4_Thread_1_spinlock DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

