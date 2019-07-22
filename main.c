#include <stdio.h>
#include "../headers/queue.h"
#include "../headers/stack.h"
#include "../headers/tests.h"
int main(void) {
  stack st;
  stack_create(&st);
  stack_init(&st, 3);
  stack_decl_with_keyboard(&st);
  printf("\n\n*stack tests*\n\n");
  test_stack_init(&st, 3) == True ? printf("test stack init:\tOK\n")
                                  : printf("test stack init:\tFAIL\n");
  test_stack_push(&st, 12) == True
      ? printf("test stack push:\tOK (12 was pushed in queue)\n")
      : printf("test stack push:\tFAIL\n");
  test_stack_pop(&st) == True
      ? printf("test stack pop:\t\tOK (12 was poped from queue)\n")
      : printf("test stack pop:\t\tFAIL\n");
  test_stack_get_el(&st, 2, 2) == True ? printf("test stack get element:\tOK\n")
                                       : printf("test stack element:\tFAIL\n");
  stack_print(&st);
  stack_delete(&st);

  queue qu;
  queue_create(&qu);
  queue_init(&qu, 5);
  queue_decl_with_keyboard(&qu);
  printf("\n\n*queue tests*\n\n");
  test_queue_init(&qu, 5) == True ? printf("test queue init:\tOK\n")
                                  : printf("test queue init:\tFAIL\n");
  test_queue_push(&qu, 12) == True
      ? printf("test queue push:\tOK (12 was pushed in queue)\n")
      : printf("test queue push:\tFAIL\n");
  test_queue_pop(&qu) == True
      ? printf("test queue pop:\t\tOK (0 was poped from queue)\n")
      : printf("test queue pop:\t\tFAIL\n");
  test_queue_get_el(&qu, 2, 3) == True ? printf("test queue get element:\tOK\n")
                                       : printf("test queue element:\tFAIL\n");
  queue_print(&qu);
  queue_delete(&qu);
  return 0;
}