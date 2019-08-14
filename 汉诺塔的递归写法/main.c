#include<stdio.h>

int move(int n, char from, char via, char to)
{
    if(n == 1){
        printf("%c -> %c\n",from,to);
    }
    else{
        move(n-1,from,to,via);
        printf("%c -> %c\n",from,to);
        move(n-1,via,from,to);
    }
}

int main(void)
{
    int rings;
    scanf("%d",&rings);
    char from = 'a';
    char via = 'b';
    char to = 'c';
    move(rings,from,via,to);
}
