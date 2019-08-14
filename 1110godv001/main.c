#include<stdio.h>
int i,num1,num2,result;
int printMenu()
{
    printf("1--加法\n");
    printf("2--减法\n");
    printf("3--乘法\n");
    printf("4--除法\n");
    printf("0--退出\n");
}

int getChoice()
{
    printf("请输入你的选项（0--4）:\n");
    scanf("%d",&i);
    return i;
}

int doAdd()
{
    printf("请输入第一个整数:\n");
    scanf("%d",&num1);
    printf("请输入第二个整数:\n");
    scanf("%d",&num2);
    result = num1 + num2;
    printf("%d + %d = %d\n\n",num1,num2,result);
}

int doMinus()
{
    printf("请输入第一个整数:\n");
    scanf("%d",&num1);
    printf("请输入第二个整数:\n");
    scanf("%d",&num2);
    result = num1 - num2;
    printf("%d - %d = %d\n\n",num1,num2,result);
}

int doMultiply()
{
    printf("请输入第一个整数:\n");
    scanf("%d",&num1);
    printf("请输入第二个整数:\n");
    scanf("%d",&num2);
    result = num1 * num2;
    printf("%d * %d = %d\n\n",num1,num2,result);
}

int doDivide()
{
    printf("请输入第一个整数:\n");
    scanf("%d",&num1);
    printf("请输入第二个整数:\n");
    scanf("%d",&num2);
    while(num2 == 0){
        printf("除数为0，请重新输入\n");
        scanf("%d",&num2);
    }
    result = num1 / num2;
    printf("%d / %d = %d\n\n",num1,num2,result);
}

int main(void)
{
    do{
        printMenu();
        i = getChoice();
        switch(i){
            case 1:
                doAdd();
                break;

            case 2:
                doMinus();
                break;

            case 3:
                doMultiply();
                break;

            case 4:
                doDivide();
                break;
        }
    }while(i != 0);
}
