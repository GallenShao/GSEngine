set(CMAKE_CXX_FLAGS "-g -std=c++17 -Werror")

set(GSENGINE_ROOT ${CMAKE_CURRENT_LIST_DIR}/..)

include_directories(${GSENGINE_ROOT}/include)

aux_source_directory(. GS_ENGINE_SRCS)
aux_source_directory(backend/utils GS_ENGINE_SRCS)

add_library(GSEngine ${GS_ENGINE_SRCS})