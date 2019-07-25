#ifndef _TESTS
#define _TESTS
#include <stdio.h>
#include "../headers/queue.h"
#include "../headers/stack.h"

typedef enum { True, False } Bool;

Bool test_stack_init(void (*stack_init_func)(stack*, int), stack* st,
                     int _size);
Bool test_stack_push(void (*stack_push_func)(stack*, int), stack* st, int el);
Bool test_stack_pop(int (*stack_pop_func)(stack*), stack* st);

Bool test_queue_init(void (*queue_init_func)(queue*, int), queue* qu,
                     int _size);
Bool test_queue_push(void (*queue_push_func)(queue*, int), queue* qu, int el);
Bool test_queue_pop(int (*queue_pop_func)(queue*), queue* qu);

#endif _TESTS