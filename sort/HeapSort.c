/**
 * @file HeapSort.c
 * @Brief  Deap sorting algorithm implementation
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-14
 */

#include <stdio.h>
#include "Sort.h"

#define NO_EXCHANGE    0
#define LEFT_EXCHANGE  1
#define RIGHT_EXCHANGE 2


/* --------------------------------------------------------------------------*/
/**
 * @Brief  sift Swap a smallest complete binary tree
 *
 * @Param root Root of the tree
 * @Param left Left leaf
 * @Param right Right leaf
 *
 * @Returns   
 */
/* ----------------------------------------------------------------------------*/
static int sift(DATA_TYPE *root, DATA_TYPE *left, DATA_TYPE *right)
{
    DATA_TYPE temp = 0;

    /**
     * if the root is the biggest, do nothing;
     * or compare left and right, decide how to exchange
     */ 
    if (*root > *left && *root > *right)
	return NO_EXCHANGE;
    else {
	temp = *root;
	if (*left > *right){
	    *root = *left;
	    *left = temp;
	    return LEFT_EXCHANGE;
	} else {
	    *root = *right;
	    *right = temp;
	    return RIGHT_EXCHANGE;
	}
    }
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  heap_down From the given root, sift the tree
 *
 * @Param array[] Array address
 * @Param start The given root
 * @Param array_size
 *
 * @Returns   0 is OK
 */
/* ----------------------------------------------------------------------------*/
static int heap_down(DATA_TYPE array[], int start, int array_size)
{
    int root = start;
    int left = 2*root + 1;
    int right = 2*root + 2;

    /**
     * if the root is leaf or the last non-leaf that has no right child, exit while
     */ 
    while (right < array_size){
	int choice = sift(&array[root], &array[left], &array[right]);
	switch(choice){
	    case NO_EXCHANGE:
		return 0;
	    case LEFT_EXCHANGE:
		root = left;
		break;
	    case RIGHT_EXCHANGE:
		root = right;
		break;
	}
	left = 2*root + 1;
	right = 2*root + 2;
    }

    /*
     * the root is the last non-leaf, but has no right child
     */ 
    if (left < array_size){
	if (array[root] < array[left]){
	    DATA_TYPE temp = array[root];
	    array[root] = array[left];
	    array[left] = temp;
	}
    }

    return 0;
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  heapify Build a big-endin heap
 *
 * @Param array[] Array address
 * @Param array_size
 */
/* ----------------------------------------------------------------------------*/
static void heapify(DATA_TYPE array[], int array_size)
{
    /**
     * get the last non-leaf node
     */ 
    int root = (array_size - array_size%2) / 2 - 1;

    int left = 2*root + 1;
    int right = 2*root + 2;

    /**
     * the last non-leaf node has no right child, handle it firstly
     */ 
    if (right > array_size-1){
	if (array[root] < array[left]){
	    DATA_TYPE temp = array[root];
	    array[root] = array[left];
	    array[left] = temp;
	}
	root--;
    }

    /**
     * iterate all the non-leaf node
     */ 
    for (; root >= 0; root--){
	left = 2*root + 1;
	right = 2*root + 2;

	int choice = sift(&array[root], &array[left], &array[right]);
	switch (choice){
	    case NO_EXCHANGE:
		continue;
	    case LEFT_EXCHANGE:
		if (2*left+1 > array_size-1)
		    continue;
		else
		    heap_down(array, left, array_size);
		break;
	    case RIGHT_EXCHANGE:
		if (2*right+1 > array_size-1)
		    continue;
		else
		    heap_down(array, right, array_size);
		break;
	}
    }
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  heap_sort User's interface
 *
 * @Param array[] Array address
 * @Param array_size
 *
 * @Returns  0 is OK; -1 is failed 
 */
/* ----------------------------------------------------------------------------*/
int heap_sort(DATA_TYPE array[], int array_size)
{
    if (array == 0)
	return -1;

    /**
     * only have two element
     */ 
    if (array_size < 3){
	DATA_TYPE temp = array[0];
	if (array[0] < array[1])
	    return 0;
	array[0] = array[1];
	array[1] = temp;
    }

    /**
     * build a big-endin heap
     */ 
    heapify(array, array_size);

    /**
     * iterate the array, put the biggest in the rear
     * index means the current array's size
     */ 
    int index = array_size - 1;
    for (; index > 2; index--){
	DATA_TYPE temp = array[index];
	array[index] = array[0];
	array[0] = temp;

	int choice = sift(&array[0], &array[1], &array[2]);
	switch (choice){
	    case NO_EXCHANGE:
		continue;
	    case LEFT_EXCHANGE:
		heap_down(array, 1, index);
		break;
	    case RIGHT_EXCHANGE:
		heap_down(array, 2, index);
		break;
	}
    }

    DATA_TYPE temp = array[0];
    if (array[1] > array[2]){
	array[0] = array[2];
    } else {
	array[0] = array[1];
	array[1] = array[2];
    }
    array[2] = temp;

    return 0;
}


