cmake_minimum_required(VERSION 3.10)

project(
  C-OOP
  VERSION 1.0
  )

add_executable(
  ${PROJECT_NAME}
  main.c
  )
target_link_libraries(
  ${PROJECT_NAME}
  m
  )

add_library(
  Array MODULE
  Array.c
  )
target_link_libraries(
  Array
  m
  )
