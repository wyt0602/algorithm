/**************************************************
 * 题目：
 * 实现一个my_queue类，该类用两个栈来实现一个队列。
 *
 * 分析：为了减少移动，则用两个栈，一个栈用于入队列，
 * 另一个用于出队列，只有当出队列为空时，才将入队列
 * 的数据拷贝到出队列。
 *
 *************************************************/ 

#include <stdlib.h>
#include <stdio.h>

#include "Stack.h"
#include "GetList.h"
#include "Queue.h"

int main()
{
    STACK_DATA_TYPE result;
    Queue queue;
    bool ret = queue_init(&queue);
    if (ret == false)
	return 0;

    LinkedNode *list = get_list(30, 100, UNIQUE_NON_SORTED);
    if (list == NULL)
	return 0;

    printf("list1:\n");
    print_list(list);

    while (list){
	queue.in(&queue, (STACK_DATA_TYPE)(list->value));
	list = list->next;
    }
    queue.out(&queue, &result);
    printf("queue first:%u\n", (unsigned)result);

    list = get_list(12, 200, UNIQUE_NON_SORTED);
    if (list == NULL)
	return 0;
    printf("list2:\n");
    print_list(list);

    while (list){
	queue.in(&queue, (STACK_DATA_TYPE)(list->value));
	list = list->next;
    }

    int i = 0;
    printf("queue:\n");
    while (!queue.is_empty(&queue)){
	if (i%6 == 0 && i != 0)
	    printf("\n");
	queue.out(&queue, &result);
	printf("%8u", (unsigned)result);
	i++;
    }

    printf("\n");
    queue_delete(&queue);
    return true;
}
