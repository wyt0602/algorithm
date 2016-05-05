/***********************************************
 *题目：
 *    用c或c++实现void reverse(char *str)函数，即反转一个NULL结尾
 *    的字符串。
 *
 ***********************************************/ 

#include <string.h>
#include <stdio.h>

void reverse(char *str)
{
    int left = 0;
    int right = strlen(str) - 1;   //error : right = strlen(str);
    char temp;

    while (left < right){
	temp = str[left];
	str[left] = str[right];
	str[right] = temp;

	left++;
	right--;
    }
}

int main()
{
    char str[] = "hello world!";

    printf("old:%s\n", str);

    reverse(str);

    printf("new:%s\n", str);

    return 0;
}
