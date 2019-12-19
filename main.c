#include "stack.h"

int main() {
  stack(int) *a = NULL;
  stack_constructor(int, a);
  printf("%d\n", sizeof(*a));
  stack_resize(a, 5);
  //stack_resize(a, 4);
  printf("%d", sizeof(*a));
  stack_destructor(a);
  return (0);
}
