#include<stdio.h>
int i,num1,num2,result;
int printMenu()
{
    printf("1--�ӷ�\n");
    printf("2--����\n");
    printf("3--�˷�\n");
    printf("4--����\n");
    printf("0--�˳�\n");
}

int getChoice()
{
    printf("���������ѡ�0--4��:\n");
    scanf("%d",&i);
    return i;
}

int doAdd()
{
    printf("�������һ������:\n");
    scanf("%d",&num1);
    printf("������ڶ�������:\n");
    scanf("%d",&num2);
    result = num1 + num2;
    printf("%d + %d = %d\n\n",num1,num2,result);
}

int doMinus()
{
    printf("�������һ������:\n");
    scanf("%d",&num1);
    printf("������ڶ�������:\n");
    scanf("%d",&num2);
    result = num1 - num2;
    printf("%d - %d = %d\n\n",num1,num2,result);
}

int doMultiply()
{
    printf("�������һ������:\n");
    scanf("%d",&num1);
    printf("������ڶ�������:\n");
    scanf("%d",&num2);
    result = num1 * num2;
    printf("%d * %d = %d\n\n",num1,num2,result);
}

int doDivide()
{
    printf("�������һ������:\n");
    scanf("%d",&num1);
    printf("������ڶ�������:\n");
    scanf("%d",&num2);
    while(num2 == 0){
        printf("����Ϊ0������������\n");
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
