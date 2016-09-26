#ifndef SORT_H
#define SORT_H

typedef int DTYPE;

#define NULL 0

void swap(DTYPE *array, int l, int r)
{
    DTYPE temp = array[l];
    array[l] = array[r];
    array[r] = temp;
}

int heap_sort(DTYPE *array, int size);

#endif
