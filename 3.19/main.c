#include<stdio.h>
int main(void)
{
    float loanPrinciple, rate, interest;
    int days;
    printf("Enter loan principle(-1 to end):");
    scanf("%f",&loanPrinciple);

    while(loanPrinciple != -1){
        printf("Enter interest rate:");
        scanf("%f",&rate);
        printf("Enter term of the loan in days:");
        scanf("%d",&days);
        interest = (float)loanPrinciple * rate * days / 365;
        printf("The interest charge is $%.2f\n\n",interest);
        printf("Enter loan principle(-1 to end):");
        scanf("%f",&loanPrinciple);
    }
    return 0;
}
