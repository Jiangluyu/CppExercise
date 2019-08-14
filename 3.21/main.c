#include<stdio.h>
int main(void)
{
    int i,s;
    s = 0;
    printf("Enter the value of integer i: ");
    scanf("%d",&i);

    while(i >= 0){
        i--;
        s = s+i;
    }
    printf("the value of integer s is %d",s);
    return 0;
}

/*#include<stdio.h>
int main(void)
{
    int i,s;
    s = 0;
    printf("Enter the value of integer i: ");
    scanf("%d",&i);

    while(i >= 0){
        s = s + i;
        i--;
    }
    printf("the value of integer s is %d",s);
    return 0;
}*/
