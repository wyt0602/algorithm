/*******************************************************
 * 题目：
 * 请设计一个栈，除了pop与push方法，还支持min方法，可返回
 * 栈元素中的最小值。push,pop和min三个方法的时间复杂度必须
 * 为O(1)。（结合可扩展栈一起设计，合理设计数据结构）
 *
 * 分析：
 * （1）得到最小，只需要每次push的时候做一次判断就行了
 * （2）问题：若min出栈了，该怎么办呢？
 * （3）记录先前的最小值，那么就可以实现了
 * （4）这样就得有多余的空间来记录这种状态
 * （5）有一种特殊情况得考虑，元素有相等的情况怎么办？
 * 	都记录（相邻时才会出现）
 *
 *******************************************************/ 

#include <stdio.h>

#include "Stack.h"
#include "GetList.h"

int main()
{
    Stack stack;
    stack_init(&stack);

    LinkedNode *list = get_list(23, 100, UNIQUE_NON_SORTED);
    if (list == NULL)
	return 0;
    print_list(list);

    // test empty stack
    void *result;
    if (stack.pop(&stack, &result) == false)
	printf("empty test\n");

    while (list){
	stack.push(&stack, (void*)(list->value));
	list = list->next;
    }

    stack.min(&stack, &result);
    printf("%d\n", result);

    int i;
    for (i=0; i<20; i++)
	stack.pop(&stack, &result);

    stack.min(&stack, &result);
    printf("%d\n", result);

    MinNode *node = stack.min_list;
    while (node){
	printf("%8d", (int)(node->value));
	node = node->next;
    }
    printf("\n");

    return 0;
}
