#include<stdio.h>
int main()
{
    int i,j;
    scanf("%d",&i);
    for(i = 1; i <= 20; i++)//����ÿ�д�ӡ
    {
        for(j = 1; j <= i; j++)
        {
            printf("*");
        }
    }
}
