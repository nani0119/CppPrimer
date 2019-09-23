cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME class_template)

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Blob)

# 添加子目录
add_subdirectory(Blob)


# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s16_1_class_template_static_FILE "s16_1_class_template_static.cc")

# 生成可执行文件
add_executable(s16_1_class_template_static ${s16_1_class_template_static_FILE})

# 链接库文件
target_link_libraries(s16_1_class_template_static ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s16_1_class_template_static DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)


# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s16_1_template_default_args_FILE "s16_1_template_default_args.cc")

# 生成可执行文件
add_executable(s16_1_template_default_args ${s16_1_template_default_args_FILE})

# 链接库文件
target_link_libraries(s16_1_template_default_args ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s16_1_template_default_args DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s16_1_class_member_template_FILE "s16_1_class_member_template.cc")

# 生成可执行文件
add_executable(s16_1_class_member_template ${s16_1_class_member_template_FILE})

# 链接库文件
target_link_libraries(s16_1_class_member_template ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s16_1_class_member_template DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

