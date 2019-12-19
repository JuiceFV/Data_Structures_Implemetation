#ifndef _STACK
#define _STACK

#include <stdio.h>
#include <stdlib.h>

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

#define stack_constructor(T, st)                 \
  {                                              \
    if (st == NULL) {                            \
      st = malloc(sizeof(stack(T)) + sizeof(T)); \
      st->begin = NULL;                          \
      st->end = NULL;                            \
      st->size = 0;                              \
    }                                            \
  }

#define stack_destructor(st)         \
  {                                  \
    if (st->begin) {                 \
      do {                           \
        void *temp = st->begin;      \
        st->begin = st->begin->next; \
        free(temp);                  \
      } while (st->begin != NULL);   \
      free(st);                      \
    }                                \
  }

#define stack_resize(st, _size)                                              \
  {                                                                          \
    if (st == NULL) {                                                        \
      printf(                                                                \
          "There is no stack. You must use the constructor before using "    \
          "the stack_resize.\nTo avoid any errors this program will abort. " \
          "Please press any key");                                           \
      return (getchar());                                                    \
    }                                                                        \
    if (st->size > _size) {                                                  \
      printf(                                                                \
          "Wrong size. You trying to cut the size of the vector\nTo avoid "  \
          "any errors this program will abort. Please press any key");       \
      stack_destructor(st);                                                  \
      return (getchar());                                                    \
    }                                                                        \
    int i = st->size;                                                        \
    if (st->begin == NULL) {                                                 \
      st->begin = malloc(sizeof(st->begin) + sizeof(st->begin->value));      \
      st->begin->value = (0);                                                \
      st->begin->next = NULL;                                                \
      st->end = st->begin;                                                   \
      i++;                                                                   \
    }                                                                        \
    while (i < _size) {                                                      \
      st->end->next = malloc(sizeof(st->end) + sizeof(st->end->value));      \
      st->end = st->end->next;                                               \
      st->end->value = (0);                                                  \
      st->end->next = NULL;                                                  \
      i++;                                                                   \
    }                                                                        \
    st->size = _size;                                                        \
  }

#endif  // !
