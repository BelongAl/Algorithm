#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;

void dfs(int val, string s, int num, int &count, int i, vector<int> &money, map<string, bool> &m)
{
	if (num == val)
	{
		s.pop_back();
		if (!m[s])
		{
			m[s] = true;
			if (count == 0)
			{
				cout << s;
				count = 1;
				return;
			}
			else
			{
				cout << ';' << s;
				return;
			}
		}
	}
	if (i == money.size())
	{
		return;
	}
	string stmp = s;
	stmp += to_string(money[i]);
	stmp.push_back(',');
	dfs(val, s, num, count, i + 1, money, m);
	dfs(val, stmp, num + money[i], count, i + 1, money, m);
}

int main()
{
	string s;
	cin >> s;
	vector<int> money;
	vector<int> goods;
	int i = 0;
	for (i; i < s.size(); i++)
	{
		if ('0' < s[i] < '9')
		{
			string tmp;
			while (i < s.size() && s[i] != ',' && s[i] != ';')
			{
				tmp.push_back(s[i]);
				i++;
			}
			money.push_back(atoi(tmp.c_str()));
		}
		if (s[i] == ';')
		{
			i++;
			break;
		}
	}

	for (i; i < s.size(); i++)
	{
		if ('0' < s[i] < '9')
		{
			string tmp;
			while (i < s.size() && s[i] != ',')
			{
				tmp.push_back(s[i]);
				i++;
			}
			goods.push_back(atoi(tmp.c_str()));
		}
		if (s[i] == ';')
		{
			break;
		}
	}

	sort(money.begin(), money.end());
	s.clear();
	int count = 0;
	map<string, bool> m;
	dfs(goods[0], s, 0, count, 0, money, m);

	return 0;
}
