#include "../includes/stack.h"

void* stack_pop_function(stack(any_type) * st) {
  if (st) {
    void* result = st->end->value;
    if (st->begin == st->end)
    {
        free(st->end);
        st->begin = st->end = NULL;
        st->size--;
        return (result);
    }
    void* temp1 = st->begin;
    while (st->begin->next != st->end) st->begin = st->begin->next;
    st->end = st->begin;
    st->begin = temp1;
    free(st->end->next);
    st->end->next = NULL;
    st->size--;
    return (result);
  } else {
    printf(
        "There is no stack. You must use the constructor before using "
        "the stack_pop.\nTo avoid any errors this program will "
        "abort. "
        "Please press any key");
    exit(getchar());
  }
}
