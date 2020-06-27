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

#endif
