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

    char search;

    int count[26] = {0};

    char *ptr = NULL;
    char *arrStr = NULL;
    arrStr = arr;

    for(int i = 65; i <= 90; i++){
        search = i;
        ptr = strchr(arrStr, search);
        while(ptr != NULL)
        {
            count[i - 65]++;
            arrStr = ptr + 1;
            ptr = strchr(arrStr, search);
        }
        arrStr =  arr;

        search = i + 32;
        ptr = strchr(arrStr, search);
        while(ptr != NULL)
        {
            count[i - 65]++;
            arrStr = ptr + 1;
            ptr = strchr(arrStr, search);
        }
         arrStr =  arr;
    }

    for(int i = 0; i < 26; i++){
        printf("%c\t%d\n", i + 65, count[i]);
    }
    return 0;
}
