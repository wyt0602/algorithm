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
    DATA_TYPE value;
    struct LinkedNode *next;
}LinkedNode;

#define SORTED_UNIQUE         0x0001
#define SORTED_NON_UNIQUE     0x0010
#define UNIQUE_NON_SORTED     0x0100
#define NON_UNIQUE_NON_SORTED 0x1000

typedef unsigned int LIST_TYPE;

LinkedNode* get_list(int size, LIST_TYPE type);
LinkedNode* merge_sort(LinkedNode *list);

#endif
