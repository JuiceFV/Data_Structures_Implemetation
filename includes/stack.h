/***************************************************************
    In this file I have implemented the stack data structure
    In this implemetation I used linked-list. Also I tried to
    make the "template", such as in C++.  Most of the methods
    were written in this file (stack.h) because I needed to use
    an undefined type. Which make essential the usage of the
    "#define" macro-definition.
***************************************************************/
#ifndef _STACK
#define _STACK

#include "common.h"

// The node structure. It's using as a type.
// For instance, "node(int) *nd;".
// This notation expands into this initialization
// struct node_int {int value; struct node_int *next;} *nd;
// I would to note that the token "##" is concatenation operator.
// You can find more information here:
// https://docs.microsoft.com/en-us/cpp/preprocessor/token-pasting-operator-hash-hash?view=vs-2019
#define node(T)            \
  struct node_##T {        \
    T value;               \
    struct node_##T *next; \
  }

#define stack(T)           \
  struct stack_##T {       \
    size_t size;           \
    node(T) * begin, *end; \
  }

// Here I have split the implemetation. It's depending on the compilers.
// For example the GNUC-compiler has some syntax-sugar, which MSVC hasn't.
#if defined(_MSC_VER)
// The constructor is pretty simple:
// 1) Check the availability  of the object.
// 2) Allocate memory for the object
// 3) Zeroing each field of the object
// Note: I am using "do{}while(0)" to avoid syntax errors. Also you can use only
// "{}".
#define stack_constructor(T, st)                                             \
  do {                                                                       \
    if (st == NULL) {                                                        \
      if (!(st = malloc(sizeof(stack(T))))) {                                \
        write_error_log(MALLOC_ERROR_MESSAGE, __LINE__, __FILE__,            \
                        "-> line: 43 file(stack.h)");                        \
        printf(                                                              \
            "Error has occured! Check error_log.txt for the more details.\n" \
            "Press any key");                                                \
        return (getchar());                                                  \
      }                                                                      \
      st->begin = NULL;                                                      \
      st->end = NULL;                                                        \
      st->size = 0;                                                          \
    }                                                                        \
    write_log(STACK_CONSTRUCTOR_ACCOMPLISHED, "stack_constructor(T, st)");   \
  } while (0)

// A little bit specific implemetation of the stack_pop.
// Cause of this is MSVC compiler. GNUC implemetation is a little bit different
// Here we shall to use the "typedef void* any_type" because when we will
// concatenate using "##" we will get an error.
// The explanation, how does it works is in the "stack.c"
typedef void *any_type;
void *stack_pop_function(stack(any_type) * st);
#define stack_pop(st) stack_pop_function(st)
#elif defined(__GNUC__)
#define stack_constructor(T)                                               \
  ({                                                                       \
    struct stack_##T *st;                                                  \
    if (!(st = malloc(sizeof(stack(T))))) {                                \
      write_error_log(MALLOC_ERROR_MESSAGE, __LINE__, __FILE__,            \
                      "-> line: 67 file(stack.h)");                        \
      printf(                                                              \
          "Error has occured! Check error_log.txt for the more details.\n" \
          "Press any key");                                                \
      return (getchar());                                                  \
    }                                                                      \
    st->begin = NULL;                                                      \
    st->end = NULL;                                                        \
    st->size = 0;                                                          \
    write_log(STACK_CONSTRUCTOR_ACCOMPLISHED, "stack_constructor(T, st)"); \
    st;                                                                    \
  })
#endif  // end compiler-split implimentation

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
      write_log(STACK_DESTRUCTOR_ACCOMPLISHED, "stack_destructor(stack)"); \
    } else {                                                               \
      write_error_log(STACK_INACCESSIBILITY("stack_destructor(stack)"),    \
                      __LINE__, __FILE__, "-> line: 97 file(stack.h)");    \
      printf(                                                              \
          "Error has occured! Check error_log.txt for the more details.\n" \
          "Press any key");                                                \
      return (getchar());                                                  \
    }                                                                      \
  }

#define stack_resize(st, _size)                                             \
  {                                                                         \
    if (st == NULL) {                                                       \
      write_error_log(STACK_INACCESSIBILITY("stack_resize(stack, size)"),   \
                      __LINE__, __FILE__, "-> line: 111 file(stack.h)");    \
      printf(                                                               \
          "Error has occured! Check error_log.txt for the more details.\n"  \
          "Press any key");                                                 \
      return (getchar());                                                   \
    }                                                                       \
    if (st->size > _size) {                                                 \
      printf(                                                               \
          "Wrong size. You trying to cut the size of the vector\nTo avoid " \
          "any errors this program will abort. Please press any key");      \
      stack_destructor(st);                                                 \
      return (getchar());                                                   \
    }                                                                       \
    int i = st->size;                                                       \
    if (st->begin == NULL) {                                                \
      st->begin = malloc(sizeof(*(st->begin)) + sizeof(st->begin->value));  \
      st->begin->value = (0);                                               \
      st->begin->next = NULL;                                               \
      st->end = st->begin;                                                  \
      i++;                                                                  \
    }                                                                       \
    while (i < _size) {                                                     \
      st->end->next = malloc(sizeof(*(st->end)) + sizeof(st->end->value));  \
      st->end = st->end->next;                                              \
      st->end->value = (0);                                                 \
      st->end->next = NULL;                                                 \
      i++;                                                                  \
    }                                                                       \
    st->size = _size;                                                       \
  }

#define stack_is_empty(st) st->size == 0 ? 1 : 0

#define stack_push(st, val)                                                  \
  {                                                                          \
    if (st) {                                                                \
      if (st->begin == NULL) {                                               \
        st->begin = malloc(sizeof(*(st->begin)) + sizeof(st->begin->value)); \
        st->begin->value = val;                                              \
        st->begin->next = NULL;                                              \
        st->end = st->begin;                                                 \
        st->size++;                                                          \
      } else {                                                               \
        st->end->next = malloc(sizeof(*(st->end)) + sizeof(st->end->value)); \
        st->end = st->end->next;                                             \
        st->end->value = val;                                                \
        st->end->next = NULL;                                                \
        st->size++;                                                          \
      }                                                                      \
    } else {                                                                 \
      printf(                                                                \
          "There is no stack. You must use the constructor before using "    \
          "the stack_push.\nTo avoid any errors this program will "          \
          "abort. "                                                          \
          "Please press any key");                                           \
      return (getchar());                                                    \
    }                                                                        \
  }

#define stack_clear(st)                                                   \
  do {                                                                    \
    if (st == NULL) {                                                     \
      printf(                                                             \
          "There is no stack. You must use the constructor before using " \
          "the stack_push.\nTo avoid any errors this program will "       \
          "abort. "                                                       \
          "Please press any key");                                        \
      return (getchar());                                                 \
    }                                                                     \
    if (st->begin != NULL) {                                              \
      while (st->begin != NULL) {                                         \
        void *temp = st->begin;                                           \
        st->begin = st->begin->next;                                      \
        free(temp);                                                       \
      }                                                                   \
      st->size = 0;                                                       \
      st->end = NULL;                                                     \
    } else {                                                              \
      printf("Stack is already clear.");                                  \
    }                                                                     \
  } while (0)

#endif  // !
