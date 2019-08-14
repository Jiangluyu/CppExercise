#include<stdio.h>
int main(void)
{
    char a,b,c,d;
    scanf("%c%c%c%c",&a,&b,&c,&d);

    if(a <= 53)
        a += 10;
    if(b <= 53)
        b += 10;
    if(c <= 53)
        c += 10;
    if(d <= 53)
        d += 10;

    printf("The integer is %c%c%c%c",c,d,a,b);
    return 0;
}
