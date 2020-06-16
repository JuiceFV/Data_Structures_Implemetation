#include "./includes/premain.h"
#include "./includes/queue.h"

int main(void) {
    queue(int) *qu = NULL;
    queue_constructor(int, qu);
    queue_enqueue(qu, 1);
    queue_enqueue(qu, 2);
    queue_enqueue(qu, 3);
    queue_enqueue(qu, 4);

    while (qu->begin) {
        printf("%d->", queue_dequeue(qu));
    }
    queue_destructor(qu);
}