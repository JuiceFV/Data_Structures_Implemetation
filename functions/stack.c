#include "../headers/stack.h"

void stack_create(stack* st) {
  st->size = 0;
  st->begin = NULL;
  st->end = NULL;
}

void stack_init(stack* st, int _size) {
  stack_free(&st);
  st->size = _size;
  st->begin = (cell*)malloc(1 * sizeof(cell));
  st->begin->next = NULL;
  st->end = st->begin;
  for (int i = 0; i < st->size - 1; i++) {
    st->end->next = (cell*)malloc(1 * sizeof(cell));
    st->end = st->end->next;
    st->end->next = NULL;
  }
}

void stack_free(stack* st) { st = NULL; }

void stack_print(stack* st) {
  printf("\n*stack print*\n\n");
  if (st->begin == NULL) return;
  cell* print_el = st->begin;
  printf("[ | ");
  while (print_el != NULL) {
    printf("%d | ", print_el->key);
    print_el = print_el->next;
  }
  printf("]\n\n");
}

void stack_push(stack* st, int el) {
  if (st->begin == NULL) {
    st->size++;
    st->begin = (cell*)malloc(1 * sizeof(cell));
    st->begin->key = el;
    st->begin->next = NULL;
    st->end = st->begin;
  } else {
    st->size++;
    st->end->next = (cell*)malloc(1 * sizeof(cell));
    st->end = st->end->next;
    st->end->key = el;
    st->end->next = NULL;
  }
}

int stack_pop(stack* st) {
  if (st->size == 0) {
    printf("Stack is empty\n");
    abort();
  } else {
    int deleted = st->end->key;
    cell* temp = st->begin;
    while (temp->next != st->end) {
      temp = temp->next;
    }
    st->end = temp;
    temp = temp->next;
    free(temp);
    st->end->next = NULL;
    st->size--;
    return deleted;
  }
}

int stack_get_el(stack* st, int index) {
  if (st->begin == NULL) {
    printf("Stack is empty\n");
    abort();
  }
  if (st->size < index) {
    printf("Size of the stack is less than index\n");
    abort();
  }
  cell* temp = st->begin;
  while (index != 0) {
    temp = temp->next;
    index--;
  }
  return temp->key;
}

void stack_decl_with_keyboard(stack* st) {
  printf("\n*stack fillization*\n\n");
  if (st->begin == NULL) {
    printf("Stack doesn't initialized\n");
    abort();
  } else {
    cell* temp = st->begin;
    int index = 0;
    while (temp != NULL) {
      printf("Input %d element: ", index);
      scanf_s("%d", &temp->key);
      temp = temp->next;
      index++;
    }
  }
}

void stack_delete(stack* st) {
  if (st->begin == NULL) {
    printf("There is no stack\n");
    abort();
  } else {
    if (st->begin == st->end) {
      free(st->begin);
    } else {
      free(st->end);
      free(st->begin);
    }
  }
}