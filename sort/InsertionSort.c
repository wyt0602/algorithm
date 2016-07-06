/**
 * @file InsertionSort.c
 * @Brief  Insertion sort
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-07-01
 */

#include <string.h>

#include "Sort.h"

void insert(DATA_TYPE* first, DATA_TYPE* last)
{
    DATA_TYPE *pre = last - 1;
    DATA_TYPE value = *last;

    while (value < *pre)
	*last-- = *pre--;

    *last = value;
}

int insertion_sort(DATA_TYPE array[], int array_size)
{
    if (array == NULL || array_size < 2)
	return -1;

    int i = 1;
    for (; i < array_size; ++i){
	DATA_TYPE value = array[i];
	if (value < array[0]){
	    memmove(array+1, array, i*sizeof(DATA_TYPE));
	    array[0] = value;
	} else
	    insert(array, array+i);
    }

    return 0;
}
