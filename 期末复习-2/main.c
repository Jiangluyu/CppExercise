#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *cfptr;
    cfptr = fopen("SB.txt", "r");

    printf("Enter request\n"
           "1 - List accts with zero balances\n"
           "2 - List accts with credit balances\n"
           "3 - List accts with debit balances\n"
           "4 - End of run\n? ");
    unsigned int request;
    scanf("%u", &request);

    while(request != 4)
    {
        unsigned int acctNum;
        double balance;
        char name[30];

        fscanf(cfptr, "%d%29s%lf", &acctNum, name, &balance);

        switch(request){
    case 1:
        puts("\nAccounts with zero balances:");

        while(!feof(cfptr))
        {
            if(balance == 0)
            {
                printf("%-10d%-13s%7.2f\n", acctNum, name, balance);
            }

            fscanf(cfptr, "%d%29s%lf", &acctNum, name, &balance);
        }

        break;
    case 2:
        puts("\nAccounts with credit balances:\n");

        while(!feof(cfptr))
        {
            if(balance > 0)
            {
                printf("%-10d%-13s%7.2f\n", acctNum, name, balance);
            }

            fscanf(cfptr, "%d%29s%lf", &acctNum, name, &balance);
        }

        break;
    case 3:
        puts("\nAccounts with debit balances:\n");

        while(!feof(cfptr))
        {
            if(balance < 0)
            {
                printf("%-10d%-13s%7.2f\n", acctNum, name, balance);
            }

            fscanf(cfptr, "%d%29s%lf", &acctNum, name, &balance);
        }

        break;
        }

        rewind(cfptr);

        printf("\n?");
        scanf("%d", &request);
    }

    puts("End of run.");
    fclose(cfptr);
}
