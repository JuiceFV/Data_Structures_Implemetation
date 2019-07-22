#include "../headers/queue.h"

void queue_create(queue* qu) {
  qu->begin = NULL;
  qu->end = NULL;
  qu->size = 0;
}

void queue_init(queue* qu, int _size) {
  queue_free(qu);
  qu->size = _size;
  qu->begin = (q_cell*)malloc(1 * sizeof(q_cell));
  qu->begin->prev = NULL;
  qu->begin->next = NULL;
  qu->end = qu->begin;
  for (int i = 0; i < qu->size - 1; i++) {
    qu->end->next = (q_cell*)malloc(1 * sizeof(q_cell));
    qu->end->prev = qu->end;
    qu->end = qu->end->next;
    qu->end->next = NULL;
  }
}

void queue_print(queue* qu) {
  printf("\n*queue print*\n\n");
  if (qu->begin == NULL) return;
  q_cell* print_el = qu->begin;
  printf("[ | ");
  while (print_el != NULL) {
    printf("%d | ", print_el->key);
    print_el->prev = print_el;
    print_el = print_el->next;
  }
  printf("]\n\n");
}

void queue_free(queue* qu) { qu = NULL; }

void queue_push(queue* qu, int el) {
  if (qu->begin == NULL) {
    qu->size++;
    qu->begin = (q_cell*)malloc(1 * sizeof(q_cell));
    qu->begin->key = el;
    qu->begin->prev = NULL;
    qu->begin->next = NULL;
    qu->end = qu->begin;
  } else {
    qu->size++;
    qu->end->next = (q_cell*)malloc(1 * sizeof(q_cell));
    qu->end->prev = qu->end;
    qu->end = qu->end->next;
    qu->end->key = el;
    qu->end->next = NULL;
  }
}

int queue_pop(queue* qu) {
  if (qu->size == 0) {
    printf("Queue is empty\n");
    abort();
  } else {
    int deleted = qu->begin->key;
    q_cell* temp = qu->begin;
    qu->begin = temp->next;
    free(temp);
    qu->begin->prev = NULL;
    qu->size--;
    return deleted;
  }
}

int queue_get_el(queue* qu, int index) {
  if (qu->begin == NULL) {
    printf("Queue is empty\n");
    abort();
  }
  if (qu->size < index) {
    printf("Size of the queue is less than index\n");
    abort();
  }
  q_cell* temp = qu->begin;
  while (index != 0) {
    temp->prev = temp;
    temp = temp->next;
    index--;
  }
  return temp->key;
}

void queue_decl_with_keyboard(queue* qu) {
  printf("\n*queue fillization*\n\n");
  if (qu->begin == NULL) {
    printf("Queue doesn't initialized\n");
    abort();
  } else {
    q_cell* temp = qu->begin;
    int index = 0;
    while (temp != NULL) {
      printf("Input %d element: ", index);
      scanf_s("%d", &temp->key);
      temp->prev = temp;
      temp = temp->next;
      index++;
    }
  }
}

void queue_delete(queue* qu) {
  if (qu->begin == NULL) {
    printf("There is no queue\n");
    abort();
  } else {
    if (qu->begin == qu->end) {
      free(qu->begin);
    } else {
      free(qu->end);
      free(qu->begin);
    }
  }
}