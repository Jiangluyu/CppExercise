#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define LENGTH 70

int main(void)
{
    printf("BANG !!!!!\n");
    printf("AND THEY'RE OFF !!!!!\n");

    int way[3][LENGTH] = {0};
    int T = 0;
    int H = 0;

    srand(time(NULL));

    while(way[2][69] == 0){
        int i = rand() % 10 + 1;

        way[2][T] = 0;
        way[2][H] = 0;

        //Tortoise
        if(i <= 5){//Fast plod
            T += 3;
            if(T > 69)
                T = 69;
            way[0][T] = 1;
        }
        else if(i <= 7){//Slip
            T -= 6;
            if(T < 0)
                T = 0;
            way[0][T] = 1;
        }
        else if(i <= 10){//Slow plod
            T++;
            if(T > 69)
                T = 69;
            way[0][T] = 1;
        }

        //Hare
        if(i >= 3 && i <= 4){//Big hop
            H += 9;
            if(H > 69)
                H = 69;
            way[1][H] = 2;
        }
        else if(i == 5){//Big slip
            H -= 12;
            if(H < 0)
                H = 0;
            way[1][H] = 2;
        }
        else if(i <= 8 && i >= 6){//Small hop
            H++;
            if(H > 69)
                H = 69;
            way[1][H] = 2;
        }
        else if(i >= 9){//Small slip
            H -= 2;
            if(H < 0)
                H = 0;
            way[1][H] = 2;
        }

        if(T == H)
            way[2][T] = 3;
        else{
            way[2][T] = 1;
            way[2][H] = 2;
        }

        for(int j = 0; j < 70; j++){
            if(way[2][j] == 0)
                printf("_");
            else if(way[2][j] == 1)
                printf("T");
            else if(way[2][j] == 2)
                printf("H");
            else
                printf("OUCH!!!");
        }

        puts("");
        way[0][T] = 0;
        way[1][H] = 0;
        Sleep(1000);
    }

    if(way[2][69] == 1){
        printf("TORTOISE WINS!!! YAY!!!\n");
    }
    else if(way[2][69] == 2){
        printf("Hare wins. Yuch\n");
    }
    else if(way[2][69] == 3){
        printf("It's a tie\n");
    }

    return 0;
}
