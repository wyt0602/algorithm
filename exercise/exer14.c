/**************************************************
 * 题目：
 * 给定一个有环链表，实现一个算法返回环路的开头节点。
 * 有环链表的定义：在链表中某个节点的next元素指向在
 * 它前面出现过的节点，则表明该链表存在环路。
 * 示例：
 * 输入：A->B->C->D->E->C (C节点出现了两次)
 * 输出：C
 *
 * 分析：
 * （1）首先需要知道存在环路，因此就是是经典的判断
 * 	链表是否存在环的问题。->用双指针就可以解决。
 *
 * （2）下面将给出一种巧妙的解法：
 *
 * <1>存在两个指针slow和fast
 * <2>假设链表的非环部分长度为k
 * <3>slow前进一步，fast将前进两步
 * <4>slow前进k步到达环的开始节点，那么fast前进了2k步
 * <5>那么fast将快了slow有k步
 * <6>由于是在环上，因此fast和slow相距其实是d=k%LOOP_SIZE
 * <7>则fast去追slow而相距则为D=LOOP_SIZE-d
 * <8>当slow前进D, fast前进2D，则此时它们相遇
 * <9>此时，fast距离环的开头节点为LOOP_SIZE-D，即d
 * <10>也就是说fast距离环头k%LOOP_SIZE
 * <11>从链表开头距离环头为k，这可知当有两个指针同时运动时
 * 将会相遇，那么这时就是环头。
 *
 **************************************************/ 

#include <stdlib.h>
#include <stdio.h>

#include "GetList.h"

LinkedNode* find_beginning(LinkedNode *list)
{
    LinkedNode *fast = list;
    LinkedNode *slow = list;

    while (fast != NULL && fast->next != NULL){
	slow = slow->next;
	fast = fast->next->next;

	if (slow == fast)
	    break;
    }

    if (fast == NULL || fast->next == NULL)
	return NULL;

    while (list != fast){
	list = list->next;
	fast = fast->next;
    }

    return fast;
}

int main()
{
    LinkedNode *list = get_list(23, 100, LOOP);
    if (list == NULL)
	return 0;

    printf("list:\n");
    print_list(list);

    list = find_beginning(list);
    if (list == NULL)
	return 0;
    printf("beginning:%d\n", list->value);

    return 0;
}
