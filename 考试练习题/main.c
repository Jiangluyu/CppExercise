/*(20 ��) 1.WB2201    ��һ�������ڵ���������
��дһ�����򣬸���ָ��������Χ [a ,b] �����е�������һ�������ǡ�õ��ڳ������������������֮�ͣ�������ͳ�Ϊ����
����6����������Ϊ6=1+2+3������1��2��3��6����������
*/

/*#include<stdio.h>
int main(void)
{
    int a,b;
    int sum = 0;
    int count = 0;
    printf("�������������a b (�������Ϊ1-10000): \n");
    scanf("%d %d",&a,&b);
    printf("Output:\n");
    if(a < b){
        printf("%d��%d֮����������Ϊ��",a,b);
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
            printf("û��������");
        }
    }
    else{
        printf("��������!");
    }
    return 0;
}
*/


/*��Ŀ����
��������a�ĳ�ʼֵ������������¸�ֵ���ʽ����֮��a��ֵ��
a-=2

�����ʽ
ֻ��һ�У�����һ������a��

���
�����Ŀ�����б��ʽ�����a��ֵ��ע����β������С�
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


 /*(25 ��) 3.LB3301    ������������֮�������
������������֮���������ע���ж�����Ƿ�Ϊ����ķ�������Ϊ400�ı���Ϊ���꣬��2000�ꣻ����100�ı���������4�ı�����Ϊ���꣬��1996�ꡣ��̿����زģ�
printf("from the date (----/--/--):\n")...��printf("to the date(----/--/--):\n")��printf("Output:\nsum=%d\n"...��
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


