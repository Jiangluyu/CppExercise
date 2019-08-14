#include<stdio.h>
#define SIZE 10

int main(void)
{
    int a[10] = {0};
    for(int i = 0; i < 10; i++){
        scanf("%d",&a[i]);
    }

    for(int i = 0; i < 10; i++){
        for(int j = 9; j > 0; j--){
            int hold;
            if (a[j] < a[j-1]){
                hold = a[j-1];
                a[j-1] = a[j];
                a[j] = hold;
            }
        }
    }

    for(int i = 0; i < 10; i++){
        printf("%d",a[i]);
    }

    int tmp;
    int up = 9;
    int down = 0;
    int flag = 0;
    printf("Please enter a number to find(0~9): ");
    scanf("%d", &tmp);
    while(up > down){
        if(tmp == a[(up+down)/2]){
            printf("The number is at %d\n",(up + down)/2);
            flag = 1;
            break;
        }
        else if(tmp < a[(up+down)/2]){
            up = (up + down)/2;
        }
        else if(tmp > a[(up+down)/2]){
            down = (up + down)/2;
        }
    }
    if(flag == 0){
        printf("sorry.\n");
    }
}

