/**
 * @file QuickSort.c
 * @Brief  Quicksort implementation
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-18
 */

#include "Sort.h"


/* --------------------------------------------------------------------------*/
/**
 * @Brief  partition Partition a array
 *
 * @Param array[] Array
 * @Param low Start address
 * @Param high End address
 *
 * @Returns   The pivot's index
 */
/* ----------------------------------------------------------------------------*/
static int partition(DATA_TYPE array[], int low, int high)
{
    DATA_TYPE pivot = array[low];
    int i = low;
    int j = high - 1;

    while (1){
	/**
	 * i is remained; j goes ahead.
	 * when exit the top while loop;
	 * there are two situations:
	 * 1. j = i
	 * 2. j = i-1
	 * -------------------
	 * | | | | |i| | | | |
	 * -------------------
	 *        \ /
	 *         j 
	 * so return i;
	 */ 
	do {
	    --j;
	}while (array[j] > pivot);
	if (i >= j){
	    array[i] = pivot;
	    return i;
	}
	array[i] = array[j];

	/**
	 * j is remained; i takes backward.
	 * when exit the top while loop;
	 * there are two situations:
	 * 1. i = j
	 * 2. i = j+1
	 * -------------------
	 * | | | |j| | | | | |
	 * -------------------
	 *        \ /
	 *         i 
	 * so return j;
	 */ 
	do {
	    ++i;
	}while (array[i] < pivot);
	if (i >= j){
	    array[j] = pivot;
	    return j;
	}
	array[j] = array[i];
    }
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  quick_recursion Quick sort recursive
 *
 * @Param array[] Array that needs to be sroted
 * @Param low The start address
 * @Param high The end address
 */
/* ----------------------------------------------------------------------------*/
static void quick_recursion(DATA_TYPE array[], int low, int high)
{
    if (low < high){
	int middle = partition(array, low, high);
	quick_recursion(array, low, middle-1);
	quick_recursion(array, middle+1, high);
    }
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  quick_sort Quick sort interface
 *
 * @Param array[] Array
 * @Param array_size 
 *
 * @Returns   0 is OK; -1 is failed
 */
/* ----------------------------------------------------------------------------*/
int quick_sort(DATA_TYPE array[], int array_size)
{
    if (array == 0)
	return -1;

    quick_recursion(array, 0, array_size-1);

    return 0;
}
