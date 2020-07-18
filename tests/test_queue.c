#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "premain.h"
#include "queue.h"

#if defined(_MSC_VER)
static void queue_correct_constructor_behavior_test() {
  queue(int)* a = NULL;
  queue_constructor(int, a);
#elif defined(__GNUC__)
static void queue_correct_constructor_behavior_test(void** state) {
  queue(int)* a = queue_constructor(int);
#endif
  if (return_val_from_macro != NULL) {
    assert_true(a != NULL);
    assert_true(a->begin == NULL);
    assert_true(a->end == NULL);
    assert_true(a->size == 0);
  } else {
    printf("Something went wrong in queue_correct_constructor_behavior_test");
    queue_destructor(a);
    exit(-1);
  }
  queue_destructor(a);
}

#if defined(_MSC_VER)
static void queue_incorrect_constructor_behavior_test() {
  queue(int)* a = NULL;
  queue_constructor(int, a);
  if (return_val_from_macro != NULL) {
    queue_constructor(int, a);
    if (return_val_from_macro == NULL) {
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
      exit(-1);
    }
  } else {
    printf("Something went wrong in queue_incorrect_constructor_behavior_test");
    queue_destructor(a);
    exit(-1);
  }
  queue_destructor(a);
}
#endif

#if defined(_MSC_VER)
static void queue_correct_destructor_behavior_test() {
  queue(int)* a = NULL;
  queue_constructor(int, a);
#elif defined(__GNUC__)
static void queue_correct_destructor_behavior_test(void** state) {
  queue(int)* a = queue_constructor(int);
#endif
  if (return_val_from_macro != NULL) {
    assert_true(a != NULL);
    queue_destructor(a);
    if (return_val_from_macro != NULL) {
      assert_null(a);
    } else {
      printf("Something went wrong in queue_correct_destructor_behavior_test");
      queue_destructor(a);
      exit(-1);
    }
  } else {
    printf("Something went wrong in queue_correct_destructor_behavior_test");
    queue_destructor(a);
    exit(-1);
  }
}

#if defined(_MSC_VER)
static void queue_incorrect_destructor_behavior_test() {
#elif defined(__GNUC__)
static void queue_incorrect_destructor_behavior_test(void** state) {
#endif
  queue(int)* a = NULL;
  queue_destructor(a);
  if (return_val_from_macro == NULL) {
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
    exit(-1);
  }
}

#if defined(_MSC_VER)
static void queue_correct_dequeue_behavior_test() {
  queue(int)* a = NULL;
  queue_constructor(int, a);
#elif defined(__GNUC__)
static void queue_correct_dequeue_behavior_test(void** state) {
  queue(int)* a = queue_constructor(int);
#endif
  queue_enqueue(a, 1);
  queue_enqueue(a, 2);
  if (return_val_from_macro != NULL) {
    int popped_val = queue_dequeue(a);
    if (return_val_from_macro != NULL) {
      assert_int_equal(popped_val, 1);
      assert_int_equal((int)return_val_from_macro, 1);
      queue_destructor(a);
    } else {
      printf("Something went wrong in queue_correct_dequeue_behavior_test");
      queue_destructor(a);
      exit(-1);
    }
  } else {
    printf("Something went wrong in queue_correct_dequeue_behavior_test");
    queue_destructor(a);
    exit(-1);
  }
}

#if defined(_MSC_VER)
static void queue_incorrect_dequeue_behavior_test() {
  queue(int)* a = NULL;
  queue_constructor(int, a);
#elif defined(__GNUC__)
static void queue_incorrect_dequeue_behavior_test(void** state) {
  queue(int)* a = queue_constructor(int);
#endif
  // The test when a queue exists however first element is missing
  queue_dequeue(a);
  if (return_val_from_macro == NULL) {
    FILE* file = fopen("error_logs.txt", "r");
    char buff[255];
    char* line = fgets(buff, 255, file);
    fclose(file);
    assert_true(line != NULL);
    file = fopen("error_logs.txt", "w");
    fprintf(file, "");
    fclose(file);
  } else {
    printf("Something went wrong in queue_correct_dequeue_behavior_test");
    queue_destructor(a);
    exit(-1);
  }

  // The test when a queue is avoided
  a = NULL;
  queue_dequeue(a);
  if (return_val_from_macro == NULL) {
    FILE* file = fopen("error_logs.txt", "r");
    char buff[255];
    char* line = fgets(buff, 255, file);
    fclose(file);
    assert_true(line != NULL);
    file = fopen("error_logs.txt", "w");
    fprintf(file, "");
    fclose(file);
  } else {
    printf("Something went wrong in queue_correct_dequeue_behavior_test");
    queue_destructor(a);
    exit(-1);
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
    cmocka_unit_test(queue_correct_dequeue_behavior_test),
    cmocka_unit_test(queue_incorrect_dequeue_behavior_test),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
