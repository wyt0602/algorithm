/**
 * @file Stack.c
 * @Brief  Stack implementation
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-05-20
 */

#include <stdlib.h>
#include <string.h>
#include "Stack.h"

#define MIN
#define BLOCK_SIZE 64
#define IS_FULL(block) ((block)->top == (block)->size)
#define IS_EMPTY(block) ((block)->top == 0)


/* --------------------------------------------------------------------------*/
/**
 * @Brief  increase_block Add a new block to the block list
 *
 * @Param stack
 *
 * @Returns   true is OK
 */
/* ----------------------------------------------------------------------------*/

static bool increase_block(Stack *stack)
{
    Block *block = (Block*)malloc(sizeof(Block));
    if (block == NULL)
	return false;
    block->size = BLOCK_SIZE;
    block->top = 0;

    STACK_DATA_TYPE *mem = (STACK_DATA_TYPE*)malloc(sizeof(STACK_DATA_TYPE)*BLOCK_SIZE);
    if (mem == NULL){
	free(block);
	return false;
    }
    memset(mem, 0, sizeof(STACK_DATA_TYPE)*BLOCK_SIZE);
    block->start = mem;

    block->next = stack->block_list;
    stack->block_list = block;

    return true;
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  decrease_block  delete a empty block from the block list
 *
 * @Param stack
 */
/* ----------------------------------------------------------------------------*/
static void decrease_block(Stack *stack)
{
    Block *temp = stack->block_list;
    stack->block_list = temp->next;

    free(temp->start);
    free(temp);
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  insert_into_min_list Insert a min node into the min list
 *
 * @Param stack Stack handler
 * @Param item The item needed to be inserted
 *
 * @Returns   
 */
/* ----------------------------------------------------------------------------*/
static bool insert_into_min_list(Stack *stack, STACK_DATA_TYPE item)
{
    MinNode *node = NULL;

    if (stack->min_list == NULL){
	node = (MinNode*)malloc(sizeof(MinNode));
	if (node == NULL)
	    return false;
	node->value = item;
	node->next = NULL;
	stack->min_list = node;
    } else {
	if (item > stack->min_list->value)
	    return true;

	node = (MinNode*)malloc(sizeof(MinNode));
	if (node == NULL)
	    return false;
	node->value = item;
	node->next = stack->min_list;
	stack->min_list = node;
    }

    return true;
}

static void delete_from_min_list(Stack *stack)
{
    MinNode *temp = stack->min_list;
    stack->min_list = temp->next;
    free(temp);
}

static bool push(Stack *stack, STACK_DATA_TYPE item)
{
    if (stack == NULL)
	return false;

    /*
     * current block is full
     */ 
    if (IS_FULL(stack->block_list))
	if (increase_block(stack) == false)
	    return false;

    Block *block = stack->block_list;
    (block->start)[block->top++] = item;

#ifdef MIN
    if (insert_into_min_list(stack, item) == false)
	return false;
#endif

    return true;
}


static bool pop(Stack *stack, STACK_DATA_TYPE *result)
{
    if (stack == NULL)
	return false;

    Block *block = stack->block_list;

    if (IS_EMPTY(block))
	return false;

    *result = (block->start)[--block->top];

#ifdef MIN
    if (*result == stack->min_list->value)
	delete_from_min_list(stack);
#endif

    if (IS_EMPTY(block) && stack->origin_block != block)
	decrease_block(stack);

    return true;
}

static bool peek(Stack *stack, STACK_DATA_TYPE *result)
{
    if (stack == NULL)
	return false;

    Block *block = stack->block_list;
    if (IS_EMPTY(block))
	return false;

    *result = (block->start)[block->top - 1];

    return true;
}

static bool min(Stack *stack, STACK_DATA_TYPE *result)
{
    if (stack == NULL)
	return false;

    if (stack->min_list == NULL)
	return false;

    *result = stack->min_list->value;

    return true;
}

static bool is_empty(Stack *stack)
{
    if (stack == NULL)
	return true;

    Block *block = stack->block_list;
    if (IS_EMPTY(block))
	return true;

    return false;
}

bool stack_init(Stack *stack)
{
    if (stack == NULL)
	return false;

    if (increase_block(stack) == false)
	return false;

    stack->origin_block = stack->block_list;
    stack->min_list = NULL;
    stack->push = push;
    stack->pop = pop;
    stack->peek = peek;
    stack->min = min;
    stack->is_empty = is_empty;

    return true;
}

void stack_delete(Stack *stack)
{
    if (stack == NULL)
	return;
    decrease_block(stack);
}
