/*
 * @file MergeSort.c
 * @Brief  merge sort implementation
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-22
 */

#include <stdlib.h>
#include "Sort.h"


/* --------------------------------------------------------------------------*/
/**
 * @Brief  split_sort Split sort
 *
 * @Param src The array needed to be sorted
 * @Param des The array that split sort
 * @Param array_size 
 * @Param width the width 
 *
 * @Returns  
 */
/* ----------------------------------------------------------------------------*/
static int split_sort(DATA_TYPE *src, DATA_TYPE *des, int array_size, int width)
{
    int l_start = 0;
    int r_start = width;
    int l_end = r_start;
    int r_end = r_start + width;
    int des_cur = 0;

    do {
	
	l_end = l_end > array_size ? array_size : l_end;
	r_end = r_end > array_size ? array_size : r_end;

	for (;;){
	    /*  
	     *  ***memorize that && and || calculate the first expression(the first "if")
	     *
	     * situation 1: (l_start >= l_end) is true
	     * left is empty, copy right to des
	     * 
	     * situation 2: (l_start < l_end) and (r_start >= r_end) are true
	     * right is empty, copy left to des
	     * 
	     * situation 3: (l_start < l_end) and (r_start < r_end) are true
	     * right and left are not empty, copy the lower to des;
	     * 1) (src[l_start] <= src[r_start]) is true
	     *   copy left to des
	     * 2) (src[l_start] <= src[r_start]) is false
	     *   copy right to des
	     * 
	     * situation 4: (l_start >= l_end) and (r_start >= r_end) are true
	     * right and left are empty, break for loop
	     *
	     */ 
	    if (l_start < l_end && (r_start >= r_end || src[l_start] <= src[r_start])){
		des[des_cur] = src[l_start];
		l_start++;
		des_cur++;
	    } else if (r_start < r_end){
		des[des_cur] = src[r_start];
		r_start++;
		des_cur++;
	    } else
		break;
	}

	/*
	 * width = 3;
	 *                            r_n_end   
	 *        l_end r_end l_n_end ^
	 *        ^     ^     ^      _|
	 *        |     |     |     |
	 * ---------------------------------
	 * |l| | |r| | |-| | |-| | | | | | |
	 * ---------------------------------
	 *              ^     ^
	 *              |     |
	 *              l_new r_new
	 */ 
	l_start = l_start + width;
	r_start = r_start + width;
	l_end = r_start;
	r_end = r_start + width;


    } while (des_cur < array_size);

    return 0;
}
/* --------------------------------------------------------------------------*/
/**
 * @Brief  merge_sort User's interface
 *
 * @Param array[] Array needed to be sorted
 * @Param array_size
 *
 * @Returns   0 is OK; -1 is failed
 */
/* ----------------------------------------------------------------------------*/
int merge_sort(DATA_TYPE array[], int array_size)
{
    if (array == NULL)
	return -1;

    if (array_size == 1)
	return 0;

    /*
     * alloc temporary extra memory;
     * src points to the data that needs to be sorted;
     * des points to the data that has been sorted;
     * at the begining, exchange the des and src, because in
     * the for loop, exchange the des and src at first
     */ 
    DATA_TYPE *src, *des, *temp;
    des = array;
    src = calloc(array_size, sizeof(DATA_TYPE));
    if (des == NULL)
	return -1;

    /*
     * width means splitting size
     */ 
    int width;
    for (width = 1; width < array_size; width = width*2){
	temp = src;
	src = des;
	des = temp;
	split_sort(src, des, array_size, width);
    }

    if (des == array){
	free(src);
	return 0;
    }
    
    int i;
    for (i = 0; i < array_size; ++i)
	array[i] = des[i];

    free(des);
    return 0;
}

