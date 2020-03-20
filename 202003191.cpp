#include<iostream>
#include<map>
#include<vector>

using namespace std;
class Solution {
	bool JudgeAround(vector<vector<char>>& board, int row, int col, map<pair<int, int>, bool> &sign)
	{
		if (col == 0 ||
			col == board[0].size() - 1 ||
			row == 0 ||
			row == board.size() - 1)
		{
			return false;
		}

		sign[make_pair(row, col)] = true;

		if ((board[row - 1][col] == 'X' || sign[make_pair(row - 1, col)]) &&
			(board[row + 1][col] == 'X' || sign[make_pair(row + 1, col)]) &&
			(board[row][col - 1] == 'X' || sign[make_pair(row, col - 1)]) &&
			(board[row][col + 1] == 'X' || sign[make_pair(row, col + 1)]))
		{
			return true;
		}

		bool arr[4] = { true, true, true, true };


		if (board[row + 1][col] == 'O' && !sign[make_pair(row + 1, col)])
		{
			arr[0] = JudgeAround(board, row + 1, col, sign);
		}
		if (board[row - 1][col] == 'O' && !sign[make_pair(row - 1, col)])
		{
			arr[1] = JudgeAround(board, row - 1, col, sign);
		}
		if (board[row][col + 1] == 'O' && !sign[make_pair(row, col + 1)])
		{
			arr[2] = JudgeAround(board, row, col + 1, sign);
		}
		if (board[row][col - 1] == 'O' && !sign[make_pair(row, col - 1)])
		{
			arr[3] = JudgeAround(board, row, col - 1, sign);
		}
		for (int i = 0; i < 4; i++)
		{
			if (arr[i] == false)
			{
				return false;
			}
		}

		return true;
	}

public:
	void solve(vector<vector<char>>& board) {
		if (board.size() <= 2 || board[0].size() <= 2)
		{
			return;
		}


		for (int i = 1; i < board.size() - 1; i++)
		{
			for (int j = 1; j < board[0].size() - 1; j++)
			{
				map<pair<int, int>, bool> sign;
				if (board[i][j] == 'O')
				{
					if (JudgeAround(board, i, j, sign))
					{
						for (auto e : sign)
						{
							board[e.first.first][e.first.second] = 'X';
						}					
					}
				}
			}
		}
	}
};
int main()
{

	vector<char> arr1{ 'O','O','O','O','X','X' };
	vector<char> arr2{ 'O','O','O','O','O','O' };
	vector<char> arr3{ 'O','X','O','X','O','O' };
	vector<char> arr4{ 'O','X','O','O','X','O' };
	vector<char> arr5{ 'O','X','O','X','O','O' };
	vector<char> arr6{ 'O','X','O','O','O','O' };
	vector<vector<char>> vc;
	vc.push_back(arr1);
	vc.push_back(arr2);
	vc.push_back(arr3);
	vc.push_back(arr4);
	vc.push_back(arr5);

	Solution s;
	s.solve(vc);
	
	return 0;
}