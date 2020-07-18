#include "../includes/queue.h"

#if defined(_MSC_VER)
// queue_dequeue:
// 1) Check for the object accessibility
// 2) Check, is the queue emptiness
// 3) If there is only one element - dequeue it.
// 4) If there are several numbers of elements - dequeue the last one
void* queue_dequeue_function(queue(any_type) * qu) {
  if (qu) {
    if (qu->begin == NULL) {
      write_error_log(QUEUE_ELEMENT_INACCESSIBILITY(
                          "queue_dequeue_function(queue(any_type) * qu)"),
                      __LINE__, __FILE__, "");
      queue_destructor(qu);
      return (NULL);
    }
    void* result = qu->end->value;
    if (qu->end != qu->begin) {
      qu->end = qu->end->prev;
      free(qu->end->next);
      qu->end->next = NULL;
      qu->size--;
      return (result);
    }
    free(qu->end);
    qu->end = qu->begin = NULL;
    qu->size--;
    return (result);
  } else {
    write_error_log(
        QUEUE_INACCESSIBILITY("queue_dequeue_function(queue(any_type) * qu)"),
        __LINE__, __FILE__, "");
    return (NULL);
  }
}

void* queue_empty_function(queue(any_type)* qu) {
    if (qu) {
        return qu->size == 0 ? 1 : 0;
    }
    else {
        write_error_log(
            QUEUE_INACCESSIBILITY("queue_dequeue_function(queue(any_type) * qu)"),
            __LINE__, __FILE__, "");
        return (NULL);
    }
}

void* queue_peek_function(queue(any_type)* qu) {
    if (qu) {
        return qu->end->value;
    }
    else {
        write_error_log(
            QUEUE_INACCESSIBILITY("queue_dequeue_function(queue(any_type) * qu)"),
            __LINE__, __FILE__, "");
        return (NULL);
    }
}
#endif
