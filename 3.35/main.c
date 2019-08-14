#include<stdio.h>
int main(void)
{
    int number,a,b,counter;
    a = 1;
    counter = 1;
    printf("Enter the number: ");
    scanf("%d",&number);
    while(number/a != 0){
        a *= 10;
        counter++;
    }
    while(a != 1){
        a /= 10;
        counter++;
    }
    printf("%d",counter);
}
