#include<stdio.h>
int main()
{
    int number;
    int num;
    int value;
    printf("Enter the number of the product:");
    scanf("%d",&number);
    switch(number){

    case 1:
        printf("The value is $2.98.\n");
        scanf("%d",&num);

        value = num * 2.98;
        printf("Total is $%d",value);
        break;
    case 2:
        printf("The value is $4.50.\n");
        scanf("%d",&num);
        value = num * 4.50;
        printf("Total is $%d",value);
        break;
    case 3:
        printf("The value is $9.98.\n");
        scanf("%d",&num);
        value = num * 9.98;
        printf("Total is $%d",value);
        break;
    case 4:
        printf("The value is $4.49.\n");
        scanf("%d",&num);
        value = num * 4.49;
        printf("Total is $%d",value);
        break;
    case 5:
        printf("The value is $6.87.\n");
        scanf("%d",&num);
        value = num * 6.87;
        printf("Total is $%d",value);
        break;
    case'\n':
    case'\t':
    case' ':
        break;

    default:
        printf("%s","Incorrect number entered.");
        puts("Please enter a new number:");
        break;
    }
    return 0;
}
