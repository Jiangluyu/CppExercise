/*#include<stdio.h>
int fibonacci(unsigned int n)
{
    unsigned long long int result;
    if(n == 1||n == 2)
        return 1;
    else{
        result = fibonacci(n - 1)+fibonacci(n - 2);
        return result;
    }
}

int main(void)
{
    unsigned int num;
    scanf("%u",&num);
    printf("%u\t%llu\n",num,fibonacci(num));
    return 0;
}
*/
/*#include <stdio.h>
int fibonacci(unsigned int n)
{
    unsigned long long int a = 1;
    unsigned long long int b = 1;
    unsigned long long int c = a;
    for (int i = 3;i <= n;i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(void)
{
    unsigned int n;
    scanf("%u",&n);
    printf("%u\t%llu",n,fibonacci(n));
    return 0;
}*/

/* 斐波那契数列的尾递归写法 */
#include <stdio.h>

double fib(double n, double a, double b)
{
    if(n<=0.0)
        return -1.0;   //错误输入
    else if(n==1.0 || n==2.0)
        return b;  //b记录最靠后的一项
    else
    {
        while(n>2.0)
            return fib(n-1.0, b, a+b);
    }
}

int main(int argc, char *argv[])
{
    double d, n = 20.0;

    d = fib(n, 1.0, 1.0);

    printf("斐波那契数列第 %.f 项的值为 %.f。\n", n, d);

    return 0;
}
