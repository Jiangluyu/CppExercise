#include<stdio.h>
int main(void)
{
    int x, y;
    printf("Please enter the value of x&y:");
    scanf("%d%d",&x,&y);

    if( y == 8)
    {
        if( x == 5)
            puts("@@@@@");
            puts("#####");
            puts("$$$$$");
    }
    else
    {
        puts("&&&&&");
    }
    return 0;
}
