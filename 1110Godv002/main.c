#include<stdio.h>
int sigma(int x)
{
    int result = 0;
    if(x == 1)
        result = 1;
    else
        result += x + sigma(x - 1);
    return result;
}

int main(void)
{
    int num;
    scanf("%d",&num);
    printf("%d",sigma(num));
}
