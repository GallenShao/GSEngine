cmake_minimum_required(VERSION 3.0)
project(GSEngineMacOS)

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_CXX_FLAGS "-g")			# 调试信息
set(CMAKE_CXX_FLAGS "-std=c++11")	# 使用c++11
set(CMAKE_CXX_FLAGS "-Wformat")		# 开启所有警告

set(CMAKE_CXX_FLAGS_DEBUG   "-O0" )				# 调试包不优化
# set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG " )	# release包优化

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake-build-debug/output)

set(GSENGINE_ROOT ${CMAKE_CURRENT_LIST_DIR}/../..)

#################### 设置头文件目录 ####################

# glfw和glew的头文件目录
include_directories(/usr/local/include)

# GSEngine对外头文件目录
include_directories(${GSENGINE_ROOT}/include)

#################### 设置源文件目录 ####################

aux_source_directory(./ GS_ENGINE_MACOS_SRCS)

#################### 设置库文件目录 ####################

# glew的库目录路径
link_directories(/usr/local/Cellar/glew/2.2.0_1/lib)
# glfw的库目录路径
link_directories(/usr/local/Cellar/glfw/3.3.4/lib)

####################    设置子库    ####################

add_subdirectory(../../src GSEngine)

####################  设置构建目标  ####################

add_executable(GSEngineMacOS ${GS_ENGINE_MACOS_SRCS})

####################   设置库文件   ####################

# 指定glew库
target_link_libraries(GSEngineMacOS GLEW)
# 指定glfw库
target_link_libraries(GSEngineMacOS GLFW)

target_link_libraries(GSEngineMacOS GSEngine)