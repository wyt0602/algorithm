#include <stdio.h>

#include "GetList.h"

int main()
{
    LinkedNode *list1 = get_list(24, 60, LOOP);
    LinkedNode *list2 = get_list(12, 12, LOOP);

    printf("list:\n");
    print_list(list1);

    printf("list:\n");
    print_list(list2);

    return 0;
}
