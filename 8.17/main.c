#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
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

    char arr1[999];
    strcpy(arr1, arr);

    printf("Enter the words you want to search: \n");
    char search[20];
    gets(search);

    int count = 0;

    char *ptr = NULL;
    char *arrStr = NULL;
    arrStr = arr1;

    ptr = strstr(arrStr, search);
    while(ptr != NULL)
    {
        count++;
        arrStr = ptr + strlen(search);
        ptr = strstr(arrStr, search);
    }
    printf("%d\n", count);

    return 0;
}
