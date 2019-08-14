#include<stdio.h>
int main(void)
{
    unsigned int counter,number,largest;
    largest = 0;
    counter = 0;
    while(counter < 10){
        printf("Enter the value of sale:");
        scanf("%u",&number);
        if(number >= largest){
            largest = number;
        counter++;
        }
    }
    printf("The largest is %d",largest);
    return 0;
}
