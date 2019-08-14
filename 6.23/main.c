#include <stdio.h>
#include <stdlib.h>

int x = 0;
int y = 0;
int flag = 0;
int n;

int floor[50][50];

int act1(int n1)
{
        switch(flag%4){
        case 0://up
            scanf("%d",&n);
            for(int c = 0; c < n; c++){
                x--;
            }
            break;
        case 1://right
            scanf("%d",&n);
            for(int c = 0; c < n; c++){
                y++;
            }
            break;
        case 2://down
            scanf("%d",&n);
            for(int c = 0; c < n; c++){
                x++;
            }
            break;
        case 3://left
            scanf("%d",&n);
            for(int c = 0; c < n; c++){
                y--;
            }
            break;
        }
}

int act2(int n2)
{
        switch(flag%4){
        case 0://down
            scanf("%d",&n);
            for(int c = 0; c < n; c++){
                x++;
                floor[x][y] = 1;
            }
            break;
        case 1://left
            scanf("%d",&n);
            for(int c = 0; c < n; c++){
                y--;
                floor[x][y] = 1;
            }
            break;
        case 2://up
            scanf("%d",&n);
            for(int c = 0; c < n; c++){
                x--;
                floor[x][y] = 1;
            }
            break;
        case 3://right
            scanf("%d",&n);
            for(int c = 0; c < n; c++){
                y++;
                floor[x][y] = 1;
            }
            break;
        }
}

int main(void)
{
    int ins;
    int action;
    printf("%s","Enter the instruction: \n");
    printf("%s","1\t\t笔向上\n2\t\t笔向下\n");
    scanf("%d",&ins);
    while(ins != 9){
        if(ins == 1){
            printf("Enter the action: \n");
            printf("3\t\t右转\n4\t\t左转\n5\t\t向前\n6\t\t打印50乘50的数组\n9\t\t数据结束\n");
            scanf("%d",&action);
            while(action != 9){
                if (action == 3)
                    flag ++;
                else if(action == 4)
                    flag --;
                else if(action == 5)
                    break;
                else if(action == 6)
                    for(int i = 0; i < 50; i++){
                    for(int j = 0; j < 50; j++){
                        if(floor[i][j] == 1)
                            printf("*");
                        else
                            printf(" ");
                    }
                    puts("");
                    }
                scanf("%d",&action);
            }
            act1(flag);
        }
        else if(ins == 2){
             printf("Enter the action: \n");
            printf("3\t\t右转\n4\t\t左转\n5\t\t向前\n6\t\t打印50乘50的数组\n9\t\t数据结束\n");
            scanf("%d",&action);
            while(action != 9){
                if (action == 3)
                    flag ++;
                else if(action == 4)
                    flag --;
                else if(action == 5)
                    break;
                else if(action == 6){
                    for(int i = 0; i < 50; i++){
                        for(int j = 0; j < 50; j++){
                            if(floor[i][j] == 1)
                                printf("*");
                            else
                                printf(" ");
                        }
                        puts("");
                    }
                }
                scanf("%d",&action);
            }
            act2(flag);
        }
        else{
            puts("Error!");
        }
        printf("%s","Enter the instruction: \n");
        scanf("%d",&ins);
    }
    return 0;
}
