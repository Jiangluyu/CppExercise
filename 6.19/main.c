#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 13

int main(void)
{
    unsigned int frequency[SIZE] = {0};

    srand(time(NULL));

    for(unsigned int roll = 1; roll <= 36000; roll++){
        int rolla = 1 + rand()%6;
        int rollb = 1 + rand()%6;
        int face = rolla + rollb;
        frequency[face]++;
    }

    printf("%s\t\t%s\n","Face","Frequency");

    for(size_t face = 2; face < SIZE; face++){
        printf("%u\t\t%u",face,frequency[face]);
        puts("");
    }
    return 0;
}
