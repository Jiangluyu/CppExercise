 /*(25 ��) 5.LB2301    дһ���򵥼���������
��дһ���򵥼��������������ʽΪ��data1 op data2������data1��data2�ǲμ������������(data1��data2���붨��Ϊint����������ӿ��ܳ���int�ܱ�ʾ�ķ�Χ)��opΪ�����������ȡֵֻ����+��-��*��/��%��
���������������С�������λ����������������������̿����زģ�printf("Please input data1 op data2: ")...��printf("\nError! chu shu wei 0.\n")...��
�������������Ч��Ӧ���Ƶ���ͼ1��ͼ2��ͼ3��ͼ4��ͼ5��ʾ��ͼ1�е�3000 + 2000��ͼ2�е�3000 % 2000��ͼ3�е�3000 % 0��ͼ4�е�3000 / 0��ͼ5�е�3500 / 200�ǴӼ�����������ݡ�
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

