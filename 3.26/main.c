#include <stdio.h>
int main(void)
{
    int number,largest,counter;
    largest = 0;
    counter = 0;
    while(counter < 10){
        printf("Enter the value of the number: ");
        scanf("%d",&number);
        if(number >= largest)
            largest = number;
        counter++;
    }
    printf("The largest number is %d",largest);
    return 0;
}
