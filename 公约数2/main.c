#include<stdio.h>
int main()
{
    int num1, num2, tmp;
    scanf("%d%d",&num1,&num2);
    if(num1 < num2){
        tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
    int z = num1 * num2;
    tmp = num1 % num2;
    while(tmp != 0){
        num1 = num2;
        num2 = tmp;
        tmp = num1 % num2;
    }
    printf("The result is %d\n",num2);
    printf("The result2 is %d\n",z/num2);
}
