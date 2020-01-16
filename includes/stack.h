/*
    <STACK DATA STRUCTURE>
    The stack data structure is pretty simple but pretty useful
    data structure.
    What is Stack?
    - It is type of linear data structure.
    - It follows LIFO (Last In First Out) property.
    - Insertion and Deletion in stack can only be done from top only.
    - Insertion in stack is also known as a PUSH operation.
    - Deletion from stack is also known as POP operation in stack.
    Stack Implementation
    - Stack implementation using array. (I used)
    - Stack implementation using linked list.
    Stack usage example
    -When function (sub-program) is called
     When a function is called, the function is called last will be completed
     first. It is the property of stack. There is a memory area, specially
     reserved for this stack.

    More information you can find here:
    https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
*/
#ifndef _STACK
#define _STACK

// Including the header which will be used as common file for the
// all data-structures-implementation.
// Now it contains:
// - Error messages
// - function which writes error logs
// - library for the memory leaks detection (#include <crtdbg.h>)
#include "common.h"

// This define will expand as
// struct stack_T{unsigned long size; T values[];}, where T is a type
// The operator "##" using as concatenation operator.
// You can read more about this here:
// https://docs.microsoft.com/en-us/cpp/preprocessor/token-pasting-operator-hash-hash?view=vs-2019
#define stack(T)        \
  struct node_##T {     \
    unsigned long size; \
    T values[];         \
  }

// Freeing whole stack including "size"
#define stack_destructor(st) free(st)

// Splitting into two implementations due to the variety of compilers. However,
// the basic logic is the same.
#if defined(_MSC_VER)
// The constructor is allocating memory for the stack and zeroing "size" -
// field. Otherwise it writes the error into error_logs.txt
#define stack_constructor(T, st)                                             \
  {                                                                          \
    if (st == NULL) {                                                        \
      if (!(st = malloc(sizeof(stack(T))))) {                                \
        write_error_log(MALLOC_ERROR_MESSAGE, __LINE__, __FILE__,            \
                        "-> includes/stack.h:56");                           \
        printf(                                                              \
            "Error has occured! Check error_log.txt for the more details.\n" \
            "Press any key");                                                \
        return (getchar());                                                  \
      }                                                                      \
      st->size = 0;                                                          \
    } else {                                                                 \
      write_error_log(STACK_EXISTANCE, __LINE__, __FILE__,                   \
                      "includes/stack.h:55");                                \
      printf(                                                                \
          "Error has occured! Check error_log.txt for the more details.\n"   \
          "Press any key");                                                  \
      return (getchar());                                                    \
    }                                                                        \
  }

// GNUC-compiler implementation begins
#elif defined(__GNUC__)
#define stack_constructor(T)                                               \
  ({                                                                       \
    struct stack_##T *st;                                                  \
    if (!(st = malloc(sizeof(stack(T))))) {                                \
      write_error_log(MALLOC_ERROR_MESSAGE, __LINE__, __FILE__,            \
                      "-> includes/stack.h:80");                           \
      printf(                                                              \
          "Error has occured! Check error_log.txt for the more details.\n" \
          "Press any key");                                                \
      return (getchar());                                                  \
    }                                                                      \
    st->size = 0;                                                          \
    st;                                                                    \
  })
#endif  // end compiler-split implimentation

// Due to in the stack_push a type doesn't available we shall use another method
// of memory allocating. This method is fully described here:
// https://en.wikipedia.org/wiki/Flexible_array_member
#define stack_push(st, val)                                                    \
  {                                                                            \
    if (st) {                                                                  \
      if (st->size < MAX_SIZE) {                                               \
        st = realloc(st,                                                       \
                     sizeof(st->size) + (st->size + 1) * sizeof(*st->values)); \
        st->values[st->size++] = (val);                                        \
      } else {                                                                 \
        write_error_log(STACK_OVERFLOW, __LINE__, __FILE__,                    \
                        "-> includes/stack.h:99");                             \
        printf(                                                                \
            "Error has occured! Check error_log.txt for the more details.\n"   \
            "Press any key");                                                  \
        return (getchar());                                                    \
      }                                                                        \
    } else {                                                                   \
      write_error_log(STACK_INACCESSIBILITY("stack_push(st, val)"), __LINE__,  \
                      __FILE__, "-> includes/stack.h:98");                     \
      printf(                                                                  \
          "Error has occured! Check error_log.txt for the more details.\n"     \
          "Press any key");                                                    \
      return (getchar());                                                      \
    }                                                                          \
  }

// Stack-pop operation removes and returns the last element. I the
// array-implementation it reduces the stack-size.
#define stack_pop(st) st->values[--st->size]

// Check for the stack emptiness
#define stack_empty(st) st->size == 0 ? 1 : 0

// Stack clear is the method which clears values but it doesn't clears
// whole stack. Check for stack and first element availability. If both true
// then remove node by node.
#define stack_clear(st)                                                    \
  do {                                                                     \
    if (st) {                                                              \
      st = realloc(st, sizeof(st->size));                                  \
      st->size = 0;                                                        \
    } else {                                                               \
      write_error_log(STACK_INACCESSIBILITY("stack_clear(st)"), __LINE__,  \
                      __FILE__, "-> includes/stack.h:130");                \
      printf(                                                              \
          "Error has occured! Check error_log.txt for the more details.\n" \
          "Press any key");                                                \
      return (getchar());                                                  \
    }                                                                      \
  } while (0)

// Stack-peek returns the last value of the stack but it doesn't reduces the
// size (in other words it doesn't remove the last element)
#define stack_peek(st) st->values[st->size - 1]

#endif  // end of stack.h