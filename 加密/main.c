#include<stdio.h>
int main(void)
{
    char a,b,c,d;
    scanf("%c%c%c%c",&a,&b,&c,&d);

    if(a >= 51)
        a -= 10;
    if(b >= 51)
        b -= 10;
    if(c >= 51)
        c -= 10;
    if(d >= 51)
        d -= 10;

    printf("The code is %c%c%c%c",c,d,a,b);
    return 0;
}
