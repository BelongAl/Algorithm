// write your code here cpp
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		string res;
		//先把第一个单词罗列出
		int i = 0;
		while (i < s.size() && s[i] != '_')
		{
			if (s[i] < 97)
			{
				res.push_back(s[i] + 32);
			}
			else
			{
				res.push_back(s[i]);
			}
			i++;
		}
		bool sign = true;
		i++;
		while (i < s.size())
		{
			if (sign)//首字母大写
			{
				if (s[i] >= 97)
				{
					res.push_back(s[i] - 32);
				}
				else
				{
					res.push_back(s[i]);
				}
				sign = false;
			}
			else
			{
				if (s[i] < 97)
				{
					res.push_back(s[i] + 32);
				}
				else
				{
					res.push_back(s[i]);
				}
			}
			i++;
			if (i < s.size() && s[i] == '_')
			{
				sign = true;
				i++;
			}
		}
		cout << res << endl;
	}
}

