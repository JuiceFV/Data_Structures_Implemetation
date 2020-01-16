#ifndef _COMMON_H
#define _COMMON_H

// Uncomment if you want to use memory-leaks-checker
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>

// This is the max of the unsigned long (int) value.
// If you would to change the type of the size, therefore you should change the
// MAX_SIZE
#define MAX_SIZE 4294967295

#define MALLOC_ERROR_MESSAGE                                                  \
  "This error has occured because malloc returned wrong value. Its "          \
  "could be for several reasons:\n1)You have exhausted heap memory. This is " \
  "possible if size of the stack is very large\n2)You have corrupted the "    \
  "heap. That could happen if there are errors in the code that you are "     \
  "running."

#define STACK_INACCESSIBILITY(function)                         \
  "This error has occured because there is no stack (stack == " \
  "NULL).\nYou must use the constructor before using the " function "."

#define STACK_EXISTANCE \
  "The stack already exists. You used constructor somewhere else."

#define STACK_EMPTINESS                                                      \
  "The stack already empty. Either you didn't push anything into the stack " \
  "or you used stack_clear somewehre else."

#define STACK_OVERFLOW "The stack has been overflowed"

#define QUEUE_INACCESSIBILITY(function)                         \
  "This error has occured because there is no queue (queue == " \
  "NULL).\nYou must use the constructor before using the " function "."

#define QUEUE_EXISTANCE \
  "The queue already exists. You used constructor somewhere else."

#define QUEUE_OVERFLOW "The queue has been overflowed"

#define QUEUE_ELEMENT_INACCESSIBILITY(function)                          \
  "This error has occured because there is no element for the pop "      \
  "(queue->begin == NULL).\nYou must enqueue an element into the queue " \
  "before using " function "."

#define QUEUE_EMPTINESS                                                      \
  "The queue already empty. Either you didn't push anything into the queue " \
  "or you used queue_clear somewehre else."

void write_error_log(const char* error_message, int line, const char* file,
                     const char* specific_dir);
#endif
