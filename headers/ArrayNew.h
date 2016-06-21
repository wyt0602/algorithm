/**
 * @file ArrayNew.h
 * @Brief  get array
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-05-24
 */

#ifndef ARRAY_NEW_H_
#define ARRAY_NEW_H_

#define SORTED_UNIQUE         1
#define SORTED_NON_UNIQUE     2
#define NON_SORTED_UNIQUE     3
#define NON_SORTED_NON_UNIQUE 4

int* get_array(int size, int scale, int type);
void print_array(int *array, int size);

#endif
