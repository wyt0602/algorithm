#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_next(char *str, int *next)
{
    int len = strlen(str);
    int i = 0;
    int j = -1;
    next[0] = -1;

    while (i < len){
	if (j == -1 || str[i] == str[j]){
	    ++i;
	    ++j;
	    if (str[i] == str[j])
		next[i] = next[j];
	    else
	        next[i] = j;
	} else
	    j = next[j];
    }
}

int is_substring(char *str1, char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 < len2)
	return 0;

    int i = 0;
    int j = 0;
    int *next = (int*)malloc(len2);
    if (next == NULL)
	return 0;

    get_next(str2, next);

    while (i < len1 && j < len2){
	if ( j == -1 || str1[i] == str2[j]){
	    ++i;
	    ++j;
	} else
	    j = next[j];
    }

    if (j < len2)
	return 0;
    else
	return 1;
}

int main()
{
    char *str1 = "aaaaaaaaaaaaaaaaax";
    char *str2 = "aaaaaax";

    int ret = is_substring(str1, str2);
    if (ret == 1)
	printf("is sub string!\n");
    else
	printf("is not sub string!\n");

    return 0;
}
