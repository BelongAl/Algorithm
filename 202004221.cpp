#include<iostream>
#include<vector>

using namespace std;

class Solution {
	int GetSum(int number)
	{
		int ret = 0;
		while (number)
		{
			ret += (number % 10);
			number /= 10;
		}
		return ret;
	}

	void dfs(vector<vector<bool>> &v, int rows, int cols, int i, int j, int k)
	{
		if (i < 0 || j < 0 || i >= rows || j >= cols)
		{
			return;
		}
		else if ((GetSum(i) + GetSum(j)) > k)
		{
			return;
		}
		else if (v[i][j])
		{
			return;
		}
		v[i][j] = true;
		dfs(v, rows, cols, i + 1, j, k);
		dfs(v, rows, cols, i - 1, j, k);
		dfs(v, rows, cols, i, j + 1, k);
		dfs(v, rows, cols, i, j - 1, k);
	}
	
public:
	int movingCount(int threshold, int rows, int cols)
	{
		vector<vector<bool>> v(rows, vector<bool>(cols, false));
		dfs(v, rows, cols, 0, 0, threshold);
		int ret = 0;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (v[i][j])
				{
					ret++;
					cout << "true ";
				}
				else
				{
					cout << "false ";
				}

			}
			cout << endl;
		}
		return ret;
	}
};

int main()
{
	Solution s;
	int ret = s.movingCount(10, 1, 100);
	return 0;
}