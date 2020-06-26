/*
The common.h file, according to its name contains common data for the entire library.
All external libraries are rostered over here.
*/
#ifndef _COMMON_H
#define _COMMON_H

// Uncomment if you want to use memory-leaks-checker
// TODO: Further it will be replaced to tests.
//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// In purpose to implement queue_dequeue_function in queue.h it's vital
// for us to use the void* however it is not possible to use it in such definition (the reason is ## in defines)
// therefor redefine the void* as one-word name.
typedef void* any_type;


// This is the max of the unsigned long (int) value.
// If you would to change the type of the size, therefore you should change the
// MAX_SIZE
#define MAX_SIZE 4294967295

// Something similar to return from function, however for macroses.
int return_val_from_macro;

// Yeeeeeep :)))) It seems a little bit weird.
// Let me explain, in the premain.h I used to use a relative paths to the queue.h and stack.h
// It works sufficiently good everywhere except sub-binary directory (/tests for example).
// The solution which I got is the define absolute path to includes in CMake.
//-----------------------------------------------------------------------------
// CMakeLists.txt root directory:
// add_compile_definitions(PATH_TO_INCLUDES = "${PROJECT_SOURCE_DIR}/includes")
//-----------------------------------------------------------------------------
// and after I merely concatenate the absolute path to the "includes"-directory to a specific file (queue.h/stack.h).
#define PATH_TO_QUEUE_H PATH_TO_INCLUDES ## "/queue.h"
#define PATH_TO_STACK_H PATH_TO_INCLUDES ## "/stack.h"
#endif
