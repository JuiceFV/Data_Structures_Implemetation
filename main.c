#include "./includes/stack.h"

int main() {
  stack(int)* a = stack_constructor(int);
  stack_push(a, 7);
  stack_push(a, 6);
  stack_push(a, 5);
  printf("%d", stack_at(a, 0));
  stack_destructor(a);
  return (0);
}
