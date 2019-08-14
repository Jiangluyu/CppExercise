//5.50~5.54
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int question()
{
    int a, b;
    a = rand()%9 + 1;
    b = rand()%9 + 1;
    printf("How much is %d times %d?\n", a, b);
    return a*b;
}

int main()
{
    srand(time(NULL));
    int i = 0;
    int answer = 0;
    while(i != -1){
        int c = question();
        scanf("%d",&answer);
        while(answer!= c){
            int num = rand()%4 + 1;
            switch(num){
                case 1:
                    printf("No. Please try again.\n");
                    break;
                case 2:
                    printf("Wrong. Try once more.\n");
                    break;
                case 3:
                    printf("Don't give up!\n");
                    break;
                case 4:
                    printf("No. Keep trying.\n");
                    break;
            }
            scanf("%d",&answer);
        }
        int num2 = rand()%4 + 1;
        switch(num2){
            case 1:
                printf("Very good!\n");
                break;
            case 2:
                printf("Excellent!\n");
                break;
            case 3:
                printf("Nice work!\n");
                break;
            case 4:
                printf("Keep up the work!\n");
                break;
            }
        printf("Continue? (-1 to quit)\n");
        scanf("%d",&i);
    }
    return 0;
}
