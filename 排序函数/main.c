#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int pop(int x[])
{
    for(int i = 0; i < 10; i++){
        for(int j = 9; j > 0; j--){
            int c = 0;
            if(x[j] <= x[j-1]){
                c = x[j];
                x[j] = x[j-1];
                x[j-1] = c;
            }
        }
    }
    for(int i = 0; i < 10; i++)
        printf("%d\t", x[i]);
    printf("\n\n");
}

int search(int x[],int y)
{
    printf("Please enter a number to find: ");
    int flag = 0;
    for(int i = 0; i < 10; i++){
        if(y == x[i]){
            printf("the number at %d\n",i);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
    printf("Sorry.");
    }
    printf("\n\n");
}

int messUp(int x[])
{
    int index;
    int tmp;
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        index = rand()%10;
        tmp = x[i];
        x[i] = x[index];
        x[index] = tmp;
    }
    for(int i = 0; i < 10; i++)
        printf("%d\t",x[i]);

    printf("\n\n");
}

int main(void)
{
    int a[10] = {6,7,5,1,4,3,2,9,5,0};
    pop(a);
    messUp(a);
    search(a, 5);
}
