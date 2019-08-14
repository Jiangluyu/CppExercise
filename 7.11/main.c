#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 54

int poker[54] = {0};

int dividePoker(int x)
{
    if(x <= 13){
        printf("����%d\n", (x - 1)% 13 + 1);
    }
    else if(x <= 26){
        printf("����%d\n", (x - 1)% 13 + 1);
    }
    else if(x <= 39){
        printf("÷��%d\n", (x - 1)% 13 + 1);
    }
    else if(x <= 52){
        printf("��Ƭ%d\n", (x - 1)% 13 + 1);
    }
    else if(x == 53){
        printf("С��\n");
    }
    else{
        printf("����\n");
    }
}

int printPoker(int x[], int n)
{
    for(int i = 0; i < n; i++){
        dividePoker(x[i]);
    }
}

int mixPoker()
{
    srand(time(NULL));

    for(int c = 0; c < 200; c++){
        int random1 = rand() % 54;
        int random2 = rand() % 54;
        int temp = 0;
        temp = poker[random1];
        poker[random1] = poker[random2];
        poker[random2] = temp;
    }
}

int main(void)
{
    for(int i = 0; i < 54; i++){
        poker[i] = i + 1;
    }

    printPoker(poker, 54);

    printf("\n-------------Origin----------\n");

    mixPoker();

    printPoker(poker, 54);

    printf("\n-------------Mixed-----------\n");

    int player[3][17] = {0};
    int index = 0;
    for(int i = 0; i < 51; i++){
            player[i%3][index] = poker[i];
        if(i%3 == 2)
            index++;
    }

    printPoker(player[0],17);

    printf("\n------------player1-----------\n");

    printPoker(player[1],17);

    printf("\n------------player2-----------\n");

    printPoker(player[2],17);

    printf("\n------------player3-----------\n");
}
