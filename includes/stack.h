#ifndef _STACK
#define _STACK

#include <stdio.h>
#include <stdlib.h>

// Here I defined the node(T). I'ill explain a little bit.
// First, let's remember how do we use the template-class in C++
// For example, vector: vector<int> a;
// In my fancy the usage of my stack will seems like that: stack(int) *a;
// I would to use the linked-list for the stack creation, therefore I need
// to create a node. The type will be passed as an argument. We'ill concatenate
// the node_ with the type, for instance stack(int) will seems like that:
// node_int*. And value will has an integer type.
#define node(T)            \
  struct node_##T {        \
    T value;               \
    struct node_##T *next; \
  }

// As I said before, I would to use the templates. And the stack has the same
// idea as the node.
#define stack(T)           \
  struct stack_##T {       \
    size_t size;           \
    node(T) * begin, *end; \
  }

// Simple constructor.
// Here I just allocate the memory for the stack
// with the type T. And zeroing every field.
#define stack_constructor(T, st)     \
  {                                  \
    if (st == NULL) {                \
      st = malloc(sizeof(stack(T))); \
      st->begin = NULL;              \
      st->end = NULL;                \
      st->size = 0;                  \
    }                                \
  }

// Simple destructor.
// Just freeing each node.
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

// Stack resize.
// Here we will change the size of the given stack.
// First, we should to check the data accuracy, espesially
// we shall to check the _size, which passing as argument.
// Let's consider some excepions
// 1) The _size is either 0 or less then current size
// 2) The _size is equal to the current size
// 3) Feasibly, we didn't initialize the stack before resize
// If we passed the all previous steps, thus we can make
// the stack-capacity bigger. If this stack wasn't created, namely
// the pointer-begin points onto NULL, therefor we'll create the stack/first
// node. If the <begin> exists we're creates remain nodes, using end-pointer.
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

#define stack_clear(st)   \
  do {                    \
    stack_destructor(st); \
    st = NULL;            \
  } while (0)

#endif  // !
