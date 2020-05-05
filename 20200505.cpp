#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
用一个二维dp，每个点表示以其为右下角的正方形最大边长。然后每次若是1，再和它左上边的三个点最小值+1；
*/

class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
		{
			return 0;
		}
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));

		int ans = 0;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (matrix[i - 1][j - 1] == 0)
				{
					f[i][j] = 0;
				}
				else
				{
					f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
				}
				ans += f[i][j];
			}
		}
		return ans;
	}
};

int main()
{
	vector<int> v1{ 0,1,1,1 };
	vector<int> v2{ 1,1,1,1 };
	vector<int> v3{ 0,1,1,1 };
	vector<vector<int>> v{ v1, v2, v3 };
	Solution s;
	int ret = s.countSquares(v);
	return 0;
}