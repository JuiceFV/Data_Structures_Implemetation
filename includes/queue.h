#ifndef _QUEUE
#define _QUEUE

// Including the header which will be used as common file for the
// all data-structures-implementation.
// Now it contains:
// - Error messages
// - function which writes error logs
// - library for the memory leaks detection (#include <crtdbg.h>)
#include "common.h"

#define queue(T)        \
  struct queue_##T {    \
    unsigned long size; \
    T *values;          \
  }

#define queue_destructor(qu) free(qu)
#if defined(_MSC_VER)
#define queue_constructor(T, qu)                                           \
  {                                                                        \
    if (qu == NULL) {                                                      \
      qu = malloc(sizeof(queue(T)) + sizeof(T) * 0);                       \
      qu->size = 0;                                                        \
      qu->values = NULL;                                                   \
    } else {                                                               \
      write_error_log(QUEUE_EXISTANCE, __LINE__, __FILE__,                 \
                      "includes/queue.h:22");                              \
      printf(                                                              \
          "Error has occured! Check error_log.txt for the more details.\n" \
          "Press any key");                                                \
      return (getchar());                                                  \
    }                                                                      \
  }
#elif defined(__GNUC__)
#define queue_constructor(T, qu)                              \
  ({                                                          \
    queue_##T *qu = malloc(sizeof(queue(T)) + sizeof(T) * 0); \
    qu->size = 0;                                             \
    qu->values = NULL;                                        \
    qu;                                                       \
  })

#endif

#endif  // !_QUEUE
