#include<stdio.h>
int move(int n, char from, char via, char to)
{
    if(n == 1)
        printf("%c -> %c\n", from, to);
    else{
        move(n-1, from, to, via);
        printf("%c -> %c\n", from, to);
        move(n-1, via, from, to);
    }
}

int main(void)
{
    int rings;
    printf("Input the rings: ");
    scanf("%d",&rings);
    move(rings,'a','b','c');
    return 0;
}
