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

#define SCALE 5

static LinkedNode* unique(int size)
{
    int mod = SCALE * size;
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
    int mod = size;
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

LinkedNode* get_list(int size, LIST_TYPE type)
{
    if (size <= 0)
	return NULL;

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
    else
	return NULL;

    return list;
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
}*/
