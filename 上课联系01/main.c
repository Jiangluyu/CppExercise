#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int poker[54] = {0};

int divide(int x)
{
    if(x <= 13){
        printf("����%d\n",x);
    }
    else if(x <= 26){
        printf("����%d\n", (x-1)%13+1);
    }
    else if(x <= 39){
        printf("÷��%d\n", (x-1)%13+1);
    }
    else if(x <= 52){
        printf("��Ƭ%d\n", (x-1)%13+1);
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
        divide(x[i]);
    }
    puts("");
}

int main(void)
{
    for(int i = 0; i < 54; i++){
        poker[i] = i + 1;
    }

    //ϴ��
    srand(time(NULL));
    for(int c = 0; c < 300; c++){
        int rdm1 = rand()%54;
        int rdm2 = rand()%54;
        int tmp = poker[rdm1];
        poker[rdm1] = poker[rdm2];
        poker[rdm2] = tmp;
    }

    printPoker(poker,54);
    printf("\n------------cards-------------\n");

    //���ֶ�����,����(ʣ����)����ӡ
    int player[3][17];
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

    return 0;
}
