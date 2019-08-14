 /*(25 分) 5.LB2301    写一个简单计算器程序，
编写一个简单计算器程序，输入格式为：data1 op data2。其中data1和data2是参加运算的两个数(data1、data2必须定义为int，但二者相加可能超出int能表示的范围)，op为运算符，它的取值只能是+、-、*、/、%。
输出：计算除法输出小数点后两位，其他运算均输出整数。编程可用素材：printf("Please input data1 op data2: ")...、printf("\nError! chu shu wei 0.\n")...。
　　程序的运行效果应类似地如图1、图2、图3、图4、图5所示，图1中的3000 + 2000、图2中的3000 % 2000、图3中的3000 % 0、图4中的3000 / 0和图5中的3500 / 200是从键盘输入的内容。
*/
/*
#include<stdio.h>
#include<math.h>
int main(void)
{
    int data1, data2, result;
    char op;
    printf("Please input data1 op data2: ");
    scanf("%d %c %d",&data1,&op,&data2);
    printf("Output:\n");
    if(op == '+'){
        result = data1 + data2;
    }
    else if(op == '-'){
        result = data1 - data2;
    }
    else if(op == '*'){
        result = data1 * data2;
    }
    else if(op == '/'){
        if(data2 == 0){
            printf("Error! Chu shu wei 0.");
        }
        else{
            result = data1 / data2;
        }
    }
    else if(op == '%'){
            if(data2 == 0){
                printf("Error! Chu shu wei 0.");
            }
            else{
                result = data1 % data2;
            }
    }
    printf("%d%c%d=%d",data1,op,data2,result);
}
*/

