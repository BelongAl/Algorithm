#include<iostream>
#include<vector>

using namespace std;

class Solution
{
	int m_max = 0;
public:
	void fun(vector<vector<int>> board, int a, int b, int count)
	{
		if (a < 0 || b < 0)
		{
			return;
		}
		count += board[a][b];
		if (count > m_max)
		{
			m_max = count;
		}
		fun(board, a - 1, b, count);
		fun(board, a, b - 1, count);
	}
	int getMost(vector<vector<int>> board)
	{
		int a = 2;
		int b = 2;
		int count = 0;
		m_max = 0;
		fun(board, a, b, count);
		return m_max;
	}

};

int main()
{
	Solution s;
	vector<vector<int>> v;
	v.resize(3);
	int k = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			v[i].push_back(k);
			k++;
		}
	}
	cout << s.getMost(v) << endl;
	system("pause");
	return 0;
}


