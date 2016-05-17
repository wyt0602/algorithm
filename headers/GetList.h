/**
 * @file GetList.h
 * @Brief  Get List interface
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-05-12
 */

#ifndef GET_LIST_H_
#define GET_LIST_H_

typedef int DATA_TYPE;

typedef struct LinkedNode{
    int visit;
    DATA_TYPE value;
    struct LinkedNode *next;
}LinkedNode;

#define SORTED_UNIQUE         1
#define SORTED_NON_UNIQUE     2
#define UNIQUE_NON_SORTED     3
#define NON_UNIQUE_NON_SORTED 4
#define LOOP                  5 

typedef unsigned int LIST_TYPE;

void print_list(LinkedNode *list);
LinkedNode* get_list(int size, int scale, LIST_TYPE type);
LinkedNode* merge_sort(LinkedNode *list);

#endif
