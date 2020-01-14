/*Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids.How many unique paths would there be ?

An obstacle and empty space is marked as1and0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.*/


#include<iostream>
#include<vector>

class Solution {
public:
	int uniquePathsWithObstacles(std::vector<std::vector<int> > &obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		{
			return 0;
		}

		std::vector<std::vector<int>> path(m, std::vector<int>(n,0));

		for (int i = 0; i < m; i++)
		{
			if (obstacleGrid[i][0] == 0)
			{
				path[i][0] = 1;
			}
			else
			{
				break;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (obstacleGrid[0][i] == 0)
			{
				path[0][i] = 1;
			}
			else
			{
				break;
			}
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (obstacleGrid[i][j] == 1)
				{
					path[i][j] = 0;
				}
				else
				{
					path[i][j] = path[i - 1][j] + path[i][j - 1];
				}
			}
		}

		return path[m - 1][n - 1];

	}
};

int main()
{
	return 0;
}
