#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

//F[i]：s前i个字符是否能被成功分割
//F[i] = 
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		vector<bool> f(s.size() + 1, false);
		f[0] = true;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; j >= 0; j--)
			{
				if (f[j])
				{
					string tmp(s.begin() + j, s.begin() + i + 1);
					if (dict.find(tmp) != dict.end())
					{
						f[i + 1] = true;
						break;
					}
				}
			}
		}
		return f[f.size() - 1];
	}
};

int main()
{

	return 0;
}