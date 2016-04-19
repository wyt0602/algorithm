/**
 * @file Sort.h
 * @Brief  Sorting algorithm interface
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-14
 */

#ifndef SORT_H_
#define SORT_H_

typedef int DATA_TYPE;

int heap_sort(DATA_TYPE array[], int array_size);
int quick_sort(DATA_TYPE array[], int array_size);

#endif
