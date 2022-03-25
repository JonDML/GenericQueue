#ifndef GENERIC_QUEUE_H
#define GENERIC_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>

#define GENERATE_QUEUE(TYPE) \
struct Node_##TYPE{ \
    TYPE value; \
    struct Node_##TYPE *next; \
}; \
\
typedef struct { \
    struct Node_##TYPE *front, *rear; \
    atomic_int size; \
}Queue_##TYPE;\
\
int Queue_push_##TYPE(Queue_##TYPE* q, TYPE val) \
{\
    if(NULL == q) return -1; \
    struct Node_##TYPE *tempNode = malloc(sizeof *tempNode); \
    if(NULL == tempNode) return -2; \
    tempNode->value = val; \
    tempNode->next = NULL; \
    if(NULL == q->rear) \
    {\
        q->front = q->rear = tempNode; \
        ++q->size; \
        return 0; \
    }\
    \
    q->rear->next = tempNode; \
    q->rear = tempNode; \
    ++q->size; \
    return 0; \
} \
\
int Queue_pop_##TYPE(Queue_##TYPE* q, TYPE* val) \
{\
    if(NULL == q) return -1;\
    if(NULL == q->front) return -3; \
    struct Node_##TYPE* tempNode = q->front; \
    q->front = q->front->next; \
    \
    if(NULL == q->front) q->rear = NULL; \
    if(NULL != val) *val = tempNode->value; \
    free(tempNode);\
    --q->size; \
    return 0; \
}\
\
Queue_##TYPE* create_queue_##TYPE() \
{\
    Queue_##TYPE* q = malloc(sizeof *q); \
    if(NULL == q) return NULL;\
    q->front = q->rear = NULL; \
    q->size = 0; \
    return q; \
}\
\
void clear_queue_##TYPE(Queue_##TYPE* q) \
{\
    while(NULL != q->front) Queue_pop_##TYPE(q, NULL);\
}\
\
int destroy_queue_##TYPE(Queue_##TYPE* q) \
{\
    if(NULL == q) return -1;\
    clear_queue_##TYPE(q);\
    free(q); \
    q = NULL; \
    return 0; \
}\
\
int Queue_size_##TYPE(Queue_##TYPE *q) \
{\
    if(NULL == q) return -1; \
    return q->size; \
}
#endif //GENERIC_QUEUE_H