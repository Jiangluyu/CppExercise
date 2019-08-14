#include<stdio.h>
int main(void)
{
    float gallons, miles,sumOfGallons,sumOfMiles;
    sumOfGallons = 0;
    sumOfMiles = 0;
    printf("Enter the gallons used(-1 to end):");
    scanf("%f",&gallons);
    while (gallons != -1){
        printf("Enter the miles driven:");
        scanf("%f",&miles);

        sumOfGallons += gallons;
        sumOfMiles += miles;
        printf("The miles/gallons for this tank was %f\n\n",miles/gallons);
        printf("Enter the gallons used(-1 to end):");
        scanf("%f",&gallons);
    }
    if(sumOfGallons != 0)
        printf("The overall average miles/gallons was %f",sumOfMiles/sumOfGallons);
    else
        printf("False");
    return 0;
}
