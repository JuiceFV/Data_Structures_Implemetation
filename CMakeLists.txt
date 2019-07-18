cmake_minimum_required(VERSION 3.0)

project(StackAndQueue)

set(MAIN_FILE "main.c")

file(GLOB SOURCE_FILES "functions/*c")
include_directories("${PROJECT_SOURCE_DIR}/headers")

add_executable(${PROJECT_NAME} ${MAIN_FILE} ${SOURCE_FILES} )

