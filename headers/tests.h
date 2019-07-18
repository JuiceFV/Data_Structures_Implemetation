#ifndef _TESTS
#define _TESTS
#include <stdio.h>
#include "../headers/stack.h"

typedef enum { True, False } Bool;

Bool test_stack_init(stack* st, int _size);
Bool test_stack_push(stack* st, int el);
Bool test_stack_pop(stack* st);
#endif _TESTS