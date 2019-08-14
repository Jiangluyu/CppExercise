#include<stdio.h>
#include<string.h>
int main(void)
{
 char data[100];
 int len=0;
 int i,j;
 int num_10=0;
 printf("请输入一二进制数：");
 scanf("%s",data);
 while(data[len]!='\0')
  len++;
 for(i=0;i<len;i++)
  num_10=num_10*2+data[i]-'0';
 printf("对应的十进制数为：%d\n",num_10);
 printf("对应的8进制数为：");
 if(len%3==0)
 {
  for(i=0;i<len;i=i+3)
  {
   int temp=0;
   for(j=i;j<i+3;j++)
    temp=temp*2+data[j]-'0';
   printf("%d",temp);
  }
  printf("\n");
 }
 else if(len%3==1)
 {
  printf("%c",data[0]);
  for(i=1;i<len;i=i+3)
  {
   int temp=0;
   for(j=i;j<i+3;j++)
    temp=temp*2+data[j]-'0';
   printf("%d",temp);
  }
  printf("\n");
 }
 else
 {
  int temp=0;
  temp=(data[0]-'0')*2+data[1]-'0';
  printf("%d",temp);
  for(i=2;i<len;i=i+3)
  {
   int temp=0;
   for(j=i;j<i+3;j++)
    temp=temp*2+data[j]-'0';
   printf("%d",temp);
  }
  printf("\n");
 }
 return 0;
}
