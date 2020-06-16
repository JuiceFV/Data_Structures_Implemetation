cmake_minimum_required(VERSION 3.10)

set(MAIN "all_tests.c")

add_executable(tests ${MAIN})
target_link_libraries(tests PUBLIC cmocka Data_Structures)