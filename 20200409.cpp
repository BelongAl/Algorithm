// write your code here cpp
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dfs(vector<int> v, int i, int max)
{
	if (i == v.size() - 1)
	{
		return 1;
	}
	else
	{
		if (v[i + 1] < max)
		{
			return 1;
		}
		else
		{
			return std::max(dfs(v, i + 1, v[i + 1]) + 1, dfs(v, i + 1, max));
		}
	}
}

int min()
{
	int n;
	while (cin >> n)
	{
		vector<int> dance(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> dance[i];
		}
		cout << dfs(dance, 0, 0);
	}
	return 0;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> dance(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> dance[i];
		}
		vector<int> v(n, 1);
		for (int i = n - 2; i >= 0; i--)
		{
			int max = 0;
			for (int j = i + 1; j < n; j++)
			{
				if (dance[j] > dance[i] && v[j] > max)
				{
					max = v[j];
				}
			}
			v[i] += max;
		}
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] > max)
			{
				max = v[i];
			}
		}
		cout << max << endl;
	}
	return 0;
}