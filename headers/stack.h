// stack realiztion with singly linked list
#ifndef _STACK
#define _STACK
#include <stdio.h>
#include <stdlib.h>

// ---------struct initialization-------
// struct for each ellement of stack
typedef struct cell {
  int key;            // key ellement
  struct cell* next;  // pointer to the next cell
} cell;
// struct for stack-ellement
typedef struct stack {
  int size;     // stack size
  cell* begin;  // pointer at the first ellement
  cell* end;    // pointer at the last ellement
} stack;
// ----end of struct initialization-----

// -----------main functions------------
// create stack (constructor)
// without test
void stack_create(stack* st);
// stack initialization with some size
void stack_init(stack* st, int _size);
// clear stack
// without test
void stack_free(stack* st);
// print stack
// without test
void stack_print(stack* st);
// push element in stack
void stack_push(stack* st, int el);
// pop elements from stack
int stack_pop(stack* st);
// get element by index
int stack_get_el(stack* st, int index);
// stack declaration using keyboard input
// without test
void stack_decl(stack* st);
// delete memory
// without test
void stack_delete(stack* st);
// --------end of main functions--------

#endif _STACK