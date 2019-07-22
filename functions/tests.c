#include "../headers/tests.h"

Bool test_stack_init(stack* st, int _size) {
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

Bool test_stack_get_el(stack* st, int index, int el) {
  if (stack_get_el(st, index) == el) {
    return True;
  } else {
    return False;
  }
}

Bool test_queue_init(queue* qu, int _size) {
  int result = 0;
  q_cell* temp = qu->begin;
  while (temp != NULL) {
    result++;
    temp->prev = temp;
    temp = temp->next;
  }
  if (result == _size)
    return True;
  else
    return False;
}
Bool test_queue_push(queue* qu, int el) {
  queue_push(qu, el);
  if (qu->end->key == el)
    return True;
  else
    return False;
}
Bool test_queue_pop(queue* qu) {
  int before = qu->begin->key;
  queue_pop(qu);
  int after = qu->begin->key;
  if (before != after)
    return True;
  else
    return False;
}
Bool test_queue_get_el(queue* qu, int index, int el) {
  if (queue_get_el(qu, index) == el) {
    return True;
  } else {
    return False;
  }
}