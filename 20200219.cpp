#include<iostream>
#include<vector>
#include<map>

using namespace std;


class Solution {
	int m_maxpath = 0; 

	void path(vector<vector<int>> matrix, vector<vector<int>> sign, int row, int col, int pathnumber)
	{
		pathnumber++;
		if (pathnumber > m_maxpath)
		{
			m_maxpath = pathnumber;
		}
		if ((row == 0 || sign[row - 1][col] == 1) &&
			(row == matrix.size() - 1 || sign[row + 1][col] == 1) &&
			(col == 0 || sign[row][col - 1] == 1) &&
			(col == matrix[0].size() - 1 || sign[row][col + 1] == 1))

		{
			return;
		}
		else
		{
			sign[row][col] = 1;//标记已走过
			if (row != 0 && sign[row - 1][col] != 1 && matrix[row-1][col] < matrix[row][col])
			{
				path(matrix, sign, row-1, col,pathnumber );
			}
			if (row != matrix.size() - 1 && sign[row + 1][col] != 1 && matrix[row +1][col] < matrix[row][col])
			{
				path(matrix, sign, row + 1, col, pathnumber);
			}
			if (col != 0 && sign[row][col - 1] != 1 && matrix[row][col-1] < matrix[row][col])
			{
				path(matrix, sign, row, col-1, pathnumber);
			}
			if (col != matrix[0].size() - 1 && sign[row][col + 1] != 1 && matrix[row][col+1] < matrix[row][col])
			{
				path(matrix, sign, row, col+1, pathnumber);
			}
		}
	}

public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				vector<vector<int>> sign(matrix.size(), vector<int>(matrix[0].size(), 0));
				path(matrix, sign, i, j, 0);
			}
		}
		return m_maxpath;
	}
};

int main()
{
	vector<vector<int>> v;
	v.push_back(vector<int>{9, 9, 4});
	v.push_back(vector<int>{6, 6, 8});
	v.push_back(vector<int>{2, 1, 1});

	Solution s;
	s.longestIncreasingPath(v);

	return 0;
}