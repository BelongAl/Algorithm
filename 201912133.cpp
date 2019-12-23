#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		int len = s.size();
		//初始化 F(0) = true;
		vector<bool> canBreak(len+1, false);
		canBreak[0] = true;
		for (int i = 1; i <= len; i++)
		{
			for (int j = i - 1; j >= 0; --j)//求第i个结果
			{
				if (canBreak[j])//查看j-i之间是否在dict中
				{
					unordered_set<string>::iterator tmp1 = dict.find(s.substr(j, i - j));
					unordered_set<string>::iterator tmp2 = dict.end();
					if (tmp1 != tmp2)
					{
						canBreak[i] = true;
						break;
					}
				}
			}
		}
		return canBreak[len];
	}
};

int main()
{
	Solution s;
	string s1("leetcode");
	unordered_set<string> s2;
	s2.insert("leet");
	s2.insert("code");
	cout << s.wordBreak(s1, s2) << endl;
	system("pause");
	return 0;
}