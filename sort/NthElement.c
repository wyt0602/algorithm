/**
 * @file NthElement.c
 * @Brief  Find Nth element
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-06-30
 */

#include "Sort.h"

typedef DATA_TYPE D_TYPE;

inline D_TYPE median(D_TYPE a, D_TYPE b, D_TYPE c)
{
    if (a < b){
	if (b < c)      //a<b, b<c -> a<b<c
	    return b;
	else if (a < c) //a<b, c<=b, so a<c -> a<c<=b
	    return c;
	else            //a<b, c<=b, c<=a -> c<=a<b
	    return a;
    }else if (c < b){   //b<=a, so c<b -> c<b<=a
	return b;
    }else if (a < c){   //b<=a, b<=c, so a<c -> b<=a<c
	return a;
    }else               //b<=a, b<=c, c<=a -> b<=c<=a 
	return c;
}

inline void swap(D_TYPE* a, D_TYPE* b)
{
    D_TYPE temp = *a;
    *a = *b;
    *b = temp;
}


D_TYPE* patition(D_TYPE* first, D_TYPE* last, D_TYPE pivot)
{
    --first;
    ++last;
    while (1){
	do{
	    ++first;
	}while (*first < pivot);

	do{
	    --last;
	}while (pivot < *last);

	if (first >= last)
	    return first;
	swap(first, last);
    }
}


/* --------------------------------------------------------------------------*/
/**
 * @Brief  nth_element Get the nth element from the given sequence
 *
 * @Param first 
 * @Param last
 * @Param nth nth from 0; nth = 1, means 0, 1
 *
 * @Returns   
 */
/* ----------------------------------------------------------------------------*/
D_TYPE* nth_element(D_TYPE* first, D_TYPE* last, int nth)
{
    if (!(first && last))
	return 0;
    if (last - first < nth)
	return 0;

    D_TYPE* goal = &first[nth];
    while ((last-first+1) > 3){
	D_TYPE* mid = first + (last - first) / 2;
	D_TYPE* cut = patition(first, last, median(*first, *last, *mid));

	if (cut <= goal)
	    first = cut;
	else
	    last = cut;
    }

    insertion_sort(first, last-first+1);

    return goal;
}

