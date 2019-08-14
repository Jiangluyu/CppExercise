#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*FILE *cfptr;
    cfptr = fopen("SB.txt", "w");

    puts("Enter the acctNum, name, balance:\n");

    printf("?");

    unsigned int acctNum;
    char name[30];
    double balance;

    scanf("%d%29s%lf", &acctNum, name, &balance);

    while(!feof(stdin))
    {
        fprintf(cfptr, "%d %s %.2f\n", acctNum, name, balance);
        printf("?");
        scanf("%d%29s%lf", &acctNum, name, &balance);
    }

    fclose(cfptr);*/


    FILE *rfptr;
    rfptr = fopen("SB.txt", "r");


    unsigned int acctNum;
    char name[30];
    double balance;


    printf("%-10s%-13s%s\n", "Account", "Name", "Balance");
    fscanf(rfptr, "%d%29s%lf", &acctNum, name, &balance);

    while(!feof(rfptr))
    {
        printf("%-10d%-13s%7.2f\n", acctNum, name, balance);
        fscanf(rfptr, "%d%29s%lf", &acctNum, name, &balance);
    }

    fclose(rfptr);
}
