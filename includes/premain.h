/*
This file responsible for demeanor before and after main performance.
*/
#ifndef _PREMAIN_H
#define _PREMAIN_H

#include "common.h"
#include "error.h"

// https://stackoverflow.com/questions/1113409/attribute-constructor-equivalent-in-vc/2390626
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

static void finalize(void)
{
    printf("finalize\n");
}

INITIALIZER(initialize)
{
    FILE* file;
    char buff[255];
    int i = 0;
    int number_of_error_line = 0;
    char* line;
    char* token;
    file = fopen("error_logs.txt", "w");
    fprintf(file, "");
    fclose(file);

    file = fopen(PATH_TO_QUEUE_H, "r");
    while (line = fgets(buff, 255, file))
    {
        number_of_error_line++;
        token = strtok(line, " ");
        while (token != NULL)
        {
            if (strcmp("anticipated_error", token) == 0)
                queue_error_lines[i++] = number_of_error_line;
            token = strtok(NULL, " ");
        }
    }
    fclose(file);
    number_of_error_line = 0;
    i = 0;
    file = fopen(PATH_TO_STACK_H, "r");
    while (line = fgets(buff, 255, file))
    {
        number_of_error_line++;
        token = strtok(line, " ");
        while (token != NULL)
        {
            if (strcmp("anticipated_error", token) == 0)
                stack_error_lines[i++] = number_of_error_line;
            token = strtok(NULL, " ");
        }
    }
    fclose(file);
    atexit(finalize);
}

#endif