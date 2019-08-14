#include<stdio.h>
int main(void)
{
    unsigned int N,i;
    printf("N\t10*N\t100*N\t1000*N\n\n");
    for(i = 0;i < 10;i++){
        N = i + 1;
        printf("%d\t%d\t%d\t%d\n",N,10*N,100*N,1000*N);
    }
    return 0;
}
