#include<stdio.h>
int main(void)
{
    int number;
    int count = 1;
    int n;
    long long int total;
    printf("Enter the number:");
    scanf("%d",&number);
    printf("n!\t\tresult\n");
    for(int i = 0; i < number; i++){
        printf("%d!\t\t",count);
        total = 1;
        for(n = count; n > 1; n--){
             total *= n;
        }
        printf("%lld\n",total);
        count++;
    }
    return 0;
}
