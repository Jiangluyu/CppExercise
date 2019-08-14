#include <stdio.h>
void main()
{
    int i,j,n;
    printf("请输入方阵的行(列)宽n:  ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        printf("* ");
        printf("\n");
    }
}
