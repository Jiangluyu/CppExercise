#include<stdio.h>
int main()
{
    int x;
    int y;
    printf("Please enter two numbers.\n");
    scanf("%d%d",&x,&y);

    printf("result1 is %d\n",x+y);
    printf("result2 is %d\n",x*y);
    printf("result3 is %d\n",x/y);
    printf("result4 is %d\n",x%y);
    getchar();
    return 0;
}
