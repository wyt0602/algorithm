/***********************************************
 * 题目：
 * 给定两个用链表表示的整数，每个节点包含一个数位。
 * 这些数位是反向存放的，也就是个位排在链表的首部。
 * 编写函数对这两个整数求和，并用链表的形式返回结果。
 * 示例：
 * 输入：(7->1->6)+(5->9->2)，即617+295
 * 输出：2->1->9，即912
 *
 * 进阶：假如这些数位是正向存放的，请再做一遍。
 * 输入：(6->1->7)+(2->9->5)，即617+295
 * 输出：9->1->2，即912
 *
 * 分析：（1）依次遍历两个链表，对应相加，记录进位
 * 	 （2）注意链表不一样长时的处理
 * 	 （3）一定要处理最后一次进位
 *
 * 进阶分析：
 * （1）将链表反向
 * （2）进行上面的处理
 *
 ***********************************************/ 

#include <stdio.h>
#include <stdlib.h>

#include "GetList.h"

int check(int value1, int value2, int *cin)
{
    int temp = value1 + value2 + (*cin);
    *cin = 0;

    if (temp >= 10){
	*cin = 1;
	return temp%10;
    } else
	return temp;
}

void insert_node(LinkedNode **head,
		 LinkedNode **rear,
		 LinkedNode *node)
{
    if (*rear != NULL)
	(*rear)->next = node;
    else
	*head = node;
    *rear = node;
}

void deal_single_list(LinkedNode **head,
		      LinkedNode **rear,
	              LinkedNode **list,
	              int *cin)
{
    if (*cin == 0){
	insert_node(head, rear, *list);
	while ((*rear)->next)
	    *rear = (*rear)->next;
	*list = NULL;
    } else {
	(*list)->value = check((*list)->value, 0, cin);
	insert_node(head, rear, *list);
	*list = (*list)->next;
    }
}

LinkedNode* add(LinkedNode *list1, LinkedNode *list2)
{
    if (list1 == NULL && list2 == NULL)
	return NULL;
    else if (list1 == NULL)
	return list2;
    else if (list2 == NULL)
	return list1;

    LinkedNode *head = NULL;
    LinkedNode *rear = NULL;
    int cin = 0;
    LinkedNode *reserve = list2;

    while (1){
	if (list1 != NULL && list2 != NULL){
	    list1->value = check(list1->value, list2->value, &cin);
	    insert_node(&head, &rear, list1);
	    list1 = list1->next;
	    list2 = list2->next;
	} else if (list1 != NULL){
	    deal_single_list(&head, &rear, &list1, &cin);
	} else if (list2 != NULL){
	    deal_single_list(&head, &rear, &list2, &cin);
	} else {
	    if (cin != 0){
		reserve->value = cin;
		insert_node(&head, &rear, reserve);
	    }
	    rear->next = NULL;
	    break;
	}
    }

    return head;
}


int main()
{
    LinkedNode *list1 = get_list(14, 10, NON_UNIQUE_NON_SORTED); 
    LinkedNode *list2 = get_list(20, 10, NON_UNIQUE_NON_SORTED); 

    if (!(list1 && list2))
	return 0;

    printf("list1:\n");
    print_list(list1);
    printf("list2:\n");
    print_list(list2);

    LinkedNode *result = add(list1, list2);
    printf("result:\n");
    print_list(result);

    return 0;
}


















