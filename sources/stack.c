#include "../includes/stack.h"

#if defined(_MSC_VER)
// stack_pop:
// 1) Check for the object accessibility
// 2) Check, is the stack empty
// 3) If there is only one element - pop it.
// 4) If there are several numbers of elements:
// 4.1) In the while-cycle going toward the penultimate element
// 4.2) Make the penultimate element as last.
// 4.3) According LIFO - pop that element which was last at the 4.1-step
// 5) return the element, which we have popped
void *stack_pop_function(stack(any_type) * st) {
  if (st) {
    if (st->begin == NULL) {
      write_error_log(ELEMENT_INACCESSIBILITY(
                          "stack_pop_function(stack(any_type) * stack)"),
                      __LINE__, __FILE__, "");
      printf(
          "Error has occured! Check error_log.txt for the more details.\n"
          "Press any key");
      exit(getchar());
    }
    void *result = st->end->value;
    if (st->begin == st->end) {
      free(st->end);
      st->begin = st->end = NULL;
      st->size--;
      return (result);
    }
    void *temp1 = st->begin;
    while (st->begin->next != st->end) st->begin = st->begin->next;
    st->end = st->begin;
    st->begin = temp1;
    free(st->end->next);
    st->end->next = NULL;
    st->size--;
    return (result);
  } else {
    write_error_log(
        STACK_INACCESSIBILITY("stack_pop_function(stack(any_type) * stack)"),
        __LINE__, __FILE__, "");
    printf(
        "Error has occured! Check error_log.txt for the more details.\n"
        "Press any key");
    exit(getchar());
  }
}

void *stack_at_function(stack(any_type) * st, unsigned int index) {
  if (st) {
    if (st->begin == NULL) {
      write_error_log(
          ELEMENT_INACCESSIBILITY(
              "stack_at_function(stack(any_type) * st, unsigned int index)"),
          __LINE__, __FILE__, "");
      printf(
          "Error has occured! Check error_log.txt for the more details.\n"
          "Press any key");
      exit(getchar());
    }
    if ((index >= 0) && (index < st->size)) {
      void *temp = st->begin;
      while (st->begin && (index-- > 0)) st->begin = st->begin->next;
      void *result = st->begin->value;
      st->begin = temp;
      return (result);
    }
  } else {
    write_error_log(
        STACK_INACCESSIBILITY(
            "stack_at_function(stack(any_type) * st, unsigned int index)"),
        __LINE__, __FILE__, "");
    printf(
        "Error has occured! Check error_log.txt for the more details.\n"
        "Press any key");
    exit(getchar());
  }
}
#endif
