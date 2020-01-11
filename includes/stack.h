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
    - Stack implementation using array.
    - Stack implementation using linked list. (Which I used)
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

// This define will expands as
// struct node_T{T value; struct node_T *next}, where T is a type
// The operator "##" using as concatenation operator.
// You can read more about this here:
// https://docs.microsoft.com/en-us/cpp/preprocessor/token-pasting-operator-hash-hash?view=vs-2019
#define node(T)            \
  struct node_##T {        \
    T value;               \
    struct node_##T *next; \
  }

// This "define" will expands as
// struct stack_T{size_t size; node(T) * begin, *end;}, where T is a type
#define stack(T)           \
  struct stack_##T {       \
    size_t size;           \
    node(T) * begin, *end; \
  }

// The destructor freeing memory which were allocated for the stack.
// Check for the both the stack and the first element availability. If at least
// one element exists then freeing node by node. As soon as each element is
// freed, the entire stack is freed.
#define stack_destructor(st)                                               \
  {                                                                        \
    if (st) {                                                              \
      if (st->begin) {                                                     \
        do {                                                               \
          void *temp = st->begin;                                          \
          st->begin = st->begin->next;                                     \
          free(temp);                                                      \
        } while (st->begin != NULL);                                       \
      }                                                                    \
      free(st);                                                            \
    } else {                                                               \
      write_error_log(STACK_INACCESSIBILITY("stack_destructor(stack)"),    \
                      __LINE__, __FILE__, "-> includes/stack.h:59");       \
      printf(                                                              \
          "Error has occured! Check error_log.txt for the more details.\n" \
          "Press any key");                                                \
      return (getchar());                                                  \
    }                                                                      \
  }

// Splitting into two implementations due to the variety of compilers. However,
// the basic logic is the same.
#if defined(_MSC_VER)
// The constructor is allocating the memory for the stack and zeroing each
// field. Otherwise it writes an error into error_logs.txt
#define stack_constructor(T, st)                                             \
  do {                                                                       \
    if (st == NULL) {                                                        \
      if (!(st = malloc(sizeof(stack(T))))) {                                \
        write_error_log(MALLOC_ERROR_MESSAGE, __LINE__, __FILE__,            \
                        "-> includes/stack.h:86");                           \
        printf(                                                              \
            "Error has occured! Check error_log.txt for the more details.\n" \
            "Press any key");                                                \
        return (getchar());                                                  \
      }                                                                      \
      st->begin = NULL;                                                      \
      st->end = NULL;                                                        \
      st->size = 0;                                                          \
    } else {                                                                 \
      write_error_log(STACK_EXISTANCE, __LINE__, __FILE__,                   \
                      "-> includes/stack.h:85");                             \
      printf(                                                                \
          "Error has occured! Check error_log.txt for the more details.\n"   \
          "Press any key");                                                  \
      stack_destructor(st);                                                  \
      return (getchar());                                                    \
    }                                                                        \
  } while (0)

// Due to there is no way to use such notation stack(void *). Its demands the
// typedef. The pop function will be described in stack.c
typedef void *any_type;
void *stack_pop_function(stack(any_type) * st);
#define stack_pop(st) stack_pop_function(st)
// GNUC-compiler implementation begins
#elif defined(__GNUC__)
#define stack_constructor(T)                                               \
  ({                                                                       \
    struct stack_##T *st;                                                  \
    if (!(st = malloc(sizeof(stack(T))))) {                                \
      write_error_log(MALLOC_ERROR_MESSAGE, __LINE__, __FILE__,            \
                      "-> includes/stack.h:118");                          \
      printf(                                                              \
          "Error has occured! Check error_log.txt for the more details.\n" \
          "Press any key");                                                \
      return (getchar());                                                  \
    }                                                                      \
    st->begin = NULL;                                                      \
    st->end = NULL;                                                        \
    st->size = 0;                                                          \
    st;                                                                    \
  })

#define stack_pop(st)                                                        \
  ({                                                                         \
    typeof(st->end->value) result;                                           \
    if (st) {                                                                \
      if (st->begin == NULL) {                                               \
        write_error_log(ELEMENT_INACCESSIBILITY("stack_pop(st)"), __LINE__,  \
                        __FILE__, "-> includes/stack.h:136");                \
        printf(                                                              \
            "Error has occured! Check error_log.txt for the more details.\n" \
            "Press any key");                                                \
        stack_destructor(st);                                                \
        return (getchar());                                                  \
      }                                                                      \
      result = st->end->value;                                               \
      if (st->begin == st->end) {                                            \
        free(st->end);                                                       \
        st->begin = st->end = NULL;                                          \
        st->size--;                                                          \
      } else {                                                               \
        void *temp1 = st->begin;                                             \
        while (st->begin->next != st->end) st->begin = st->begin->next;      \
        st->end = st->begin;                                                 \
        st->begin = temp1;                                                   \
        free(st->end->next);                                                 \
        st->end->next = NULL;                                                \
        st->size--;                                                          \
      }                                                                      \
    } else {                                                                 \
      write_error_log(STACK_INACCESSIBILITY("stack_pop(st)"), __LINE__,      \
                      __FILE__, "-> includes/stack.h:135");                  \
      printf(                                                                \
          "Error has occured! Check error_log.txt for the more details.\n"   \
          "Press any key");                                                  \
      return (getchar());                                                    \
    }                                                                        \
    result;                                                                  \
  })

#endif  // end compiler-split implimentation

// Due to in the stack_push a type doesn't available we shall use another method
// of memory allocating. This method is fully described here:
// https://en.wikipedia.org/wiki/Flexible_array_member
// First, check for the stack availability. In the case if the stack exists then
// push element from the top. If the first element is missing then push into the
// first, otherwise push into the last.
#define stack_push(st, val)                                                   \
  {                                                                           \
    if (st) {                                                                 \
      if (st->begin == NULL) {                                                \
        st->begin = malloc(sizeof(*(st->begin)) + sizeof(st->begin->value));  \
        st->begin->value = val;                                               \
        st->begin->next = NULL;                                               \
        st->end = st->begin;                                                  \
        st->size++;                                                           \
      } else {                                                                \
        st->end->next = malloc(sizeof(*(st->end)) + sizeof(st->end->value));  \
        st->end = st->end->next;                                              \
        st->end->value = val;                                                 \
        st->end->next = NULL;                                                 \
        st->size++;                                                           \
      }                                                                       \
    } else {                                                                  \
      write_error_log(STACK_INACCESSIBILITY("stack_push(st, val)"), __LINE__, \
                      __FILE__, "-> includes/stack.h:180");                   \
      printf(                                                                 \
          "Error has occured! Check error_log.txt for the more details.\n"    \
          "Press any key");                                                   \
      return (getchar());                                                     \
    }                                                                         \
  }

#define stack_empty(st) st->size == 0 ? 1 : 0

// Stack clear is the method which removes each node but it doesn't removes
// whole stack. Check for stack and first element availability. If both true
// then remove node by node.
#define stack_clear(st)                                                    \
  do {                                                                     \
    if (st == NULL) {                                                      \
      write_error_log(STACK_INACCESSIBILITY("stack_clear(st)"), __LINE__,  \
                      __FILE__, "-> includes/stack.h:211");                \
      printf(                                                              \
          "Error has occured! Check error_log.txt for the more details.\n" \
          "Press any key");                                                \
      return (getchar());                                                  \
    }                                                                      \
    if (st->begin != NULL) {                                               \
      while (st->begin != NULL) {                                          \
        void *temp = st->begin;                                            \
        st->begin = st->begin->next;                                       \
        free(temp);                                                        \
      }                                                                    \
      st->size = 0;                                                        \
      st->end = NULL;                                                      \
    } else {                                                               \
      write_error_log(STACK_EMPTINESS, __LINE__, __FILE__,                 \
                      "includes/stack.h:219");                             \
      printf(                                                              \
          "Error has occured! Check error_log.txt for the more details.\n" \
          "Press any key");                                                \
      stack_destructor(st);                                                \
      return (getchar());                                                  \
    }                                                                      \
  } while (0)
#endif  // end of stack.h
