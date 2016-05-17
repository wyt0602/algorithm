/**********************************************
 * 题目：
 * 编写代码，以给定值x为基准将链表分割成两部分，
 * 所有小于x的节点排在大于或等于x的节点之前。
 *
 * 分析：
 * （1）分两个链表统计，在合并
 * （2）技巧：一个在尾部插入，一个在头部插入；
 * 	需要记录头节点，可以通用的一段代码。
 *
 **********************************************/ 

#include <stdlib.h>
#include <stdio.h>

#include "GetList.h"

LinkedNode* patition(LinkedNode *list, int x)
{
    if (list == NULL)
	return NULL;

    LinkedNode *less = NULL;
    LinkedNode *larger = NULL;
    LinkedNode *start = NULL;

    while (list){
	if (list->value < x){
	    if (less != NULL)
		less->next = list;
	    else
		start = list;
	    less = list;
	    list = list->next;
	} else {
	    LinkedNode *temp = list;
	    list = list->next;
	    temp->next = larger;
	    larger = temp;
	}
    }

    if (less == NULL)
	return larger;
    less->next = larger;

    return start;
}

int main()
{
    LinkedNode *list = get_list(60, 1000, UNIQUE_NON_SORTED);
    if (list == NULL){
	printf("error:get_list()\n");
	return 0;
    }

    printf("old list:\n");
    print_list(list);

    list = patition(list, 200);
    printf("new list:\n");
    print_list(list);

    return 0;
}
