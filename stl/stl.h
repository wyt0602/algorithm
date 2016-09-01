#ifndef STL_H_
#define STL_H_

typedef int (*predicate)(int);

int median(int a, int b, int c);

int* find(int *first, int *last, int value);

int* find_if(int *first, int *last, predicate pred);

int* adjacent_find(int *first, int *last);

int count(int *first, int *last, int value);

int* search(int *first1, int *last1, int *first2, int *last2);

int* search_n(int *first, int *last, int count, int value);

void swap(int *a, int *b);

int* unique(int *first, int *last);

#endif
