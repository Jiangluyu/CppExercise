#include <stdio.h>
#include <stdlib.h>

int main()
{
    int value;
    scanf("%d", &value);

    unsigned int displayMask = 1 << 31;

    for(unsigned int c = 1; c <= 32; c++)
    {
        putchar(value & displayMask ? '1' : '0');
        value <<= 1;

        if(c % 8 == 0)
            putchar(' ');
    }
}
