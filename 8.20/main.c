#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("In0put the source text: (Enter to end)\n");
    char arr[999];
    gets(arr);

    char sign[999];
    gets(sign);
    while(sign[0] != '\0'){
        strcat(arr, sign);
        gets(sign);
    }

    int count = 1;

    char *stoken = strtok(arr," ");
    while(stoken != NULL){
        count++;
        stoken = strtok(NULL, " ");
    }

    char *stoken1 = strtok(arr, "\n");
    while(stoken1 != NULL){
        count++;
        stoken1 = strtok(NULL, "\n");
    }

    printf("%d\n", count);

    return 0;
}
