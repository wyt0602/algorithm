/**
 * @file ArrayNew.c
 * @Brief  get array implementation
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-05-24
 */

#include <stdio.h>
#include <stdlib.h>

#include "Sort.h"
#include "ArrayNew.h"

int unique(int *array, int size, int scale)
{
    char *flag = malloc(scale);
    if (flag == NULL)
	return -1;

    int index = 0;
    while (index < size){
	int temp = random()%scale;
	if (flag[temp] == 1)
	    continue;
	array[index] = temp;
	flag[temp] = 1;
	index++;
    }

    free(flag);
    return 0;
}

int non_unique(int *array, int size, int scale)
{
    int index = 0;
    while (index < size){
	int temp = random()%scale;
	array[index] = temp;
	index++;
    }
    return 0;
}


int* get_array(int size, int scale, int type)
{
    if (type == SORTED_UNIQUE  || type == NON_SORTED_UNIQUE)
	if (scale < size)
	    scale = size;

    int *array = malloc(sizeof(int)*size);
    if (array == NULL)
	return NULL;

    switch (type){
	case SORTED_UNIQUE:
	    if (unique(array, size, scale) != 0)
		return NULL;
	    heap_sort(array, size);
	    break;
	case SORTED_NON_UNIQUE:
	    if (non_unique(array, size, scale) != 0)
		return NULL;
	    heap_sort(array, size);
	    break;
	case NON_SORTED_UNIQUE:
	    if (unique(array, size, scale) != 0)
		return NULL;
	    break;
	case NON_SORTED_NON_UNIQUE:
	    if (non_unique(array, size, scale) != 0)
		return NULL;
	    break;
	default:
	    return NULL;
    }

    return array;
}

void print_array(int *array, int size)
{
    int index = 0;
    int count = 0;
    while (index < size){
	if (count%6 == 0 && count != 0)
	    printf("\n");
	printf("%8d", array[index]);
	count++;
	index++;
    }
    printf("\n");
}

/*
int main()
{
    int *array = get_array(23, 100, SORTED_UNIQUE);
    printf("array1:\n");
    print_array(array, 23);
    free(array);

    array = get_array(30, 13, SORTED_NON_UNIQUE);
    printf("array2:\n");
    print_array(array, 30);
    free(array);

    array = get_array(34, 100, NON_SORTED_UNIQUE);
    printf("array3:\n");
    print_array(array, 34);
    free(array);

    array = get_array(40, 20, NON_SORTED_NON_UNIQUE);
    printf("array4:\n");
    print_array(array, 40);
    free(array);

    return 0;
}
*/
