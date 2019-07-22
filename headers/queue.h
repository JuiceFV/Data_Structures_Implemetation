#ifndef _QUEUE
#define _QUEUE
#include <stdio.h>
#include <stdlib.h>

typedef struct q_cell {
  int key;
  struct q_cell* prev;
  struct q_cell* next;
} q_cell;

typedef struct queue {
  int size;
  q_cell* begin;
  q_cell* end;
} queue;

// -----------main functions------------
// create queue (constructor)
// without test
void queue_create(queue* qu);
// queue initialization with some size
void queue_init(queue* qu, int _size);
// clear queue
// without test
void queue_free(queue* qu);
// print queue
// without test
void queue_print(queue* qu);
// push element in queue
void queue_push(queue* qu, int el);
// pop elements from queue
int queue_pop(queue* qu);
// get element by index
int queue_get_el(queue* qu, int index);
// queue declaration using keyboard input
// without test
void queue_decl_with_keyboard(queue* qu);
// delete memory
// without test
void queue_delete(queue* qu);
// --------end of main functions--------
#endif _QUEUE