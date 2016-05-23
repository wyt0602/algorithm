/**
 * @file Queue.c
 * @Brief  Queue implementation
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-05-23
 */

#include <stdlib.h>
#include "Queue.h"

#define IS_EMPTY(queue) ((queue)->size == 0) 

static bool copy_stack(Stack *to, Stack *from)
{
    if (!(to && from))
	return false;

    STACK_DATA_TYPE result;
    while (!from->is_empty(from)){
	from->pop(from, &result);
	to->push(to, result);
    }

    return true;
}

static bool in(Queue *queue, STACK_DATA_TYPE item)
{
    if (queue == NULL)
	return false;

    bool ret = queue->in_stack->push(queue->in_stack, item);
    if (ret == false)
	return false;
    queue->size++;

    return true;
}

static bool out(Queue *queue, STACK_DATA_TYPE *result)
{
    if (!(queue && result))
	return false;

    if (IS_EMPTY(queue))
	return false;

    if (queue->out_stack->is_empty(queue->out_stack))
	copy_stack(queue->out_stack, queue->in_stack);

    if (queue->out_stack->pop(queue->out_stack, result) == false)
	return false;

    queue->size--;
    return true;
}

static bool is_empty(Queue *queue)
{
    if (queue == NULL)
	return false;

    return (IS_EMPTY(queue));
}

bool queue_init(Queue *queue)
{
    if (queue == NULL)
	return false;

    queue->in_stack = (Stack*)malloc(sizeof(Stack));
    queue->out_stack = (Stack*)malloc(sizeof(Stack));

    if (!(queue->in_stack && queue->out_stack))
	return false;

    if (stack_init(queue->in_stack) == false)
	return false;
    if (stack_init(queue->out_stack) == false)
	return false;

    queue->size = 0;
    queue->in = in;
    queue->out = out;
    queue->is_empty = is_empty;

    return true;
}

void queue_delete(Queue *queue)
{
    if (queue == NULL)
	return;

    stack_delete(queue->in_stack);
    stack_delete(queue->out_stack);

    free(queue->in_stack);
    free(queue->out_stack);
}

