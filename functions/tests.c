#include "../headers/tests.h"

Bool test_stack_init(void(*stack_init_func)(stack*, int), stack* st,
                     int _size) {
  stack_init_func(st, _size);
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

Bool test_stack_push(void(*stack_push_func)(stack*, int), stack* st, int el) {
  stack_push_func(st, el);
  if (st->end->key == el)
    return True;
  else
    return False;
}

Bool test_stack_pop(int(*stack_pop_func)(stack*), stack* st) {
  int before = st->end->key;
  stack_pop_func(st);
  if (st->end->key != before)
    return True;
  else
    return False;
}


Bool test_queue_init(void(*queue_init_func)(queue*,int),queue* qu, int _size) {
  queue_init_func(qu, _size);
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
Bool test_queue_push(void(*queue_push_func)(queue*,int), queue* qu, int el) {
  queue_push_func(qu, el);
  if (qu->end->key == el)
    return True;
  else
    return False;
}
Bool test_queue_pop(int(*queue_pop_func)(queue*), queue* qu) {
  queue_pop_func(qu);
  int before = qu->begin->key;
  queue_pop(qu);
  int after = qu->begin->key;
  if (before != after)
    return True;
  else
    return False;
}
