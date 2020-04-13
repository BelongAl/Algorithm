#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

class Solution {
public:
	bool match(string str, string pattern)
	{
		str = " " + str;
		pattern = " " + pattern;
		vector<vector<bool>> v(str.size() + 1, vector<bool>(pattern.size()+1, false));
		v[0][0] = true;
		for (int i = 1; i <= str.size(); i++)
		{
			for (int j = 1; j <= pattern.size(); j++)
			{
				if (str[i - 1] == pattern[j - 1] || pattern[i] == '*')
				{
					//如果相等
					v[i][j] = v[i - 1][j - 1];
				}
				else if (pattern[j - 1] == '*')
				{
					if (str[i - 1] != pattern[j - 2] && pattern[j - 2] != '.')
					{
						//忽略两个
						v[i][j] = v[i][j - 2];
					}
					else
					{
						//忽略一个//忽略两个//忽略多个
						v[i][j] = v[i][j - 1] || v[i][j - 2] || v[i - 1][j];
					}
				}
			}
		}
		return v[str.size()][pattern.size()];
	}
};
int main()
{
	Solution s;
	s.match("aaa", "ab*a*c*a");
	return 0;
}