/**
 * @file GetList.c
 * @Brief  Get a list
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-05-12
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "GetList.h"

static int mod = 0;

static LinkedNode* unique(int size)
{
    if (mod < size)
	mod = size;

    char *flag = malloc(mod);
    if (flag == NULL)
	return NULL;
    memset(flag, 0, mod);

    LinkedNode *head = NULL;
    LinkedNode *rear = NULL;

    int i = 0;
    while (i < size){
	int temp = random()%mod;
	if (flag[temp] == 1)
	    continue;
	LinkedNode *node = (LinkedNode*)malloc(sizeof(LinkedNode));
	if (node == NULL){
	    printf("malloc error!\n");
	    return NULL;
	}
	node->visit = 0;
	node->value = temp;
	node->next = NULL;

	if (rear != NULL)
	    rear->next = node;
	else
	    head = node;
	rear = node;
	flag[temp] = 1;
	i++;
    }

    return head;
}

static LinkedNode* non_unique(int size)
{
    LinkedNode *head = NULL;
    LinkedNode *rear = NULL;

    int i = 0;
    while (i < size){
	int temp = random()%mod;

	LinkedNode *node = (LinkedNode*)malloc(sizeof(LinkedNode));
	if (node == NULL){
	    printf("malloc error!\n");
	    return NULL;
	}
	node->visit = 0;
	node->value = temp;
	node->next = NULL;

	if (rear != NULL)
	    rear->next = node;
	else
	    head = node;
	rear = node;

	i++;
    }

    return head;
}

static LinkedNode* loop(int size, LIST_TYPE type)
{
    int loop_start = random()%size;

    LinkedNode *list = NULL;

    if (type == LOOP)
	list = unique(size);

    if (list == NULL)
	return NULL;

    int i = 0;
    LinkedNode *loop_node = NULL;
    LinkedNode *temp = list;
    LinkedNode *pre = NULL;

    while (temp){
	if (i == loop_start)
	    loop_node = temp;
	i++;
	pre = temp;
	temp = temp->next;
    }

    printf("loop_start:%d->%d\n", loop_start+1, loop_node->value);
    pre->next = loop_node;

    return list;
}

LinkedNode* get_list(int size, int scale, LIST_TYPE type)
{
    if (size <= 0)
	return NULL;

    if (scale <= 0)
	mod = size;
    mod = scale;

    LinkedNode *list = NULL;

    if (type == SORTED_UNIQUE){
	list = unique(size);
	list = merge_sort(list);
    } else if (type == SORTED_NON_UNIQUE){
	list = non_unique(size);
	list = merge_sort(list);
    } else if (type == UNIQUE_NON_SORTED)
	list = unique(size);
    else if (type == NON_UNIQUE_NON_SORTED)
	list = non_unique(size);
    else if (type == LOOP)
	list = loop(size, type);
    else
	return NULL;

    return list;
}

void print_list(LinkedNode *list)
{
    if (list == NULL)
	return;

    int count = 0;

    while (list){
	if (list->visit == 2)
	    break;

	if (count%6 == 0 && count != 0)
	    printf("\n");
	printf("%8d", list->value);
	list->visit++;
	list = list->next;
	count++;
    }
    printf("\n");
}

/*
   int main()
   {
   LinkedNode *list1 = get_list(66, SORTED_UNIQUE);
   LinkedNode *list2 = get_list(66, SORTED_NON_UNIQUE);

   while (list1){
   printf("%d ", list1->value);
   list1 = list1->next;
   }

   printf("\n");

   while (list2){
   printf("%d ", list2->value);
   list2 = list2->next;
   }
   printf("\n");

   return 0;
   }
   */
