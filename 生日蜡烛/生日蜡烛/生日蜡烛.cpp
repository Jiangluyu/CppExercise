// 生日蜡烛.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	for (int i = 1; i <= 100; i++) {
		int sum = 0, j = i;
		while (sum<236) {
			sum += j++;
		}
		if (sum == 236) {
			printf("%d %d\n", i, j);
		}
	}
	return 0;
}