#include "./includes/stack.h"
#include "./includes/queue.h"
typedef char* string;
int main() {
    queue(string)* a = NULL;
    queue_constructor(string, a);
    queue_enqueue(a, "Daun");
    queue_enqueue(a, "Pizdec");
    queue_enqueue(a, "Ahahahaha");
    queue_enqueue(a, "Dolboeb");
    queue_enqueue(a, "Sanya");
    printf("%s ", queue_dequeue(a));
    printf("%s ", queue_dequeue(a));
    printf("%s ", queue_dequeue(a));
    printf("%s ", queue_dequeue(a));
    printf("%s ", queue_dequeue(a));
    queue_enqueue(a, "Sanya");
    queue_destructor(a);
    _CrtDumpMemoryLeaks();
  return (0);
}