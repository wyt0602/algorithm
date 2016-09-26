#include <Sort_new.h>

//能够调整最小的一棵树，只有一个结点，两个结点的情况。

void adjust_heap(DTYPE *array, int hole_index, int size)
{
    DTYPE temp = array[hole_index];
    int lchild = 2 * hole_index + 1;
    int rchild = 0;

    for (; lchild <= size - 1; lchild = lchild *2 + 1){
	rchild = lchild + 1;
	if (rchild <= size - 1 && array[lchild] < array[rchild])
	    ++lchild;

	if (temp >= array[lchild])
	    break;

	array[hole_index] = array[lchild];
	hole_index = lchild;
    }
    array[hole_index] = temp;
}

int heap_sort(DTYPE *array, int size)
{
    if (array == NULL)
	return -1;
    if (size < 2)
	return 0;

    int i = 0;
    for (i=size/2-1; i >= 0; --i){
	adjust_heap(array, i, size);
    }

    for (i=size-1; i > 0; --i){
	swap(array, 0, i);
	adjust_heap(array, 0, i);
    }

    return 0;
}
