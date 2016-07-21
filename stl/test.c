#include <stdio.h>

#include "stl.h"
#include "../headers/ArrayNew.h"

int greater(int element){
    return element > 4;
}

int main()
{
    //test median
    int m = median(0, 3, 3);
    printf("m=%d\n", m);

    int *array = get_array(20, 5, NON_SORTED_NON_UNIQUE);
    print_array(array, 20);

    //test find or find_if
    //int *result = find(array+6, array+6, 5);
    int *result = find_if(array, array+20, &greater);
    if (result != array+20)
	printf("result = %d\n", *result);
    else
	printf("not find!\n");

    //test adjacent_find
    result = adjacent_find(array, array+20);
    if (result != array+20)
	printf("result = %d %d\n", result[0], result[1]);
    else
	printf("not find!\n");

    //test count
    int num = count(array, array+20, 7);
    printf("num=%d\n", num);

    //test search or search_n
    int arr1[13] = {1, 2, 3, 3, 5, 5, 5, 6, 8, 3, 3, 3, 5};
    int arr2[3] = {3, 5, 5};
    //result = search(arr1, arr1+13, arr2, arr2+3);
    result = search_n(arr1, arr1+13, 3, 3);
    int i = 0;
    if (result != arr1+13)
	for (; i<3; ++i)
	    printf("%d\n", result[i]);
    else
	printf("not find\n");


    return 0;
}
