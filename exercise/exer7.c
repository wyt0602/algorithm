/*******************************************
 * 题目：
 * 一个有序的数组的元素经过循环移动，元素的
 * 顺序可能变为“3 4 5 6 7 1 2”。怎样才能找出
 * 数组中最小的那个元素？假设数组中的元素各
 * 不相同。
 *
 *******************************************/

/*
 * (1)use binary search
 * (2)confirm the part that the min is in
 *
 *  -------------------------
 * |l| | | | | |m| | | | | |h|
 *  -------------------------
 *  \_________/ | \_________/
 *      |       |      |
 *     min(1) min(2)  min(3)
 *
 * min:
 *  (1) if m > h then min in (m, h] -> min(3)
 *  (2) if m < h then min in [l, m] -> min(1,2)
 */ 

#include <stdio.h>

int minimum(int *array, int size)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low < high){
	mid = (high - low)/2 + low; 
	//error: mid=(hig-low)/2; make this mistaken twice!!!!!!!!
	if (array[mid] > array[high])
	    low = mid + 1;
	else
	    high = mid;
    }

    return array[low];
}

int main()
{
    int array[10] = {4, 5, 6, 7, 8, 10, 13, -7, 2, 3};

    printf("result=%d\n", minimum(array, 10));
    return 0;
}
