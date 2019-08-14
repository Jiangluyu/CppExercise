//输入十个学生的成绩，计算平均值，打印成绩并显示与平均分的比较结果
#include<stdio.h>
int main(void)
{
    int array[10];
    int average;
    int sum = 0;
    for(int i = 0; i < 10; i++){
        printf("Please enter grade %d\n", i+1);
        scanf("%d",&array[i]);
        sum += array[i];
    }
    average = (sum)/10;
    for(int a = 0; a < 10; a++){
        printf("Grade %d is %d\n", a+1, array[a]);
        if(array[a] > average){
            printf("Upper\n\n");
        }
        else if(array[a] == average){
            printf("Right\n\n");
        }
        else{
            printf("Downer\n\n");
        }
    }
    return 0;
}
