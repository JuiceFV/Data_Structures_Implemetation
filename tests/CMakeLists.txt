cmake_minimum_required(VERSION 3.10)

message(STATUS "Adding tests:")

add_mocked_test(queue LINK_LIBRARIES "Data_Structures")
message(STATUS "Queue's tests has been added")
add_mocked_test(stack LINK_LIBRARIES "Data_Structures")
message(STATUS "Stack's tests has been added")
