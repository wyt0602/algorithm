#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Sort.h"
#include "ArrayNew.h"

#define SIZE 173

int main()
{
    int position = 73;
    int *array = get_array(SIZE, 900, NON_SORTED_UNIQUE);
    int *array_backup = malloc(SIZE * sizeof(int));
    if (array == NULL || array_backup == NULL)
	return 0;
    memcpy(array_backup, array, SIZE*sizeof(int));
    insertion_sort(array_backup, SIZE);
    print_array(array_backup, SIZE);

    int* goal = nth_element(array, array+SIZE-1, position);

    printf("goal=%d array[%d]=%d\n", *goal, position, array_backup[position]);

    return 0;
}
