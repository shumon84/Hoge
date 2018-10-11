cmake_minimum_required(VERSION 3.10)

project(
  Test
  VERSION 1.0
  )

set(
  CMAKE_EXPORT_COMPILE_COMMANDS ON
  )

add_subdirectory(extern)
add_subdirectory(test)
add_subdirectory(bundle)

enable_testing()

include_directories(${PROJECT_SOURCE_DIR})

add_executable(
  add
  main.cpp
  )

add_test(
  NAME add_test
  COMMAND AddFuncCheck
  )
