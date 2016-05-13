/**
 * @file MergeSort_l.c
 * @Brief  Sort list by merge-srot method
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-05-13
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "GetList.h"


/* --------------------------------------------------------------------------*/
/**
 * @Brief  merge_list Sort two list
 *
 * @Param list1
 * @Param list2
 *
 * @Returns   The result list that is sorted
 */
/* ----------------------------------------------------------------------------*/
static LinkedNode* merge_list(LinkedNode *list1, LinkedNode *list2)
{
    if (list1 == NULL)
	return list2;
    else if (list2 == NULL)
	return list1;

    LinkedNode *head = NULL;
    LinkedNode *rear = NULL;

    /*
     * like merge-sort in array
     */ 
    while (1){
	if (list1 != NULL && (list2 == NULL || list1->value <= list2->value)){
	    /*
	     * insert a new node into the list;
	     * this is a skill, and memorize it
	     */ 
	    if (rear != NULL)
		rear->next = list1;
	    else
		head = list1;

	    rear = list1;
	    list1 = list1->next;
	} else if (list2 != NULL){
	    if (rear != NULL)
		rear->next = list2;
	    else
		head = list2;

	    rear = list2;
	    list2 = list2->next;
	} else
	    break;
    }

    rear->next = NULL;
    return head;
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  combine Combine all list in an array
 *
 * @Param array The list array
 *
 * @Returns   The result list that is sorted
 */
/* ----------------------------------------------------------------------------*/
static LinkedNode* combine(LinkedNode **array)
{
    LinkedNode *list1 = NULL;
    LinkedNode *list2 = NULL;

    int index = 0;
    int i = 0;

    while (1){
	/*
	 * this is one traversal for the array
	 *
	 */ 
	while (array[i]){
	    list1 = array[i];
	    array[i] = NULL;
	    i++;
	    if (array[i] == NULL){
		array[index] = list1;
		break;
	    }

	    list2 = array[i];
	    array[i] = NULL;
	    i++;

	    array[index] = merge_list(list1, list2);
	    index++;
	}

	if (index == 0)
	    return array[0];

	/*
	 * new traversal starts
	 */ 
	index = 0;
	i = 0;
    }
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  merge_sort Sort interface
 *
 * @Param list
 *
 * @Returns   The result list that is sorted
 */
/* ----------------------------------------------------------------------------*/
LinkedNode* merge_sort(LinkedNode *list)
{
    if (list == NULL)
	return NULL;

    LinkedNode *l = list;
    int size = 0;
    while (l){
	size++;
	l = l->next;
    }

    int array_size = size/2;
    array_size += size%2;   // flag = size%2 ; if flag = 0, even number; if flag = 1, odd number

    //error: array_size must be array_size + 1;
    LinkedNode **merge_array = (LinkedNode**)malloc((array_size+1)*sizeof(LinkedNode*));
    if (merge_array == NULL)
	return NULL;
    memset(merge_array, 0, array_size*sizeof(LinkedNode*));

    int index = 0;
    while (list){
	merge_array[index] = list;
	list = list->next;
	if (list == NULL)
	    break;

	if (merge_array[index]->value <= list->value){
	    merge_array[index]->next = list;
	    list = list->next;
	    merge_array[index]->next->next = NULL;
	} else {
	    LinkedNode *temp = list;
	    list = list->next;
	    temp->next = merge_array[index];
	    merge_array[index]->next = NULL;
	    merge_array[index] = temp;
	}
	index++;
    }

    return (combine(merge_array));
}

