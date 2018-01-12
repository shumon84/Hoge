cmake_minimum_required(VERSION 3.10)

project(
  C-OOP
  VERSION 1.0
  )

add_executable(
  ${PROJECT_NAME}
  main.c
  )

add_library(
  Array MODULE
  Array.c
  )
