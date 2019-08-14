#include<stdio.h>
int main(void)
{
    int value;
    int max = 0;
    int i;
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        printf("Enter the integer:");
        scanf("%d",&value);
        if(value >= max)
            max = value;
    }
    printf("The max is: %d", max);
    return 0;
}
