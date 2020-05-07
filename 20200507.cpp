#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int m = s.size();
		vector<vector<bool>> v(m, vector<bool>(m, false));
		//≥ı ºªØ
		for (int i = 0; i < m; i++)
		{
			v[i][i] = true;
		}
		int k = 1;
		vector<int> ret(2, 0);
		while (k < m)
		{
			int row = 0;
			int col = k;
			while (col < m)
			{
				if (s[row] == s[col] && (v[row + 1][col-1] || col - row == 1))
				{
					v[row][col] = true;
					if (col - row > ret[1] - ret[0])
					{
						ret[1] = col;
						ret[0] = row;
					}
				}
				row++;
				col++;
			}
			k++;
		}
		string res(s.begin() + ret[0], s.begin() + ret[1] + 1);
		return res;
	}
};

int main()
{
	string s1("cbbd");
	Solution s;
	s.longestPalindrome(s1);
	return 0;
}