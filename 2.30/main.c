#include<stdio.h>
int main()
{
    printf("number\tsquare\tcube\n");
    int j=0;
    for(j=0;j<=10;j++)
        printf("%d\t%d\t%d\n",j,j*j,j*j*j);
    return 0;
}
