#include "premain.h"
#include "queue.h"

int main(void) {
    queue(int) *qu = NULL;
    queue_constructor(int, qu);
    queue_constructor(int, qu);
    if (return_val_from_macro == -1) {
        printf("Error has been occured! Check error_log.txt for more details.");
        return (getchar());
    }
    queue_enqueue(qu, 1);
    queue_enqueue(qu, 2);
    queue_enqueue(qu, 3);
    queue_enqueue(qu, 4);

    while (qu->begin) {
        printf("%d->", queue_dequeue(qu));
    }
    queue_destructor(qu);
}