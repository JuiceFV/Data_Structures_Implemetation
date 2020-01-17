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
      printf(
          "Error has occured! Check error_log.txt for the more details.\n"
          "Press any key");
      queue_destructor(qu);
      _CrtDumpMemoryLeaks();
      exit(getchar());
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
    qu->end = NULL;
    qu->size--;
    return (result);
  } else {
    write_error_log(
        QUEUE_INACCESSIBILITY("queue_dequeue_function(queue(any_type) * qu)"),
        __LINE__, __FILE__, "");
    printf(
        "Error has occured! Check error_log.txt for the more details.\n"
        "Press any key");
    _CrtDumpMemoryLeaks();
    exit(getchar());
  }
}
#endif
