#include "../headers/tests.h"

Bool test_stack_init(stack* st, int _size) {
  stack_init(st, _size);
  int result = 0;
  cell* temp = st->begin;
  while (temp != NULL) {
    result++;
    temp = temp->next;
  }
  if (result == _size)
    return True;
  else
    return False;
}

Bool test_stack_push(stack* st, int el) {
  stack_push(st, el);
  if (st->end->key == el)
    return True;
  else
    return False;
}

Bool test_stack_pop(stack* st) {
  int before = st->end->key;
  stack_pop(st);
  int after = st->end->key;
  if (before != after)
    return True;
  else
    return False;
}


