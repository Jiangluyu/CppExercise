#include<stdio.h>
int main(void)
{
    int number,a,b,c,d,e;
    printf("Enter the number:");
    scanf("%d",&number);

    a = number/10000;
    b = (number-a*10000)/1000;
    c = (number-a*10000-b*1000)/100;
    d = (number-a*10000-b*1000-c*100)/10;
    e = (number-a*10000-b*1000-c*100-d*10);

    if((a == e)&&(b == d))
        printf("yes");
    else
        printf("no");
    return 0;
}
