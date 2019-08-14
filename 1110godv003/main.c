#include <stdio.h>
float sigma(int x)
{
    float result = 0.0;
    int signal = 1;
    if(x % 2 == 0)
        signal = -1;

    if(x == 1)
        return 4.0;
    else
        result = signal * 4.0 / (2 * x - 1) + sigma(x - 1);
    return result;
}

int main(void)
{
    int num;
    scanf("%d", &num);
    printf("%.2f",sigma(num));
}
