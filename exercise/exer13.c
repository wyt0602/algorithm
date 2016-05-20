/**********************************************
 * 题目：
 * 编写一个函数，检查链表是否为回文。
 *
 * 分析：
 * （1）什么是回文，a->b->c->b->a 即回文
 * （2）思路：
 * <1>找到中间点，再进行对称判断。链表为单向链表
 *    就不好处理了，但可以用栈解决。
 * <2>如何找到中间节点：采用双指针操作。
 *
 **********************************************/ 

/***********************************************
 * b = back ; f = front
 *
 *(1)
 * EVEN:
 *-----   -----   -----   -----   -----   -----
 *| a |-->| b |-->| c |-->| c |-->| b |-->| a |-->NULL
 *-----   -----   -----   -----   -----   -----
 *^   ^   ^       ^   ^   ^           ^             ^ 
 *|   |   |       |   |   |           |             |
 *b0  f0  b1      b2  f1  b3          f2            f3 
 *
 *<1>if (f == NULL) means size is EVEN;
 *<2>put all node before b, but not include b;
 *<3>comparing starts from b
 *
 *(2)
 * ODD:
 *-----   -----   -----   -----   -----
 *| a |-->| b |-->| c |-->| b |-->| a |-->NULL
 *-----   -----   -----   -----   -----
 *^   ^   ^       ^   ^               ^
 *|   |   |       |   |               |
 *b0  f0  b1      b2  f1              f2
 *<1>if (f !== NULL) means size is ODD;
 *<2>put all node before b, but not include b;
 *<3>comparing starts from b->next
 *
 *(3)b step first; then f
 *  so in while must compare
 *  f != NULL && f->next != NULL
 *  then meets the condition:
 *  b moves first, then f
 *
 ***********************************************/ 

#include <stdio.h>
#include <stdlib.h>

#include "GetList.h"
#include "Stack.h"

bool is_palindrom(LinkedNode *list)
{
    if (list == NULL)
	return false;

    LinkedNode *front = list;
    LinkedNode *back = list;

    Stack stack; 
    stack_init(&stack);

    //important
    while (front != NULL && front->next != NULL){
	stack.push(&stack, back);
	back = back->next;
	front = front->next->next;
    }

    if (front != NULL)
	back = back->next;

    while (!stack.is_empty(&stack)){
	LinkedNode *temp;
	stack.pop(&stack,(void*)(&temp));
	if (temp->value != back->value){
	    return false;
	}
	back = back->next;
    }

    return true;
}


int main()
{
    LinkedNode *list1 = get_list(100, 500, UNIQUE_NON_SORTED);
    LinkedNode *list2 = get_list(100, 500, UNIQUE_NON_SORTED);

    if (!(list1 && list2))
	return 0;

    printf("list1:\n");
    print_list(list1);

    LinkedNode *head1 = list1;
    LinkedNode *head2 = list2;
    while (head1->next){
	head2->value = head1->value;
	head1 = head1->next;
	head2 = head2->next;
    }
    //head2->value = 1234;
    head2->value = head1->value;
    head2 = NULL;

    LinkedNode *node = (LinkedNode*)malloc(sizeof(LinkedNode));
    if (node == NULL)
	return 0;
    node->visit = 0;
    node->value = 7777;
    node->next = NULL;

    //make ODD list
    head1->next = node;
    head1 = head1->next;

    while (list2){
	LinkedNode *temp = list2;
	list2 = list2->next;
	temp->next = head2;
	head2 = temp;
    }
    head1->next = head2;
    printf("palindrom list1:\n");
    print_list(list1);

    if (is_palindrom(list1) == true)
	printf("is palindrom!\n");
    else
	printf("is not palindrom!\n");

    return 0;

}

