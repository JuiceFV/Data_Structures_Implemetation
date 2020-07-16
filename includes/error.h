/*
The file contains all data related with errors and exceptions.
*/
#ifndef _ERROR_H
#define _ERROR_H

#include "common.h"

// The global arrays retains lines where feasible an exception.
// First element is the definition of "anticipated_error" therefoe the rest are
// the lines of possible exceptions.
int queue_error_lines[11];
int stack_error_lines[8];

// This error will occur when malloc will return NULL.
#define MALLOC_ERROR_MESSAGE                                                  \
  "This error has occured because malloc returned wrong value. Its "          \
  "could be for several reasons:\n1)You have exhausted heap memory. This is " \
  "possible if size of the stack is very large\n2)You have corrupted the "    \
  "heap. That could happen if there are errors in the code that you are "     \
  "running."

// This  error will occur when stack doesn't exist. Especially when stack ==
// NULL.
#define STACK_INACCESSIBILITY(function)                         \
  "This error has occured because there is no stack (stack == " \
  "NULL).\nYou must use the constructor before using the " function "."

// This error occures when you trying to use constructor onto same stack twice
// or more.
#define STACK_EXISTANCE \
  "The stack already exists. You used constructor somewhere else."

// This error occures when you trying to clear a stack which already empty.
#define STACK_EMPTINESS                                                      \
  "The stack already empty. Either you didn't push anything into the stack " \
  "or you used stack_clear somewehre else."

#define STACK_INACCESSIBILITY(function)                               \
  "This error has occured because there is no stack (stack == " \
  "NULL).\nYou must use the constructor before using the " function "."

// This error occures when you trying to push element into the full stack
#define STACK_OVERFLOW "The stack has been overflowed"

// This error will occur when queue doesn't exists. Especially when queue ==
// NULL.
#define QUEUE_INACCESSIBILITY(function)                         \
  "This error has occured because there is no queue (queue == " \
  "NULL).\nYou must use the constructor before using the " function "."

// This error occures when you trying to use constructor onto same queue twice
// or more.
#define QUEUE_EXISTANCE \
  "The queue already exists. You used constructor somewhere else."

// This error occures when you trying to enqueue element into the full queue
#define QUEUE_OVERFLOW "The queue has been overflowed"

// This error occures when in the queue 0 elements
#define QUEUE_ELEMENT_INACCESSIBILITY(function)                          \
  "This error has occured because there is no element for the pop "      \
  "(queue->begin == NULL).\nYou must enqueue an element into the queue " \
  "before using " function "."

// This error occures when you trying to clear a queue which already empty.
#define QUEUE_EMPTINESS                                                      \
  "The queue already empty. Either you didn't push anything into the queue " \
  "or you used queue_clear somewehre else."

// This function just writes an error message into error_logs.txt file.
void write_error_log(const char* error_message, int line, const char* file,
                     const char* specific_dir);

// This function combine a directory path and number of error's line.
char* cat_dir_and_num(const char* dir, int line);
#endif
