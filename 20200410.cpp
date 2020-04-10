// write your code here cpp
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int bfs(vector<string> &vs, int row, int col, char c, int sign)
{
	int ret = 0;
	if (sign == 1)
	{
		for (int i = col; i >= 0; i--)
		{
			if (vs[row][i] == c)
			{
				ret++;
				if (ret == 4)
				{
					return ret;
				}
			}
			else
			{
				return ret;
			}
		}
		return ret;
	}
	if (sign == 2)
	{
		for (int i = col, j = row; i >= 0 && j >= 0; i--, j--)
		{
			if (vs[j][i] == c)
			{
				ret++;
				if (ret == 4)
				{
					return ret;
				}
			}
			else
			{
				return ret;
			}
		}
		return ret;
	}
	if (sign == 3)
	{
		for (int i = row; i >= 0; i--)
		{
			if (vs[i][col] == c)
			{
				ret++;
				if (ret == 4)
				{
					return ret;
				}
			}
			else
			{
				return ret;
			}
		}
		return ret;
	}
	if (sign == 4)
	{
		for (int i = col, j = row; i < 20 && j >= 0; i++, j--)
		{
			if (vs[j][i] == c)
			{
				ret++;
				if (ret == 4)
				{
					return ret;
				}
			}
			else
			{
				return ret;
			}
		}
		return ret;
	}
	if (sign == 5)
	{
		for (int i = col; i < 20; i++)
		{
			if (vs[row][i] == c)
			{
				ret++;
				if (ret == 4)
				{
					return ret;
				}
			}
			else
			{
				return ret;
			}
		}
		return ret;
	}
	if (sign == 6)
	{
		for (int i = col, j = row; i < 20 && j < 20; i++, j++)
		{
			if (vs[j][i] == c)
			{
				ret++;
				if (ret == 4)
				{
					return ret;
				}
			}
			else
			{
				return ret;
			}
		}
		return ret;
	}
	if (sign == 7)
	{
		for (int i = row; i < 20; i++)
		{
			if (vs[i][col] == c)
			{
				ret++;
				if (ret == 4)
				{
					return ret;
				}
			}
			else
			{
				return ret;
			}
		}
		return ret;
	}
	if (sign == 8)
	{
		for (int i = col, j = row; i >= 0 && j < 20; i--, j++)
		{
			if (vs[j][i] == c)
			{
				ret++;
				if (ret == 4)
				{
					return ret;
				}
			}
			else
			{
				return ret;
			}
		}
		return ret;
	}
}

bool base(vector<string> &vs, int row, int col, char c)
{
	int a = bfs(vs, row, col - 1, c, 1);
	int b = bfs(vs, row - 1, col - 1, c, 2);
	int s = bfs(vs, row - 1, col, c, 3);
	int d = bfs(vs, row - 1, col + 1, c, 4);
	int e = bfs(vs, row, col + 1, c, 5);
	int f = bfs(vs, row + 1, col + 1, c, 6);
	int g = bfs(vs, row + 1, col, c, 7);
	int h = bfs(vs, row + 1, col - 1, c, 8);
	if (a + e + 1 >= 5 ||
		b + f + 1 >= 5 ||
		s + g + 1 >= 5 ||
		d + h + 1 >= 5)
	{
		return true;
	}
	return false;
}

int man()
{
	string s;
	vector<string> vs(20);
	while (cin >> s)
	{
		for (int i = 0; i < 19; i++)
		{
			vs[i] = s;
			cin >> s;
		}

		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("........*...........");
		//vs.push_back(".......+*+++........");
		//vs.push_back("........*...........");
		//vs.push_back("........*...........");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");
		//vs.push_back("....................");

		vs[19] = s;
		bool sign = true;
		for (int i = 1; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (vs[i][j] != '.')
				{
					if (base(vs, i, j, vs[i][j]))
					{
						sign = false;
						cout << "Yes" << endl;
						i = 20;
						break;
					}
				}
			}
			if (!sign)
			{
				break;
			}
		}
		if (sign)
		{
			cout << "No" << endl;
		}
	}

	return 0;
}


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define N 20

int count(string table[], char ch, int x, int y)
{
	int maxc = 0;
	int dir[4][2][2] = { {{ -1,0 },{ 1,0 }},    {{ 0,-1 },{ 0,1 }   },
						 {{ -1,-1 },{ 1,1 }},   {{ -1,1 },{ 1,-1 }} };
	for (int i = 0; i < 4; ++i) // 四种方向
	{
		int c = 0;
		for (int j = 0; j < 2; ++j)  // 两个小方向
		{
			int nx = x, ny = y;
			while (nx >= 0 && nx < N && ny >= 0 && ny < N && table[nx][ny] == ch)
			{
				nx += dir[i][j][0];
				ny += dir[i][j][1];
				++c;
			}
		}
		maxc = (maxc > c ? maxc : c);
	}
	return maxc - 1;
}

bool solve(string table[])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (table[i][j] == '*' || table[i][j] == '+')
				if (count(table, table[i][j], i, j) >= 5)
					return true;
		}
	}
	return false;
}

int main()
{
	string table[N];
	while (cin >> table[0])
	{
		for (int i = 1; i < N; ++i)
		{
			cin >> table[i];
		}
		cout << (solve(table) ? "Yes" : "No"
			) << endl;
	}
	return 0;
}