#include "genericqueue.h"

int main()
{
    GENERATE_QUEUE(int)
    
    Queue_int *queue = NULL;
    queue = create_queue_int();
    Queue_push_int(queue, 5);
    Queue_push_int(queue, 7);
    printf("Queue size: %d\n", Queue_size_int(queue));
    clear_queue_int(queue);
    printf("Clear Queue size: %d\n", Queue_size_int(queue));
    Queue_push_int(queue, 5);
    Queue_push_int(queue, 7);
    Queue_push_int(queue, 5);
    Queue_push_int(queue, 7);
    int num;
    Queue_pop_int(queue, &num);
    printf("First number: %d. Queue size: %d\n", num, Queue_size_int(queue));
    Queue_pop_int(queue, &num);
    printf("Second number: %d. Queue size: %d\n", num, Queue_size_int(queue));
    destroy_queue_int(queue);
    return 0;
}