#include <assert.h>
#include "stl.h"


int median(int a, int b, int c)
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

int* find(int *first, int *last, int value)
{
    assert(first <= last);

    while (first != last && *first != value)
	++first;

    return first;
}

int* find_if(int *first, int *last, predicate pred)
{
    assert(first <= last);

    int trip_count = (last - first) >> 2; //make sure step -> 4

    //excellent
    for (; trip_count > 0; --trip_count){
	if (pred(*first)) return first;
	++first;

	if (pred(*first)) return first;
	++first;

	if (pred(*first)) return first;
	++first;

	if (pred(*first)) return first;
	++first;
    }

    //bravo
    switch (last - first){
	case 3:
	    if (pred(*first)) return first;
	    ++first;
	case 2:
	    if (pred(*first)) return first;
	    ++first;
	case 1:
	    if (pred(*first)) return first;
	case 0:
	default:
	    return last;
    }
}

int* adjacent_find(int *first, int *last)
{
    assert(first <= last);

    //empty
    if (first == last) return last;

    //equal to or more than 1
    int *next = first;
    while (++next != last){
	if (*next == *first)
	    return first;
	first = next;
    }

    return last;
}

int count(int *first, int *last, int value)
{
    assert(first <= last);

    int n = 0;
    while (first != last)
	if (*first++ == value)
	    ++n;

    return n;
}

int* search(int *first1, int *last1, int *first2, int *last2)
{
    assert(first1 <= last1);
    assert(first2 <= last2);

    //test empty
    if (first1 == last1 || first2 == last2)
	return last1;

    //test list2 only one element
    if (first2 + 1 == last2)
	return find(first1, last1, *first2);

    //temp for traversal
    int *op1, *op2;
    while (first1 != last1){
	op2 = first2;
	first1 = find(first1, last1, *op2++);
	if (first1 == last1)
	    return last1;
	op1 = first1;
	if (++op1 == last1)
	    return last1;

	while (*op1 == *op2){
	    if (++op1 == last1)
		return last1;
	    if (++op2 == last2)
		return first1;
	}
	++first1;
    }

    return last1;
}

int* search_n(int *first, int *last, int count, int value)
{
    assert(first <= last);

    if (count <= 0)
	return last;

    int *op;
    int i;
    first = find(first, last, value);
    while (first != last){
	op = first;
	i = count;
	while (++op != last && --i != 0 && *op == value)
	    ;

	if (i == 0)
	    return first;

	first = find(op, last, value);
    }
    return last;
}

inline void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
