#ifndef _TESTS
#define _TESTS
#include <stdio.h>
#include "../headers/stack.h"
#include"../headers/queue.h"

typedef enum { True, False } Bool;

Bool test_stack_init(stack* st, int _size);
Bool test_stack_push(stack* st, int el);
Bool test_stack_pop(stack* st);
Bool test_stack_get_el(stack* st, int index, int el);
Bool test_queue_init(queue* qu, int _size);
Bool test_queue_push(queue* qu, int el);
Bool test_queue_pop(queue* qu);
Bool test_queue_get_el(queue* qu, int index, int el);
#endif _TESTS