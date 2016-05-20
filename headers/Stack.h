/**
 * @file Stack.h
 * @Brief  Stack interface
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-05-20
 */

#ifndef STACK_H_
#define STACK_H_

typedef void* STACK_DATA_TYPE;

typedef enum{
    false = 0,
    true
}bool;

typedef struct Block{
    unsigned int size;
    unsigned int top;
    struct Block *next;
    STACK_DATA_TYPE *start;
}Block;

typedef struct MinNode{
    STACK_DATA_TYPE value;
    struct MinNode *next;
}MinNode;

typedef struct Stack{
    Block *origin_block; //point to the first block
    MinNode *min_list;
    Block *block_list;

    //stack handle begin
    bool (*push)(struct Stack *stack, STACK_DATA_TYPE item);
    bool (*pop)(struct Stack *stack, STACK_DATA_TYPE *result);
    bool (*peek)(struct Stack *stack, STACK_DATA_TYPE *result);
    bool (*min)(struct Stack *stack, STACK_DATA_TYPE *result);
    bool (*is_empty)(struct Stack *stack);
    //stack handle end
}Stack;

void stack_init(Stack *stack);

#endif
