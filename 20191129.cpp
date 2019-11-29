#include<iostream>

using namespace std;

int main()
{
	int n = 83;
	char tmp[] = "UUDUDDDDUDUUDDDDUDD";
	int index = 1;
	int left, right;
	if (n < 4)
	{
		left = 1;
		right = n;
	}
	else
	{
		left = 1;
		right = 4;
	}
	int j = 0;
	while (tmp[j])
	{
		if (n <= 4)
		{
			if (tmp[j] == 'U')
			{
				index--;
				if (index == 0)
				{
					index = n;
				}
			}
			else
			{
				index++;
				if (index == n + 1)
				{
					index = 1;
				}
			}
		}
		else
		{
			if (tmp[j] == 'U')
			{
				if (index == left)
				{
					left--;
					right--;
				}
				index--;
				if (index == 0)
				{
					index = n;
					left = n - 3;
					right = n;
				}
			}
			else
			{
				if (index == right)
				{
					right++;
					left++;
				}
				index++;
				if (index == n + 1)
				{
					index = 1;
					left = 1;
					right = 4;
				}
			}
		}
		j++;
	}
	for (int i = left; i <= right; i++)
	{
		if (i == right)
		{
			cout << i << endl;
			break;
		}
		cout << i << " ";
	}
	cout << index << endl;
	system("pause");
	return 0;
}




