set(CMAKE_CXX_FLAGS "-g -std=c++17 -Werror")

set(GSENGINE_ROOT ${CMAKE_CURRENT_LIST_DIR}/..)

#################### 设置头文件目录 ####################

include_directories(${GSENGINE_ROOT}/include)
include_directories(${GSENGINE_ROOT}/src/backend)

#################### 设置源文件目录 ####################

aux_source_directory(. GS_ENGINE_SRCS)
aux_source_directory(backend GS_ENGINE_SRCS)
aux_source_directory(backend/utils GS_ENGINE_SRCS)
aux_source_directory(backend/buffer GS_ENGINE_SRCS)
aux_source_directory(backend/program GS_ENGINE_SRCS)
aux_source_directory(backend/parameter GS_ENGINE_SRCS)

####################  设置预编译宏  ####################

add_definitions(-DGL_SILENCE_DEPRECATION) # 忽略"OpenGL API deprecated"相关报错

####################  设置构建目标  ####################

add_library(GSEngine ${GS_ENGINE_SRCS})

####################   设置库文件   ####################

if (APPLE)
    target_link_libraries(GSEngine "-framework OpenGL")
endif()
