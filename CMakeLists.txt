# set the minimal version of the cmake
cmake_minimum_required(VERSION 3.10)

# set the name of the project
project(Data_Structures_Implimitation)

# Showing the system type
message(STATUS "We are on a ${CMAKE_SYSTEM_NAME} system")

# setting the version of the project
set(${PROJECT_NAME}_MAJOR_VERSION 0)
set(${PROJECT_NAME}_MINOR_VERSION 1)
set(${PROJECT_NAME}_VERSION "${${PROJECT_NAME}_MAJOR_VERSION}.${${PROJECT_NAME}_MINOR_VERSION}")

# Output the version of the project
message("${PROJECT_NAME} version: ${${PROJECT_NAME}_VERSION}")

# variables for the library
# stack source-files
set(${PROJECT_NAME}_stack_source "sources/stack.c")
set(${PROJECT_NAME}_includes "includes/stack.h" "includes/common.h")
set(${PROJECT_NAME}_commin_source "sources/common.c")

# main file
set(${PROJECT_NAME}_main "main.c")

# adding library toward the project
add_library(Data_Structures STATIC  ${${PROJECT_NAME}_stack_source} ${${PROJECT_NAME}_commin_source} ${${PROJECT_NAME}_includes})
target_include_directories(Data_Structures PUBLIC "${PROJECT_SOURCE_DIR}/includes")

# adding executable
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_main})
target_link_libraries(${PROJECT_NAME} PRIVATE Data_Structures)