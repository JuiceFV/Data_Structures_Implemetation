#include <dos.h>
#include <stdio.h>
#include "../headers/queue.h"
#include "../headers/stack.h"
#include "../headers/tests.h"
int print_main_menu() {
  int num;
  printf("\tMain Menu\t\n");
  printf("Select an option from the ones below:\n\n");
  printf("1. Show information about marks\n");
  printf("2. Show infromation about program\n");
  printf("3. Show full information\n");
  printf("4. Start program\n");
  printf("5. Quit\n");
  printf("Input your choice: ");
  scanf("%d", &num);
  while (num < 1 || num > 5) {
    printf("\n(Wrong input)\nInput your choice: ");
    scanf("%d", &num);
  }
  return num;
}
void print_program_info() {
  printf("*Program Information*\n");
  printf(
      "------------------------------------------------------------------------"
      "-----------------------------------------------\n");
  printf(
      "This, I believe \"APPLICATION\" is a implementation of the stack and "
      "the queue "
      "via linked lists\n");
  printf(
      "Both (stack and queue) have the same methods (functions), but they have "
      "different realization these methods (functions).\n");
  printf(
      "Methods (Functions):\n{I'll use name as \"obj_create\" or "
      "\"obj_delete\".\"obj\" can be either a \"stack\" or a \"queue\"}\n");
  printf(
      "\t(1)obj_create(&object):\t\tthis method creates an object. Works the "
      "same as the constructor in OOP.\n");
  printf(
      "\t(2)obj_init(&object, size):\tthis this method creates object with "
      "some size.\n");
  printf(
      "\t(3)obj_free(&object):\t\tthis method resets all object parameters.\n");
  printf(
      "\t(4)obj_print(&object):\t\tthis method displays an object on the "
      "screen\n");
  printf(
      "\t(5)obj_push(&object, element):\tthis method adds a new element to the "
      "end of the object.\n");
  printf(
      "\t(6)obj_pop(&object):\t\tthis method removes an item from an object "
      "and returns it.\n");
  printf(
      "\t(7)obj_decl(&object):\t\tthis method fills the object with random "
      "integers.\n");
  printf(
      "\t(8)obj_delete(&object):\t\tthis method will remove an object from "
      "memory.\n");
  printf(
      "\t(9)obj_get_el(&object, index):\tthis method will return an element "
      "with some index.\n");
  printf(
      "------------------------------------------------------------------------"
      "-----------------------------------------------\n");
}
void print_mark_info() {
  printf("*Mark Information*\n");
  printf(
      "------------------------------------------------------------------------"
      "------------------\n");
  printf(
      "*-name of the operation-*\t- the operation that is happening at the "
      "moment\n");
  printf(
      "[-IMPORTANT-]\t\t\t- Essential information required for user "
      "success.\n");
  printf("(-WARNING-)\t\t\t- Dangerous certain consequences of an action.\n");
  printf(
      "{-NOTE-}\t\t\t- Information the user should notice even if skimming\n");
  printf(
      "<-TIP->\t\t\t\t- Optional information to help a user be more "
      "successful.\n");
  printf("|-CAUTION-|\t\t\t- Negative potential consequences of an action.\n");
  printf(
      "------------------------------------------------------------------------"
      "------------------\n");
}
void print_info() {
  print_program_info();
  printf("\n");
  print_mark_info();
  printf("Good Luck:)");
}

void load_visualisation(const char* const str, const int steps) {
  for (int i = 0; i <= steps; i++) {
    printf("\r%s %d%%", str, i);
    fflush(stdout);
    _sleep(10);
  }
  printf("\n");
}
void print_header() {
  printf("|***********************|\n");
  printf("|*** Stack And Queue ***|\n");
  printf("|***********************|\n\n");
}
void print_important(const char* const important_message) {
  printf("[%s]\n", important_message);
}
int main(void) {
  srand(time(NULL));
  Bool quit = False;
  while (quit == False) {
    int num = print_main_menu();
    system("cls");
    switch (num) {
      case 1: {
        print_mark_info();
        printf("\n");
        system("pause");
      } break;
      case 2: {
        print_program_info();
        printf("\n");
        system("pause");
      } break;
      case 3: {
        print_info();
        printf("\n");
        system("pause");
      } break;
      case 4: {
        print_header();
        stack st;
        queue qu;
        printf("*Data structures creation*\n");
        printf("------------------------------\n");
        load_visualisation("Stack creation: ", 100);
        stack_create(&st);
        print_important("Stack has been created");
        Bool stack_init_test = test_stack_init(stack_init, &st, 3);
        load_visualisation("Stack filling: ", 100);
        stack_decl(&st);
        print_important("Stack successfully filled");
        load_visualisation("Queue creation: ", 100);
        queue_create(&qu);
        print_important("Queue has been created");
        Bool queue_init_test = test_queue_init(queue_init, &qu, 5);
        load_visualisation("Queue filling: ", 100);
        queue_decl(&qu);
        print_important("Queue successfully filled");
        printf("------------------------------\n");
        _sleep(1000);
        printf("\n*Data structures visualization*\n");
        printf(
            "-----------------------------------------------------------------"
            "\n");
        printf("Stack:\t\t\t");
        stack_print(&st);
        Bool stack_push_test = test_stack_push(stack_push, &st, 12);
        printf("Stack after push:\t");
        stack_print(&st);
        Bool stack_pop_test = test_stack_pop(stack_pop, &st);
        printf("Stack after pop:\t");
        stack_print(&st);
        printf("\n");
        printf("Queue:\t\t\t");
        queue_print(&qu);
        Bool queue_push_test = test_queue_push(queue_push, &qu, 12);
        printf("Queue after push:\t");
        queue_print(&qu);
        Bool queue_pop_test = test_queue_pop(queue_pop, &qu);
        printf("Queue after pop:\t");
        queue_print(&qu);
        printf(
            "-----------------------------------------------------------------"
            "\n");

        printf("\n*Tests*\n");
        printf("----------------------------\n");
        stack_init_test == True ? printf("test stack init:\tOK\n")
                                : printf("test stack init:\tFAIL\n");
        stack_push_test == True ? printf("test stack push:\tOK\n")
                                : printf("test stack push:\tFAIL\n");
        stack_pop_test == True ? printf("test stack pop:\t\tOK\n")
                               : printf("test stack pop:\t\tFAIL\n");
        queue_init_test == True ? printf("test queue init:\tOK\n")
                                : printf("test queue init:\tFAIL\n");
        queue_push_test == True ? printf("test queue push:\tOK\n")
                                : printf("test queue push:\tFAIL\n");
        queue_pop_test == True ? printf("test queue pop:\t\tOK\n")
                               : printf("test queue pop:\t\tFAIL\n");
        printf("----------------------------\n");
        printf("\n*Data structures deletion*\n");
        printf("-------------------------\n");
        load_visualisation("Stack deletion: ", 100);
        stack_delete(&st);
        print_important("Stack has been deleted");
        load_visualisation("Queue deletion: ", 100);
        queue_delete(&qu);
        print_important("Queue has been deleted");
        printf("-------------------------\n\n");
        system("pause");
      } break;
      case 5: {
        quit = True;
      } break;
    }
    system("cls");
  }

  return 0;
}