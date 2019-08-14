#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 4

void binary(int pack)
{
    unsigned int mask=1<<31;
	for(int c=1;c<=32;c++)
	{
		putchar(pack&mask?'1':'0');
		mask>>=1;

		if(c%8==0)
		{
			printf(" ");
		}
	}
}

void packCharacters(char character[])
{
    unsigned int value = character[0];
    for(int i = 0; i < SIZE; i++){
        value <<= 8;
        value = character[i]|value;
    }

    binary(value);
}

int main(void)
{
    char character[SIZE];
    puts("Input four characters:");
    for(int i = 0; i < SIZE; i++){
        scanf("%d", &character[i]);
    }

    puts("Original binary output:");
    for(int i = 0; i < SIZE; i++){
        binary(character[i]);
        puts("");
    }

    puts("Operated output:");

    packCharacters(character);

    return 0;
}
