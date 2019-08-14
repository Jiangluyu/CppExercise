/*(20 分) 1.WB2201    求一个区间内的所有完数
请写一个程序，给出指定整数范围 [a ,b] 内所有的完数，一个数如果恰好等于除它本身外的所有因子之和，这个数就称为完数
例如6是完数，因为6=1+2+3，其中1，2，3是6的所有因子
*/

/*#include<stdio.h>
int main(void)
{
    int a,b;
    int sum = 0;
    int count = 0;
    printf("请输入查找区间a b (最大区间为1-10000): \n");
    scanf("%d %d",&a,&b);
    printf("Output:\n");
    if(a < b){
        printf("%d到%d之间的完数情况为：",a,b);
        for(int num = a; num <= b; num ++){
            sum = num;
            for(int i = 1; i < num; i++){
                if(num % i == 0){
                    sum -= i;
                }
            }
            if(sum == 0){
                printf("%d ",num);
                count++;
            }
        }
        if(count == 0){
            printf("没有完数！");
        }
    }
    else{
        printf("输入有误!");
    }
    return 0;
}
*/


/*题目描述
给定变量a的初始值，计算进行如下赋值表达式计算之后a的值：
a-=2

输入格式
只有一行，包含一个整数a。

输出
输出题目描述中表达式运算后a的值。注意行尾输出换行。
*/


/*#include<stdio.h>
int main(void)
{
    int a;
    printf("Input:");
    scanf("%d",&a);
    a -= 2;
    printf("Output:\n%d",a);
    return 0;
}*/


 /*(25 分) 3.LB3301    计算两个日期之间的天数
计算两个日期之间的天数。注：判断年份是否为闰年的方法——为400的倍数为闰年，如2000年；若非100的倍数，而是4的倍数，为闰年，如1996年。编程可用素材：
printf("from the date (----/--/--):\n")...、printf("to the date(----/--/--):\n")、printf("Output:\nsum=%d\n"...。
*/

#include<stdio.h>
int main(void)
{
    int y1,y2,m1,m2,d1,d2;
    int count = 0;
    int sum = 0;
    printf("from the date (****/**/**):\n");
    scanf("%d/%d/%d",&y1,&m1,&d1);
    printf("to the date (****/**/**):\n");
    scanf("%d/%d/%d",&y2,&m2,&d2);

    int run[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    int ping[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(y1 > y2){
        int temp;
        temp = y1;
        y1 = y2;
        y2 = temp;
        temp = m1;
        m1 = m2;
        m2 = temp;
        temp = d1;
        d1 = d2;
        d2 = temp;
    }
    if(y1 < y2){
        if((y1 % 400 == 0)||(y1 % 4 == 0 && y1 % 100 != 0)){
            for(int i = 12; i > m1; i--){
                sum += run[i-1];
            }
            sum += run[m1-1] - d1;
        }
        else{
            for(int i = 12; i > m1; i--){
                sum += ping[i-1];
            }
            sum += ping[m1-1] - d1;
        }
        if((y2 % 400 == 0)||(y2 % 4 == 0 && y2 % 100 != 0)){
            for(int i = 1; i < m2; i++){
                sum += run[i-1];
            }
            sum += d2;
        }
        else{
            for(int i = 1; i < m2; i++){
                sum += ping[i-1];
            }
            sum += d2;
        }
        for(int i = y1 + 1; i < y2; i++){
            if((i % 400 == 0)||(i % 4 == 0 && i % 100 != 0)){
                count++;
            }
        }
        sum += 366*count + 365*(y2 - y1 - count -1);
    }
    else if(y1 == y2){
            if(m2 > m1){
                if((y1 % 400 == 0)||(y1 % 4 == 0 && y1 % 100 != 0)){
                    for(int i = m2 - 1; i > m1; i--){
                        sum += run[i-1];
                    }
                    sum += d2 + run[m1-1] - d1;
                }
                else{
                    for(int i = m2 - 1; i > m1; i--){
                        sum += ping[i-1];
                    }
                    sum += d2 + ping[m1-1] - d1;
                }
            }
            else{
                sum = d2 - d1;
            }
    }
    printf("Output:\nsum=%d",sum);

    return 0;
}


