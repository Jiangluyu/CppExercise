#include<stdio.h>
int main(void)
{
    int a, b;
    printf("Input a ^ b:");
    scanf("%d%d",&a,&b);
    printf("The result is %d",power(a,b));
}

int power(int x, int y)
{
    int z;
    for (;y > 1;y--){
       z = x*power(x,y-1);
    }
    return z;
}
