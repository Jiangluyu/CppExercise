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
	//随机生成黑白球个数
	int count = 0;
	do {
		int setballs = rand() % 100;
		if (box[setballs] == 0)
		{
			box[setballs] = 1;
			count++;
		}
	} while (count != whiteballs);
	//将黑白球随机放入盒子中,记黑球为0，白球为1
	for(int i=0;i<Time;i++)	//随机抽取黑白球，重复50次
		for (int j=0; j < 300; j++)
		{
			int pickballs = rand() % 100;//随机抽取第n号位球
			if (box[pickballs] == 0) //记录下抽到黑，白球次数
				num_blackballs[i]++;
			else
				num_whiteballs[i]++;
		}
	float avg_blackballs,sum=0;
	for (int i=0; i< Time; i++)
	{
		sum += num_blackballs[i];
	}
	avg_blackballs = sum / Time;//计算黑球均值
	printf("黑球/白球\n");
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
	printf("\n黑球均值%.2f,标准差%f\n", avg_blackballs,S);
	printf("实际黑球个数%d,白球个数%d\n", blackballs, whiteballs);
	system("pause");
}
