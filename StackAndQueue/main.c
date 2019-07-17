#include <stdio.h>
#include "stack.h"
#include "tests.h"
int main(void) {
  stack obj;
  stack_create(&obj);
  test_stack_init(&obj, 10) == True ? printf("test_stack_init: OK\n")
                                    : printf("test_stack_init: FAIL\n");
  stack_decl_with_keyboard(&obj);
  test_stack_push(&obj, 12) == True ? printf("test_stack_push: OK\n")
                                    : printf("test_stack_push: FAIL\n");
  stack_print(&obj);
  test_stack_pop(&obj) == True ? printf("test_stack_pop: OK\n")
                               : printf("test_stack_pop: FAIL\n");
  stack_print(&obj);

  return 0;
}