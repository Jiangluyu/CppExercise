#include<stdio.h>
#include<string.h>

int i = 0;
char str0[999];
char str[999];

int testPalindrome(char x[],int up,int down)
{
    if(up<=down)
       return 1;

    if(x[down]==x[up])
        return testPalindrome(x,up-1,down+1);
    else
       return 0;

}


int main(void)
{
    int j = 0;
    int k = 0;
    gets(str0);
    while(str0[k]!='\0'){
        str[j] = str0[k];
        k++;
        if((str0[k-1]>=65&&str0[k-1]<=90)||(str0[k-1]>=97&str0[k-1]<=122)||(str0[k-1]>=48&&str0[k-1]<=57))
            j++;
    }
    printf("%s\n",str);
    int value = testPalindrome(str,strlen(str)-1,0);
    printf("%d", value);
    return 0;
}
