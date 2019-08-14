#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 4

void binaryTransfer(int num)
{
    char bin[100] = {0};
    int count = 0;
    if(num == 1){
        count++;
        bin[0] = 1;
    }
    else{
        while(num > 0){
            if(num%2 == 1)
                bin[count] = 1;
            else
                bin[count] = 0;
            num /= 2;
            if(num > 0)
                count++;
        }
    }

    int column = 1;
    column = column + (count / 8);
    if(count%8 == 0)
        column--;
    column *= 8;

    for(int i = column-1; i >= 0; i--){
        printf("%d", bin[i]);
        if(i%8 == 0)
            putchar(' ');
    }

    puts("");

}

void packCharacters(char character[])
{
    unsigned int value = character[0];
    for(int i = 0; i < SIZE; i++){
        value <<= 8;
        value = character[i]|value;
    }

    binaryTransfer(value);
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
        binaryTransfer(character[i]);
    }

    puts("Operated output:");

    packCharacters(character);

    return 0;
}
