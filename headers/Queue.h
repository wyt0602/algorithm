/**
 * @file Queue.h
 * @Brief  Queue interface
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-05-23
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Stack.h"

typedef struct Queue{
    int size;
    Stack *in_stack;
    Stack *out_stack;
    bool (*in)(struct Queue *queue, STACK_DATA_TYPE item);
    bool (*out)(struct Queue *queue, STACK_DATA_TYPE *result);
    bool (*is_empty)(struct Queue *queue);
}Queue;

bool queue_init(Queue *queue);
void queue_delete(Queue *queue);

#endif
