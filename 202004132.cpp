#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

void bfs(int n, int m, int i, vector<int> tmp, vector<vector<int>> &res, int count)
{
	if (count > m)
	{
		return;
	}
	else if (count == m)
	{
		res.push_back(tmp);
		return;
	}
	else
	{
		for (int j = i + 1; j < n; j++)
		{
			tmp.push_back(j);
			bfs(n, m, j, tmp, res, count + j);
			tmp.pop_back();
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> res;

	for (int i = 1; i <= n; i++)
	{
		vector<int> tmp;
		tmp.push_back(i);
		bfs(n, m, i, tmp, res, i);
	}

	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
