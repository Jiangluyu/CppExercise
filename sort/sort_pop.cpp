#include<iostream>

using namespace std;

int* bubble_sort(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > 0; j--)
		{
			if (a[j] > a[j - 1])
			{
				int temp;
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}

	return a;
}


int main(void)
{
	int a[9] = { 45,12,3,68,27,1,99,200,5 };
	bubble_sort(a, 9);
	for (int i = 0; i < 9; i++)
	{
		cout << a[i]<<" ";
	}
	system("pause");
}