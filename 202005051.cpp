#include<string>
#include<iostream>
#include<vector>

using namespace std;

//方法一：回溯
/*
	有*包含两种情况
	1：0次出现 -> d*bc和bc 这样只需要删除p的前两个元素 即  isMatch(s, p.substr(2))
	2：出现1次或多次 -> b*bc bbbc 这样只需要逐个删除s中的首元素然后再调用第一种情况
		b*bc bbbc
		b*bc bbc
		b*bc bc
		bc   bc
*/

class Solution1 {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
		{
			return s.empty();
		}

		bool ismath = !s.empty() && (s[0] == p[0] || p[0] == '.');
		
		if (p.size() > 1 && p[1] == '*')
		{
			return isMatch(s, p.substr(2)) || (ismath && isMatch(s.substr(1), p));
		}
		else
		{
			return ismath && isMatch(s.substr(1), p.substr(1));
		}
	}
};

class Solution {
public:
	bool isMatch(string s, string p) {
		s = " " + s;
		p = " " + p;
		int m = s.size();
		int n = p.size();

		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (s[i - 1] == p[j - 1] || p[j - 1] == '.')//若相等，就直接判断上次是否为true 
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*')//若为*
				{
					if (s[i - 1] != p[j - 2] && p[j - 2] != '.')//若不相等，直接判断它的前两个是否匹配，即出现0次  d*bc和bc
					{
						dp[i][j] = dp[i][j - 2];
					}
					else//出现多次  acb* acbbt
					{
						dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];//表示出现一次 表示出现0次 表示出现n次
					}
				}
			}
	}
};

int main()
{

	return 0;
}