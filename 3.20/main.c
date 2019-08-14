#include<stdio.h>
int main(void)
{
    float workhour, rate, salary;
    printf("Enter # of hours worked (-1 to end):");
    scanf("%f",&workhour);
    while(workhour != -1){
        printf("Enter hourly rate of the worker($00.00):");
        scanf("%f",&rate);
        if(workhour <= 40){
            printf("Salary is $%.2f\n",workhour * rate);
        }
        else{
            salary = 40 * rate + 1.5 * rate * (workhour - 40);
            printf("Salary is $%.2f\n",salary);
        }
        printf("Enter # of hours worked (-1 to end):");
        scanf("%f",&workhour);
    }
    return 0;
}
