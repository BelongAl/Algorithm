#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int MaxValue(vector<int> a, vector<int> v, int capacity)
{
	vector<vector<int>> val(a.size() + 1, vector<int>(capacity + 1, 0));

	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= capacity; j++)
		{
			if (j >= a[i-1])
			{
				val[i][j] = max(val[i - 1][j], val[i - 1][j - a[i-1]] + v[i-1]);
			}
			else
			{
				val[i][j] = val[i - 1][j];
			}
		}
	}
	return val[a.size()][capacity];
}

int main()
{
	vector<int> a{ 2,3,8 };
	vector<int> v{ 2,5,8 };
	MaxValue(a, v, 10);
	return 0;
}