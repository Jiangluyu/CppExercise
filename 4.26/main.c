#include<stdio.h>
int main(void)
{
    int number;
    float sum = 0.0;
    int signal = 1;
    int i = 1;

    while (i < 999){
        signal = i % 2 == 0 ? -1: 1;
        sum += signal*4.0/(2*i -1);
        printf("%d : %f\n",i,sum);
        i++;
    }
}
