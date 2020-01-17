#include "./includes/stack.h"
#include "./includes/queue.h"

int main() {
    stack(int)* a = NULL;
    stack_constructor(int, a);
    stack_push(a, 7);
    stack_push(a, 6);
    stack_push(a, 5);
    stack_push(a, 4);
    stack_push(a, 3);
    stack_push(a, 2);
    printf("%d", stack_pop(a));
    stack_destructor(a);
  return (0);
}