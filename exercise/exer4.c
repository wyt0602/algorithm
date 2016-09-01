/******************************************************
 * 题目：
 * 编写一个方法，将字符串中的空格全部替换为“%20”。
 * 假定该字符串尾部有足够的空间存放新增的字符，并
 * 且返回字符串的“真”实长度。
 * 示例：
 * input: "Mr John Smith"
 * output: "Mr%20John%20Smith"
 *
 */ 

#include <stdio.h>

int replace_space(char *str)
{
    int len_old = 0;
    int len_new = 0;
    int space_count = 0;

    while (str[len_old]){
	if (str[len_old] == ' ')
	    space_count++;
	len_old++;
    }

    if (space_count == 0)
	return len_old;

    len_new = len_old + space_count*2; //error:not space_count*3, %20=3 ' '=1; 3-1 =2

    int index_old = len_old - 1;
    int index_new = len_new - 1;

    while (index_old >= 0){
	if (str[index_old] != ' ')
	    str[index_new--] = str[index_old--];
	else{
	    str[index_new--] = '0';
	    str[index_new--] = '2';
	    str[index_new--] = '%';
	    index_old--;
	}
    }

    return len_new;
}

int main()
{
    char str[50] = " ";
    printf("input:%s\n", str);

    int count = replace_space(str);
    printf("output:%s count:%d\n", str, count);

    return 0;
}
