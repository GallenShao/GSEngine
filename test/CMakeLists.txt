cmake_minimum_required(VERSION 3.14)
project(GSEngineTest)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(GSENGINE_ROOT ${CMAKE_CURRENT_LIST_DIR}/..)

#################### 设置头文件目录 ####################

# glfw和glew的头文件目录
include_directories(/usr/local/include)

include_directories(${GSENGINE_ROOT}/src/backend)

#################### 设置库文件目录 ####################

# glew的库目录路径
link_directories(/usr/local/Cellar/glew/2.2.0_1/lib)
# glfw的库目录路径
link_directories(/usr/local/Cellar/glfw/3.3.4/lib)

####################    设置子库    ####################

if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_LIST_DIR)
    add_subdirectory(${GSENGINE_ROOT}/src GSEngine)
endif()

####################    开启测试    ####################

enable_testing()

add_executable(
        GSEngine_test
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
        ${CMAKE_CURRENT_LIST_DIR}/backend/test_shader.cpp
)
target_link_libraries(
        GSEngine_test
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(GSEngine_test)

####################   设置库文件   ####################

# 指定glew库
target_link_libraries(GSEngine_test GLEW)
# 指定glfw库
target_link_libraries(GSEngine_test GLFW)
target_link_libraries(GSEngine_test GSEngine)