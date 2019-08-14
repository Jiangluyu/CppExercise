/*#include<stdio.h>
int main()
{
    int i;
    int n;
    int a;
    printf("Enter the line:");
    scanf("%d",&n);

    for(i = 0; i <= n; i++){
        for(a = 0; a < abs((n+1)/2-i); a++){
            printf(" ");
        }
        for(a = 0; a < n - 2*abs(i-(n + 1)/2); a++){
            printf("*");
        }
        printf("\n");
    }
}*/


#include<stdio.h>
int main()
{
    int lineCount = 0;
    printf("Enter the lineCount:");
    scanf("%d",&lineCount);
    for(int i = 1; i <= lineCount; i++){
        for(int j = 0; j < lineCount - i; j++){
            printf(" ");
        }
        for(int j = 0; j < 2*i-1; j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = 1; i <= lineCount - 1; i++){
        for(int j = 0; j < i; j++){
            printf(" ");
        }
        for(int j = 0; j < 2*(lineCount - i) - 1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

