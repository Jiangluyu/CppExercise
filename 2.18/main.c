#include<stdio.h>
int main()
{
    int x;
    int y;
    printf("Please enter two numbers:\n");
    scanf("%d\n%d",&x,&y);
    if(x > y)
    {
        printf("%d is larger", x);
    }
    else
    {
        if(x < y)
        {
            printf("%d is larger",y);
        }
        else
        {
            printf("These numbers are equal");
        }
    }
    getchar();
    return 0;
}
