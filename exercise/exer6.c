/***************************************************
 * 题目：
 * 编写一个算法，若MxN矩阵中某个元素为0，则将其
 * 所在的行与列清零。
 *
 ***************************************************/ 

#include <stdio.h>
#include <stdlib.h>

#define COLUMN 7

//error: two-dimensional array for parameter, must like this or
//like this ---- int (*matrix)[COLUMN] ----
//not ---- int *matrix[COLUMN] ---- 
//[] has higher priority than *
void set_zeros(int matrix[][COLUMN], int row, int column)
{
    int *row_flag = malloc(row*sizeof(int));
    int *column_flag = malloc(column*sizeof(int));

    if (!(row_flag && column_flag))
	printf("malloc error!\n");

    int i, j;
    for (i = 0; i < row; ++i){
	for (j = 0; j < column; ++j){
	    if (matrix[i][j] == 0){
		row_flag[i] = 1;
		column_flag[j] = 1;
	    }
	}
    }

    for (i = 0; i < row; ++i){
	for (j = 0; j < column; ++j){
	    if (row_flag[i] || column_flag[j])
		matrix[i][j] = 0;
	}
    }
}

int main()
{
    int matrix[3][7] = {{2, 3, 5, 12, 34, 7, 16},\
			{9, 0, 4, 23, 1, 0, 99},\
			{0, 2, 8, 0, 12, 23, 33}};
    int i, j;
    for (i = 0; i < 3; ++i){
	if (i != 0)
	    printf("\n");
	for (j = 0; j < 7; ++j){
	    printf("%2d ", matrix[i][j]);
	}
    }
    printf("\nafter setting:\n");

    set_zeros(matrix, 3, 7);
    for (i = 0; i < 3; ++i){
	if (i != 0)
	    printf("\n");
	for (j = 0; j < 7; ++j){
	    printf("%2d ", matrix[i][j]);
	}
    }
    printf("\n");

    return 0;
}
