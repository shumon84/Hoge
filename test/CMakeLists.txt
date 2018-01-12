cmake_minimum_required(VERSION 2.8)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(GTEST_ROOT ${googletest-distribution_SOURCE_DIR})
include_directories(${GTEST_ROOT}/include/)
include_directories(${Test_SOURCE_DIR})
link_directories(${GTEST_ROOT}/build/)
add_executable(AddFuncCheck ${CMAKE_CURRENT_SOURCE_DIR}/AddFuncCheck.cpp)
target_link_libraries(AddFuncCheck gtest gtest_main pthread)
