#include<stdio.h>
int main(void)
{
    int count;
    int total = 0;
    int number;
    printf("Enter the number:");
    scanf("%d",&count);
    for(int i = 0; i < count; i++){
        scanf("%d",&number);
        total += number;
    }
    printf("total is %d",total);
    return 0;
}
