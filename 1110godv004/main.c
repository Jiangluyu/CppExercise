#include<stdio.h>
int jc(int n)
{
    int result = 0;
    if(n == 1)
        result = 1;
    else
        result = n * jc(n - 1);
    return result;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",jc(n));
}
