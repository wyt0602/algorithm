/***************************************
  题目：实现一个算法，确定一个字符串的所有字符是否全部不同。假使不允许使用额外的数据结构，又该如何处理？
***************************************/

#include <string.h>
#include <stdio.h>

#define CHARACTER_SET 256
typedef enum{
    false,                   //error : false;
    true
}bool;

bool is_unique_ver1(char *str)
{
    if (strlen(str) > CHARACTER_SET)
	return false;

    char flag[CHARACTER_SET] = {};
    while (*str){                     //error : while (str)
	if (flag[*str] == 1)
	    return false;
	else 
	    flag[*str] = 1;

	str++;
    }

    return true;
}

bool is_unique(char *str)
{
    char flag[CHARACTER_SET/8] = {};
    int byte_index = 0;
    int bit_index = 0;

    while (*str){

	byte_index = *str/8;
	bit_index = *str%8;                      //error: forget the two lines

	if ((flag[byte_index] >> bit_index) & 0x01)
	    return false;
	else
	    flag[byte_index] |= 0x01 << bit_index;

	str++;
    }

    return true;
}

int main()
{
    char *str = "qwertyuiop[]asdfghjkl;zxcvbnm,./";

    if (is_unique(str))
	printf("unique!\n");
    else
	printf("not unique!\n");

    return 0;
}
