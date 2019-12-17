cmake_minimum_required(VERSION 3.15)

project(Data_Structures_Implimitation)

message(STATUS "We are on a ${CMAKE_SYSTEM_NAME} system")

set(${PROJECT_NAME}_MAJOR_VERSION 0)
set(${PROJECT_NAME}_MINOR_VERSION 1)
set(${PROJECT_NAME}_VERSION "${${PROJECT_NAME}_MAJOR_VERSION}.${${PROJECT_NAME}_MINOR_VERSION}")

message("${PROJECT_NAME} version: ${${PROJECT_NAME}_VERSION}")

# variables for the library
set(${PROJECT_NAME}_stack_source "sources/stack.c")
set(${PROJECT_NAME}_queue_source "sources/queue.c")
set(${PROJECT_NAME}_includes "includes/queue.h" "includes/stack.h")

set(${PROJECT_NAME}_main "main.c")

add_library(Data_Structures STATIC  ${${PROJECT_NAME}_stack_source} ${${PROJECT_NAME}_queue_source} ${${PROJECT_NAME}_includes})
target_include_directories(Data_Structures PUBLIC "${PROJECT_SOURCE_DIR}/includes")

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_main})
target_link_libraries(${PROJECT_NAME} PRIVATE Data_Structures)
