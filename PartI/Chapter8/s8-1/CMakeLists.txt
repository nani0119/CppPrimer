cmake_minimum_required(VERSION 3.2)

set(MODULE_NAME S8-1)

# 添加动态或者静态链接库路径
# link_directories(${PROJECT_BINARY_DIR}/PartI/Chapter1/common)

# 添加链接库
# set(EXTRA_LIBS ${EXTRA_LIBS} "libSales_item.a")
# set(EXTRA_LIBS ${EXTRA_LIBS} "libSales_item.so")

# 添加头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 获取全局属性
# get_property(Sales_item_FILE  GLOBAL PROPERTY "Sales_item_FILE") 

# ======================================================
# 自动包含当前目录代码文件
# aux_source_directory(. DIR_SRCS)
set(s8_1_2_io_condition_state_FILE "s8_1_2_io_condition_state.cc")

# 生成可执行文件
add_executable(s8_1_2_io_condition_state ${s8_1_2_io_condition_state_FILE})

# 链接库文件
target_link_libraries(s8_1_2_io_condition_state ${EXTRA_LIBS})

# 指定安装的文件信息
install(TARGETS s8_1_2_io_condition_state  DESTINATION bin)
# install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/Demo.h" DESTINATION include)

set(TEST_FILE "s8_1_2_in_file")
add_custom_command(TARGET s8_1_2_io_condition_state
  					POST_BUILD 
  					COMMAND echo "executing a copy command"
					COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_FILE} ${PROJECT_BINARY_DIR}/install/bin/${TEST_FILE}
  					COMMENT "This command will be executed after building target s8_1_2_io_condition_state"
 					)
