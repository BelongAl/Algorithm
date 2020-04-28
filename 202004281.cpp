#include<iostream>
#include<vector>

using namespace std;

//f[i][j] = f[i-1][j] + f[i][j-1];

class Soluion {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> f(m, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			f[0][i] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			f[i][0] = 1;
		}
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				f[i][j] = f[i - 1][j] + f[i][j -1];
			}
		}

		return f[m - 1][n - 1];
	}
};

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (obstacleGrid.size() == 0)
		{
			return 0;
		}
		vector<vector<int>> f(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
		for (int i = 0; i < obstacleGrid.size(); i++)
		{
			if (obstacleGrid[i][0] == 1)
			{
				break;
			}
			f[i][0] = 1;
		}
		for (int i = 0; i < obstacleGrid[0].size(); i++)
		{
			if (obstacleGrid[0][i] == 1)
			{
				break;
			}
			f[0][i] = 1;
		}
		for (int i = 1; i < obstacleGrid.size(); i++)
		{
			for (int j = 1; j < obstacleGrid.size(); j++)
			{
				if (obstacleGrid[i][j] == 0)
				{
					f[i][j] = f[i - 1][j] + f[i][j - 1];
				}
			}
		}
		return f[f.size() - 1][f[0].size() - 1];
	}
};

int main()
{

	Solution s;
	vector<vector<int>> v;
	vector<int> a1{ 0,0,0,1,0 };
	vector<int> a2{ 0,1,0,0,0 };
	vector<int> a3{ 0,0,1,0,0 };
	vector<int> a4{ 0,1,0,0,0 };
	vector<int> a5{ 0,0,0,1,0 };
	v.push_back(a1);
	v.push_back(a2);
	v.push_back(a3);
	v.push_back(a4);
	v.push_back(a5);
	int ret = s.uniquePathsWithObstacles(v);

	return 0;
}