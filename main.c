#include "./includes/stack.h"
#include <vld.h>
/*#include <stdio.h>
#include <stdlib.h>


#ifdef __cplusplus
    #define INITIALIZER(f) \
        static void f(void); \
        struct f##_t_ { f##_t_(void) { f(); } }; static f##_t_ f##_; \
        static void f(void)
#elif defined(_MSC_VER)
    #pragma section(".CRT$XCU",read)
    #define INITIALIZER2_(f,p) \
        static void f(void); \
        __declspec(allocate(".CRT$XCU")) void (*f##_)(void) = f; \
        __pragma(comment(linker,"/include:" p #f "_")) \
        static void f(void)
    #ifdef _WIN64
        #define INITIALIZER(f) INITIALIZER2_(f,"")
    #else
        #define INITIALIZER(f) INITIALIZER2_(f,"_")
    #endif
#else
    #define INITIALIZER(f) \
        static void f(void) __attribute__((constructor)); \
        static void f(void)
#endif

static void finalize(int a)
{
    printf( "finalize\n");
}

INITIALIZER(initialize)
{
    printf( "initialize\n");
    atexit( finalize);
}

int main( int argc, char** argv)
{
    return 0;
}*/

int main() {
  stack(int)* a = NULL;
  stack_constructor(int, a);
  stack_push(a, 7);
  stack_push(a, 6);
  printf("%d", stack_pop(a));
  printf("%d", stack_pop(a));
  stack_destructor(a);
  return (0);
}
