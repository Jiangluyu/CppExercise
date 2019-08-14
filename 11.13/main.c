#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void init(int num, int dial[])
{
    dial[0] = num / 1000000;
    dial[1] = (num - dial[0] * 1000000) / 100000;
    dial[2] = (num - dial[0] * 1000000 - dial[1] * 100000) / 10000;
    dial[3] = (num - dial[0] * 1000000 - dial[1] * 100000 - dial[2] * 10000) / 1000;
    dial[4] = (num - dial[0] * 1000000 - dial[1] * 100000 - dial[2] * 10000 - dial[3] * 1000) / 100;
    dial[5] = (num - dial[0] * 1000000 - dial[1] * 100000 - dial[2] * 10000 - dial[3] * 1000 - dial[4] * 100) / 10;
    dial[6] = (num - dial[0] * 1000000 - dial[1] * 100000 - dial[2] * 10000 - dial[3] * 1000 - dial[4] * 100 - dial[5] * 10) / 1;
}

void writeInFile(char word[])
{
    FILE *ofPtr;
    ofPtr = fopen("dialogName.txt", "a+");

    fprintf(ofPtr, "%s\n", word);

    fclose(ofPtr);
}

void letter(int wdial, int count, int pos, char word[])
{
    char letter[10][3] = {"","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};

    if((count / (int)pow(3, pos-1)) % 3 == 0)
        word[7-pos] = letter[wdial][0];
    else if((count / (int)pow(3, pos-1)) % 3 == 1)
        word[7-pos] = letter[wdial][1];
    else if((count / (int)pow(3, pos-1)) % 3 == 2)
        word[7-pos] = letter[wdial][2];
}

void generater(int dial[])
{
    char word[7] = {0};
    int count = 1;
    for(int i = 0; i < (int)pow(3, 7); i++){
        for(int pos = 0; pos < 7; pos++){
            letter(dial[6-pos], count, pos+1, word);
        }
        writeInFile(word);
        printf("%s", word);
        puts("");
        count++;
    }

}

int main(void)
{
    int num = 0;
    puts("Input the telephone number(space to separate each number):");
    scanf("%d", &num);

    int dial[7] = {0};

    init(num, dial);

    generater(dial);

    return 0;
}
