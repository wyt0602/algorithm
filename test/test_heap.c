/**
 * @file test_sort.c
 * @Brief  test sort
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-14
 */

#include <stdio.h>
#include "Sort.h"
#include "GetArray.h"

#define ARRAY_SIZE 1000000
#define RAND_FILE "rand.txt"
#define RESULT_FILE "result.txt"

int main()
{

    /*int array[10] = {2, 4, 6, 12, 23, \
	21, 11, 5, 89, 32
    };

    heap_sort(array, 10);

    int i;
    for (i = 0; i < 10; i++)
	printf("%d\n", array[i]);*/

    
    FILE* f_rand_show = fopen(RAND_FILE, "a+");
    FILE* f_result = fopen(RESULT_FILE, "a+");
    if (!(f_result && f_rand_show)){
	printf("fopen error!");
	return -1;
    }

    printf("fps are all right!\n");
    int array[ARRAY_SIZE] = {};

    int ret = 0;
    ret = get_array(array, ARRAY_SIZE);
    if (ret != 0)
	return -1;

    printf("get array is all right!\n");
    int i;

    for(i = 0; i < ARRAY_SIZE; i++){
	if ((i%5 == 0) && (i != 0))
	    fprintf(f_rand_show, "\n");
	fprintf(f_rand_show, "%8d  ", array[i]);
    }
    fclose(f_rand_show);

    heap_sort(array, ARRAY_SIZE);

    for(i = 0; i < ARRAY_SIZE; i++){
	if ((i%5 == 0) && (i != 0))
	    fprintf(f_result, "\n");
	fprintf(f_result, "%8d  ", array[i]);
    }
    fclose(f_result);

    return 0;
}

