/**
 * @file GetArray.c
 * @Brief  Implementation about getting an array
 * @author wu yangtao , w_y_tao@163.com
 * @version version 1.0
 * @date 2016-04-14
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Log.h"
#include "GetArray.h"

int get_array(int array[], int array_size)
{
    if (array == NULL || array_size == 0)
	return -1;

    char *flag = calloc(1, array_size);
    if (flag == NULL){
	ERROR("calloc error!");
	return -1;
    }

    /*int fd = open("/dev/urandom", O_RDONLY);
    if (fd == -1){
	ERROR("open /dev/urandon error!");
	return -1;
    }*/

    int count = 0;

    while (count < array_size){
	unsigned int temp;
	//read(fd, &temp, 4);
	temp = rand() % array_size;

	if (flag[temp])
	    continue;
	else {
	    array[count] = temp;
	    flag[temp] = 1;
	    count++;
	}
    }

    //close(fd);

    free(flag);

    return 0;
}






















