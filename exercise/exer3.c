/************************************************
 * 题目：
 * 给定两个字符串，请编写程序，确定其中一个字符串
 * 的字符重排后，能否变成另一个字符串。
 *
 ************************************************/

#include <string.h>
#include <stdio.h>

typedef enum {
    false,
    true
}bool;

#define CHARACTER_SET 256
bool compare(char *str1, char *str2)
{
    if (strlen(str1) != strlen(str2))
	return false;

    int count[CHARACTER_SET] = {};
    while (*str1){
	count[*str1]++;
	str1++;
    }

    while (*str2){
	count[*str2]--;
	str2++;
    }

    int i;
    for (i=0; i<CHARACTER_SET; i++){
	if (count[i] != 0)
	    return false;
    }

    return true;
}

int main()
{
    char *str1 = "hello world!";
    char *str2 = "held worllo!";

    if (compare(str1, str2) == true)
	printf("match exactly!\n");
    else
	printf("no match!\n");

    return 0;
}
