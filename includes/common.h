#ifndef _COMMON_H
#define _COMMON_H

#include <stdio.h>
#include <stdlib.h>

#define MALLOC_ERROR_MESSAGE                                                   \
  "Details:\nThis error has occured because malloc returned wrong value. Its " \
  "could be for several reasons:\n1)You have exhausted heap memory. This is "  \
  "possible if size of the stack is very large\n2)You have corrupted the "     \
  "heap. That could happen if there are errors in the code that you are "      \
  "running."

#define STACK_INACCESSIBILITY(function)                                   \
  "Details:\nThis error has occured because there is no stack (stack == " \
  "NULL).\nYou must use the constructor before using the " function "."

#define ELEMENT_INACCESSIBILITY(function)                                     \
  "Details:\nThis error has occured because there is no element for the pop " \
  "(stack->begin == NULL).\nYou must push an element into the stack before "  \
  "using " function "."

void write_error_log(const char* error_message, int line, const char* file,
                     const char* specific_dir);
#endif
