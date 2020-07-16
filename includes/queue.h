/*
    <QUEUE DATA STRUCTURE>
    What is queue ?
    - It is type of linear data structure.
    - It follows FIFO(First In First Out) property.
    - Insertion in queue can only be done from top only.
    - Deletion from queue can only be done from end only.
    - Insertion in queue is also known as a ENQUEUE operation.
    - Deletion from queue is also known as DEQUEUE operation in queue.
    Queue Implementation
    - Queue implementation using array.
    - Queue implementation using linked list. (I used)
*/
// Also I would note that I can't (I don't know if I will find a sulution then I
// will fix it) implement some behavior due to MSVC-compiler
#ifndef _QUEUE
#define _QUEUE

// Including the header which will be used as common file for the
// all data-structures-implementation.
// Now it contains:
// - Error messages
// - function which writes error logs
// - library for the memory leaks detection (#include <crtdbg.h>)
#include "common.h"
#include "error.h"

// This define will expands as
// struct node_T{T value; struct node_T *next}, where T is a type
// The operator "##" using as concatenation operator.
// You can read more about this here:
// https://docs.microsoft.com/en-us/cpp/preprocessor/token-pasting-operator-hash-hash?view=vs-2019
#define node(T)            \
  struct node_##T {        \
    T value;               \
    struct node_##T *next; \
    struct node_##T *prev; \
  }

// This "define" will expands as
// struct queue_T{size_t size; node(T) * begin, *end;}, where T is a type
#define queue(T)           \
  struct queue_##T {       \
    unsigned long size;    \
    node(T) * begin, *end; \
  }

#define anticipated_error 1

// The destructor freeing memory which were allocated for the queue.
// Check for the both the queue and the first element availability. If at least
// one element exists then freeing node by node. As soon as each element is
// freed, the entire queue is freed.
#define queue_destructor(qu)                                                   \
  {                                                                            \
    return_val_from_macro = 1;                                                 \
    if (qu && anticipated_error == 1) {                                        \
      if (qu->begin) {                                                         \
        do {                                                                   \
          void *temp = qu->begin;                                              \
          qu->begin->prev = qu->begin;                                         \
          qu->begin = qu->begin->next;                                         \
          free(temp);                                                          \
        } while (qu->begin != NULL);                                           \
      }                                                                        \
      free(qu);                                                                \
      qu = NULL;                                                               \
    } else {                                                                   \
      char *specific_dir =                                                     \
          cat_dir_and_num("includes/queue.h:", queue_error_lines[1]);          \
      write_error_log(QUEUE_INACCESSIBILITY("queue_destructor(qu)"), __LINE__, \
                      __FILE__, specific_dir);                                 \
      free(specific_dir);                                                      \
      return_val_from_macro = NULL;                                            \
    }                                                                          \
  }

// Splitting into two implementations due to the variety of compilers. However,
// the basic logic is the same.
#if defined(_MSC_VER)
// The constructor is allocating the memory for the queue and zeroing each
// field. Otherwise it writes an error into error_logs.txt
#define queue_constructor(T, qu)                                          \
  {                                                                       \
    return_val_from_macro = 1;                                            \
    if (qu == NULL && anticipated_error == 1) {                           \
      if (!(qu = malloc(sizeof(queue(T)))) && anticipated_error == 1) {   \
        char *specific_dir =                                              \
            cat_dir_and_num("includes/queue.h:", queue_error_lines[3]);   \
        write_error_log(MALLOC_ERROR_MESSAGE, __LINE__, __FILE__,         \
                        specific_dir);                                    \
        free(specific_dir);                                               \
        return_val_from_macro = NULL;                                     \
      }                                                                   \
      qu->begin = NULL;                                                   \
      qu->end = NULL;                                                     \
      qu->size = 0;                                                       \
    } else {                                                              \
      char *specific_dir =                                                \
          cat_dir_and_num("includes/queue.h:", queue_error_lines[2]);     \
      write_error_log(QUEUE_EXISTANCE, __LINE__, __FILE__, specific_dir); \
      free(specific_dir);                                                 \
      return_val_from_macro = NULL;                                       \
    }                                                                     \
  }

// Due to there is no way to use such notation queue(void *). It demands the
// typedef. The dequeue function will be described in queue.c
void *queue_dequeue_function(queue(any_type) * qu);
#define queue_dequeue(qu) queue_dequeue_function(qu)
// GNUC-compiler implementation begins
#elif defined(__GNUC__)
#define queue_constructor(T)                                                   \
  ({                                                                           \
    struct queue_##T *qu;                                                      \
    return_val_from_macro = 1;                                                 \
    if (!(qu = malloc(sizeof(queue(T)))) && anticipated_error == 1) {          \
      char *specific_dir =                                                     \
          cat_dir_and_num("includes/queue.h:", queue_error_lines[4]);          \
      write_error_log(MALLOC_ERROR_MESSAGE, __LINE__, __FILE__, specific_dir); \
      free(specific_dir);                                                      \
      return_val_from_macro = NULL;                                            \
    }                                                                          \
    qu->begin = NULL;                                                          \
    qu->end = NULL;                                                            \
    qu->size = 0;                                                              \
    qu;                                                                        \
  })

#define queue_dequeue(qu)                                                   \
  ({                                                                        \
    typeof(qu->begin->value) result;                                        \
    return_val_from_macro = 1;                                              \
    if (qu && anticipated_error == 1) {                                     \
      char *specific_dir =                                                  \
          cat_dir_and_num("includes/queue.h:", queue_error_lines[5]);       \
      if (qu->begin == NULL && anticipated_error == 1) {                    \
        write_error_log(QUEUE_ELEMENT_INACCESSIBILITY("queue_dequeue(qu)"), \
                        __LINE__, __FILE__, specific_dir);                  \
        free(specific_dir);                                                 \
        return_val_from_macro = NULL;                                       \
      }                                                                     \
      result = qu->end->value;                                              \
      if (qu->begin != qu->end) {                                           \
        qu->end = qu->end->prev;                                            \
        free(qu->end->next);                                                \
        qu->end->next = NULL;                                               \
        qu->size--;                                                         \
      } else {                                                              \
        free(qu->end);                                                      \
        qu->begin = NULL;                                                   \
        qu->end = NULL;                                                     \
        qu->size--;                                                         \
      }                                                                     \
    } else {                                                                \
      char *specific_dir =                                                  \
          cat_dir_and_num("includes/queue.h:", queue_error_lines[6]);       \
      write_error_log(QUEUE_INACCESSIBILITY("queue_dequeue(qu)"), __LINE__, \
                      __FILE__, specific_dir);                              \
      free(specific_dir);                                                   \
      return_val_from_macro = NULL;                                         \
    }                                                                       \
    if (!return_val_from_macro) return_val_from_macro = result;             \
    result;                                                                 \
  })

#endif  // end compiler-split implimentation

// Due to in the queue_enqueue a type doesn't available we shall use another
// method of memory allocating. This method is fully described here:
// https://en.wikipedia.org/wiki/Flexible_array_member
// First, check for the queue availability and for the queue-overflow. In the
// case if the queue exists then push element from the top.
#define queue_enqueue(qu, val)                                                 \
  {                                                                            \
    return_val_from_macro = 1;                                                 \
    if (qu && anticipated_error == 1) {                                        \
      if (qu->size++ < MAX_SIZE && anticipated_error == 1) {                   \
        if (qu->begin) {                                                       \
          qu->begin->prev =                                                    \
              malloc(sizeof(*(qu->begin)) + sizeof(qu->begin->value));         \
          qu->begin->prev->next = qu->begin;                                   \
          qu->begin = qu->begin->prev;                                         \
          qu->begin->value = val;                                              \
          qu->begin->prev = NULL;                                              \
        } else {                                                               \
          qu->begin = malloc(sizeof(*(qu->begin)) + sizeof(qu->begin->value)); \
          qu->begin->value = val;                                              \
          qu->begin->next = NULL;                                              \
          qu->begin->prev = NULL;                                              \
          qu->end = qu->begin;                                                 \
        }                                                                      \
      } else {                                                                 \
        char *specific_dir =                                                   \
            cat_dir_and_num("includes/queue.h:", queue_error_lines[7]);        \
        write_error_log(QUEUE_OVERFLOW, __LINE__, __FILE__, specific_dir);     \
        free(specific_dir);                                                    \
        return_val_from_macro = NULL;                                          \
        queue_destructor(qu);                                                  \
      }                                                                        \
    } else {                                                                   \
      char *specific_dir =                                                     \
          cat_dir_and_num("includes/queue.h:", queue_error_lines[8]);          \
      write_error_log(QUEUE_INACCESSIBILITY("queue_enqueue(qu, val)"),         \
                      __LINE__, __FILE__, specific_dir);                       \
      free(specific_dir);                                                      \
      return_val_from_macro = NULL;                                            \
    }                                                                          \
  }

#define queue_empty(qu) qu->size == 0 ? 1 : 0

#define queue_peek(qu) qu->end->value

// Queue clear is the method which removes each node but it doesn't removes
// whole queue. Check for queue and first element availability. If both true
// then removes node by node.
#define queue_clear(qu)                                                    \
  do {                                                                     \
    if (qu == NULL && anticipated_error == 1) {                            \
      char *specific_dir =                                                 \
          cat_dir_and_num("includes/queue.h:", queue_error_lines[9]);      \
      write_error_log(QUEUE_INACCESSIBILITY("queue_clear(qu)"), __LINE__,  \
                      __FILE__, specific_dir);                             \
      free(specific_dir);                                                  \
      printf(                                                              \
          "Error has occured! Check error_log.txt for the more details.\n" \
          "Press any key");                                                \
      return (getchar());                                                  \
    }                                                                      \
    if (qu->begin != NULL && anticipated_error == 1) {                     \
      while (qu->begin->next != NULL) {                                    \
        qu->begin = qu->begin->next;                                       \
        free(qu->begin->prev);                                             \
      }                                                                    \
      free(qu->begin);                                                     \
      qu->size = 0;                                                        \
      qu->end = qu->begin = NULL;                                          \
    } else {                                                               \
      char *specific_dir =                                                 \
          cat_dir_and_num("includes/queue.h:", queue_error_lines[10]);     \
      write_error_log(QUEUE_EMPTINESS, __LINE__, __FILE__, specific_dir);  \
      free(specific_dir);                                                  \
      printf(                                                              \
          "Error has occured! Check error_log.txt for the more details.\n" \
          "Press any key");                                                \
      queue_destructor(qu);                                                \
      return (getchar());                                                  \
    }                                                                      \
  } while (0)
#endif  // !_QUEUE
