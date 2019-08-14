#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Input the source text: (Enter to end)\n");
    char arr[999];
    gets(arr);

    char sign[999];
    gets(sign);
    while(sign[0] != '\0'){
        strcat(arr, sign);
        gets(sign);
    }

    printf("Enter the words you want to search: \n");
    char search;
    scanf("%c", &search);

    int count = 0;

    char *ptr = NULL;
    char *arrStr = NULL;
    arrStr = arr;

    ptr = strchr(arrStr, search);
    while(ptr != NULL)
    {
        count++;
        arrStr = ptr + 1;
        ptr = strchr(arrStr, search);
    }
    printf("%d\n", count);
    return 0;
}
