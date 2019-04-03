#include<iostream>
#include<stack>

std::stack<int> insert_sort(std::stack<int> input)
{
	std::stack<int> temp;
	std::stack<int> result;

	result.push(input.top());
	input.pop();
	
	while (!input.empty())
	{
		while (input.top() > result.top())
		{
			temp.push(result.top());
			result.pop();
			if (result.empty())
			{
				break;
			}
		} 
		
		result.push(input.top());
		input.pop();
		
		while (!temp.empty())
		{
			result.push(temp.top());
			temp.pop();
		}
	}

	return result;
}

int main(void)
{
	std::stack<int> input;
	
	int a[9] = { 13, 26, 2, 59, 45, 78, 200, 1, 20 };
	for (int i = 0; i < 9; i++)
	{
		input.push(a[i]);
	}

	std::stack<int> sort = insert_sort(input);

	while (!sort.empty())
	{
		std::cout << sort.top() << " ";
		sort.pop();
	}

	system("pause");
}