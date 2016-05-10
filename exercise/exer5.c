/************************************************
 * 题目：
 * 利用字符重复出现的次数，编写一个方法，实现基本
 * 的字符串压缩功能。比如，字符串"aabcccccaaa"会
 * 变为"a2b1c5a3"。若“压缩”后的字符串没有变短，则
 * 返回原先的字符串。
 *
 ************************************************/ 

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum{
    false,
    true
}bool;

bool compress(char *str)
{
    int size = strlen(str);
    char *compress_str = malloc(size*2 + 1);  //error: must be dynamic array
    memset(compress_str, 0, size*2 + 1);

    int index = 0;
    int count;
    char *buf = compress_str;

    while (index < size){
	count = 1;
	*buf = str[index];
	while (*buf == str[++index])
	    count++;

	buf++;         //error: miss this sentence
	int count_len = sprintf(buf, "%d", count);
	//buf = buf + count_len + 1;     error:added 1 more
	buf = buf + count_len;
    }

    if (strlen(compress_str) >= size)
	return false;

    while (*compress_str)
	*str++ = *compress_str++;

    *str = '\0';      //error: miss this

    return true;
}

int main()
{
    char str[] = "aaaaaacccccccdddddldckdddddjjjj";
    printf("input:%s\n", str);

    compress(str);
    printf("output:%s\n", str);

    return 0;
}
