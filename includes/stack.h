#ifndef _STACK
#define _STACK

#include <stdio.h>
#include <stdlib.h>

#define node(T)            \
  struct node_##T {        \
    T value;               \
    struct node_##T *next; \
    size_t type_size;      \
  }

#define stack(T)           \
  struct stack_##T {       \
    size_t size;           \
    node(T) * begin, *end; \
    size_t type_size;      \
  }

#define stack_constructor(T, st)               \
  do {                                         \
    st = malloc(sizeof(stack(T)) + sizeof(T)); \
    st->begin = NULL;                          \
    st->end = NULL;                            \
    st->size = 0;                              \
    st->type_size = sizeof(T);                 \
  } while (0)


#endif  // !
