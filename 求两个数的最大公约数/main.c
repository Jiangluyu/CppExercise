#include<stdio.h>
int main()
{
    int a, b;
    int d;
    int x, y;
    int z = 1;
    int count = 0;
    printf("Enter the value of a & b:",a,b);
    scanf("%d%d",&a,&b);
    d = a * b;
    if(a < b){
        int c = a;
        a = b;
        b = c;
    }
    while(a % 2 == 0 && b % 2 == 0){
        a /= 2;
        b /= 2;
        count ++;
    }
    x = a;
    y = b;
    while(x - y != y){
        if(x - y > y){
            x = x - y;
        }
        else{
            int c = y;
            y = x - y;
            x = c;
        }
    }
    //最小公倍数
    for(;count > 0; count--){
        z *= 2;
    }
    z *= y;

    printf("The result is %d\n",z);
    printf("The result2 is %d\n",d/z);

}
