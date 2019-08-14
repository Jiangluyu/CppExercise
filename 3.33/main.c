#include<stdio.h>
int main(void)
{
    int x, y, n;
    printf ("请输入正方形的边长：");
    scanf ("%d",&n);
    for (x = 0; x < n; x++)
        {
            for (y = 0; y < n; y++)
            {
                if (x == 0 || y == 0 || x == n - 1 || y == n - 1)
                {
                    printf ("*");
                }
                else
                {
                    printf (" ");
                }
            }
            printf("\n");
        }
    return 0;
}
