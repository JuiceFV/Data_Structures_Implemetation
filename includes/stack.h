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

#define stack_constructor(T, st)     \
  do {                               \
    if (st == NULL) {                \
      st = malloc(sizeof(stack(T))); \
      st->begin = NULL;              \
      st->end = NULL;                \
      st->size = 0;                  \
    }                                \
  } while (0)

#define stack_destructor(st)                                              \
  {                                                                       \
    if (st) {                                                             \
      if (st->begin) {                                                    \
        do {                                                              \
          void *temp = st->begin;                                         \
          st->begin = st->begin->next;                                    \
          free(temp);                                                     \
        } while (st->begin != NULL);                                      \
      }                                                                   \
      free(st);                                                           \
    } else {                                                              \
      printf(                                                             \
          "There is no stack. You must use the constructor before using " \
          "the stack_destructor.\nTo avoid any errors this program will " \
          "abort. "                                                       \
          "Please press any key");                                        \
      return (getchar());                                                 \
    }                                                                     \
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
      st->begin = malloc(sizeof(*(st->begin)) + sizeof(st->begin->value));   \
      st->begin->value = (0);                                                \
      st->begin->next = NULL;                                                \
      st->end = st->begin;                                                   \
      i++;                                                                   \
    }                                                                        \
    while (i < _size) {                                                      \
      st->end->next = malloc(sizeof(*(st->end)) + sizeof(st->end->value));   \
      st->end = st->end->next;                                               \
      st->end->value = (0);                                                  \
      st->end->next = NULL;                                                  \
      i++;                                                                   \
    }                                                                        \
    st->size = _size;                                                        \
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

#if defined(_MSC_VER)
    typedef void *any_type;
    void *stack_pop_function(stack(any_type) * st);
    #define stack_pop(st) stack_pop_function(st)
#endif //

#endif  // !
