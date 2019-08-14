#include<stdio.h>
int main()
{
    int weightInKilograms;
    printf("Please Enter Your WeightInKilograms:");
    scanf("%d",&weightInKilograms);

    int heightInCentimeters;
    printf("Please Enter Your HeightInCentimeters:");
    scanf("%d",&heightInCentimeters);

    int BMI;
    BMI = weightInKilograms/(heightInCentimeters*heightInCentimeters/10000);
    printf("Your BMI is %d\n",BMI);

    if(BMI < 18.5)
        printf("Underweight");
    else if(BMI<=24.9)
        printf("Normal");
    else if(BMI<=29.9)
        printf("Overweight");
    else
        printf("Obese");

    return 0;
}
