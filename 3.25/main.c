#include<stdio.h>
int main(void)
{
    unsigned int A,i;
    printf("A\tA+2\tA+4\tA+6\n\n");
    for(i = 0;i < 5;i++){
        A = 3*i + 3;
        printf("%d\t%d\t%d\t%d\n",A,A+2,A+4,A+6);
    }
    return 0;
}
