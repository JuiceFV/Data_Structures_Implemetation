#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "premain.h"
#include "queue.h"

static void queue_correct_constructor_behavior_test() {
#if defined (_MSC_VER)
  queue(int)* a = NULL;
  queue_constructor(int, a);
#elif defined (__GNUC__)
    queue(int)* a = queue_constructor(int);
#endif
  if (return_val_from_macro == 0) {
    assert_true(a != NULL);
    assert_true(a->begin == NULL);
    assert_true(a->end == NULL);
    assert_true(a->size == 0);
  } else {
    printf("Something went wrong in queue_correct_constructor_behavior_test");
    queue_destructor(a);
    exit(getchar());
  }
  queue_destructor(a);
}

#if defined(_MSC_VER)
    static void queue_incorrect_constructor_behavior_test() {
      queue(int)* a = NULL;
      queue_constructor(int, a);
      if (return_val_from_macro == 0) {
        queue_constructor(int, a);
        if (return_val_from_macro == -1) {
          FILE* file = fopen("error_logs.txt", "r");
          char buff[255];
          char* line = fgets(buff, 255, file);
          fclose(file);
          assert_true(line != NULL);
          file = fopen("error_logs.txt", "w");
          fprintf(file, "");
          fclose(file);
        } else {
          printf(
              "Something went wrong in queue_incorrect_constructor_behavior_test");
          queue_destructor(a);
          exit(getchar());
        }
      } else {
        printf("Something went wrong in queue_incorrect_constructor_behavior_test");
        queue_destructor(a);
        exit(getchar());
      }
      queue_destructor(a);
    }
#endif

static void queue_correct_destructor_behavior_test() {
#if defined(_MSC_VER)
  queue(int)* a = NULL;
  queue_constructor(int, a);
#elif defined (__GNUC__)
    queue(int)* a = queue_constructor(int);
#endif
  if (return_val_from_macro == 0) {
    assert_true(a != NULL);
    queue_destructor(a);
    if (return_val_from_macro == 0) {
      assert_int_not_equal(a->size, 0);
    } else {
      printf("Something went wrong in queue_correct_destructor_behavior_test");
      queue_destructor(a);
      exit(getchar());
    }
  } else {
    printf("Something went wrong in queue_correct_destructor_behavior_test");
    queue_destructor(a);
    exit(getchar());
  }
}

static void queue_incorrect_destructor_behavior_test() {
  queue(int)* a = NULL;
  queue_destructor(a);
  if (return_val_from_macro == -1) {
    FILE* file = fopen("error_logs.txt", "r");
    char buff[255];
    char* line = fgets(buff, 255, file);
    fclose(file);
    assert_true(line != NULL);
    file = fopen("error_logs.txt", "w");
    fprintf(file, "");
    fclose(file);
  } else {
    printf("Something went wrong in queue_incorrect_destructor_behavior_test");
    exit(getchar());
  }
}

int main(void) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(queue_correct_constructor_behavior_test),
#if defined(_MSC_VER)
      cmocka_unit_test(queue_incorrect_constructor_behavior_test),
#endif
      cmocka_unit_test(queue_correct_destructor_behavior_test),
      cmocka_unit_test(queue_incorrect_destructor_behavior_test),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
