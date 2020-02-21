#include<iostream>
#include<vector>

using namespace std;

class Solution {
	vector<vector<string>> m_str;

	vector<vector<int>> Nodesign(vector<vector<int>> sign, int row, int col, int n)//为会互相攻击的打上标记
	{
		for (int i = 0; i < n; i++)
		{
			sign[row][i] = 0;
			sign[i][col] = 0;
		}
		int i = row, j = col;
		while (i >= 0 && j >= 0)//标记对角线
		{
			sign[i--][j--] = 0;
		}
		i = row+1; j = col+1;
		while (i < n && j < n)
		{
			sign[i++][j++] = 0;
		}
		i = row - 1; j = col + 1;
		while (i >= 0 && j < n)
		{
			sign[i--][j++] = 0;
		}
		i = row + 1; j = col - 1;
		while (i < n && j >= 0)
		{
			sign[i++][j--] = 0;
		}
		return sign;
	}

	void dfs(vector<vector<int>> sign, int depth, int n, vector<string> site)
	{
		if (depth >= n)
		{
			m_str.push_back(site);
			return;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				vector<string> tmp_site(site);
				if (sign[depth][i])
				{
					tmp_site[depth][i] = 'Q';
					dfs(Nodesign(sign, depth, i, n), depth + 1, n, tmp_site);
				}
			}
		}
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<int>> arr(n, vector<int>(n, 1));//做标记，标记不能放皇后的位置

		//初始化
		string s;
		for(int i = 0; i < n; i++)
		{
			s.push_back('.');
		}
		vector<string> tmp(n, string(s));

		dfs(arr, 0, n, tmp);
		return m_str;
	}
};

int main()
{
	Solution s;
	s.solveNQueens(4);
	return 0;
}