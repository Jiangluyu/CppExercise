#include<stdio.h>
int main()
{
    int i,j;
    scanf("%d",&i);
    for(i = 1; i <= 20; i++)//控制每行打印
    {
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }
    }
}
