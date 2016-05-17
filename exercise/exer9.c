/****************************************************
 * 题目：实现一个算法，找出单向链表中倒数第k个节点。
 *
 * 分析：
 * （1）常规方法：第一次遍历得出链表的长度，然后
 *      求出正向访问需要几次就行了，即size-k+1
 * （2）递归方法
 * （3）迭代法：即使用两个指针，先使得两个指针相距
 *      k个节点，然后再同时移动，最后慢的一个指针
 *      就指向目标节点。
 *
 * 双指针应用的总结：
 * （1）初始状态时，两个指针都指向链表的头部
 * （2）当一起运动时，落后的指针先动
 * 	<1>理解运动是同时发生的，就像两个人赛跑
 * 	<2>因此移动时，首先得判断的就是超前指针是否能够满足移动条件
 * （3）一定得画图分析清楚，到底超前多少，就像此题，
 * 	为什么是先移动k-1个：由于初始化时指向链表头已经
 * 	代表是一个了，所以需要在移动k-1个即可。
 * 	可以类比赛跑：
 * 	A从起点移动了k个；
 * 	B还在起点。
 *
 ****************************************************/ 

#include <stdio.h>
#include <stdlib.h>

#include "GetList.h"

LinkedNode *nth_to_last(LinkedNode *list, int k)
{
    if (k <= 0 || list == NULL)
	return NULL;

    LinkedNode *back = list;
    LinkedNode *front = list;

    int i;
    for (i = 0; i < k - 1; i++){
	front = front->next;
	if (front == NULL)
	    return NULL;
    }

    while (front->next){
	back = back->next;
	front = front->next;
    }

    return back;
}

int main()
{
    LinkedNode *list = get_list(13, 20, UNIQUE_NON_SORTED);
    if (list == NULL){
	printf("error:get_list()\n");
	return 0;
    }

    printf("list:\n");
    print_list(list);

    LinkedNode *temp = nth_to_last(list, 1);
    if (temp == NULL){
	printf("out of range!\n");
	return 0;
    }
    printf("result:%d\n", temp->value);

    return 0;
}
