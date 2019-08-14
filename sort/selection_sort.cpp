#include<iostream>
#include<windows.h>

using namespace std;

int* selsort(int A[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int lowindex = i;
		for (int j = n - 1; j > i; j--)
		{
			if (A[j]< A[lowindex])
				lowindex = j;
			
		}
		swap(A[i], A[lowindex]);
	}
	return A;
}

int* inser_sort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = i; (j > 0) && (a[j] < a[j - 1]); j--)
		{
			swap(a[j], a[j - 1]);
		}
	}
	return a;
}

int main(void)
{
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);//开始计时  

	int a[10] = { 45,23,2,99,10,5,8,13,7,48 };
	//selsort(a, 10);
	inser_sort(a, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " " << ends;
	}

	QueryPerformanceCounter(&nEndTime);//停止计时  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s  
	cout << "运行时间：" << time * 1000 << "ms" << endl;
	cin.get();

}


