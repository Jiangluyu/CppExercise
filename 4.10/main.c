#include<stdio.h>
int main(void)
{
    int i = 0;
    int n;
    unsigned int count = 0;
    printf("Enter the number:");
    scanf("%d",&n);
    while(n != 9999){
        i += n;
        count += 1;
        scanf("%d",&n);
    }
    printf("The average is: %d",i/count);
    return 0;
}
