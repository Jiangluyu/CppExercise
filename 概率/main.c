#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<math.h>
#define Totalballs 100
#define Time 100
int main()
{
	srand(time(NULL));
	int box[Totalballs] = {0}, num_blackballs[Time] = { 0 }, num_whiteballs[Time] = { 0 };
	int blackballs=rand()%100+1;
	int whiteballs = Totalballs - blackballs;
	//������ɺڰ������
	int count = 0;
	do {
		int setballs = rand() % 100;
		if (box[setballs] == 0)
		{
			box[setballs] = 1;
			count++;
		}
	} while (count != whiteballs);
	//���ڰ���������������,�Ǻ���Ϊ0������Ϊ1
	for(int i=0;i<Time;i++)	//�����ȡ�ڰ����ظ�50��
		for (int j=0; j < 300; j++)
		{
			int pickballs = rand() % 100;//�����ȡ��n��λ��
			if (box[pickballs] == 0) //��¼�³鵽�ڣ��������
				num_blackballs[i]++;
			else
				num_whiteballs[i]++;
		}
	float avg_blackballs,sum=0;
	for (int i=0; i< Time; i++)
	{
		sum += num_blackballs[i];
	}
	avg_blackballs = sum / Time;//��������ֵ
	printf("����/����\n");
	for (int i = 0; i < Time; i++)
	{
		if (i % 5 == 0)
			puts("");
		printf("%d/%d  ", num_blackballs[i], num_whiteballs[i]);
	}
	float S=0.00;
	for (int i = 0; i < Time; i++)
	{
		S += pow((float)num_blackballs[i] - avg_blackballs, 2);
	}
	S = sqrt((1.0 / ((float)Time - 1.0))*S);
	printf("\n�����ֵ%.2f,��׼��%f\n", avg_blackballs,S);
	printf("ʵ�ʺ������%d,�������%d\n", blackballs, whiteballs);
	system("pause");
}
