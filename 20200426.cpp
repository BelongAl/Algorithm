#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<set>
#include<vector>
#include<stack>

using namespace std;

void getDNS_PATH(string s, string &dns, string &path)
{
	int i = 7;
	bool sign = true;
	for (i; i < s.size(); i++)
	{
		if (s[i] == '/')
		{
			sign = false;
			break;
		}
	}
	if (sign)
	{
		string ret(s.begin() + 7, s.end());
		dns = ret;
		path = ' ';
	}
	else
	{
		string ret(s.begin() + 7, s.begin() + i);
		dns = ret;
		string p(s.begin() + i + 1, s.end());
		path = p;
	}
}

int main()
{
	int n;
	cin >> n;
	int max = n;
	unordered_map<string, int> m;//域名对应的下标
	vector<set<string>> vs(n + 1);//每个域名的搜索路径
	vector<string> vst(n);
	int k = 1;
	while (n--)
	{
		string tmp;
		cin >> tmp;
		//1：拿到域名,拿到搜索路径
		string dns;
		string path;
		getDNS_PATH(tmp, dns, path);
		if (0 == m[dns])
		{
			m[dns] = k;
			vst[k] = dns;
			k++;
		}
		vs[m[dns]].insert(path);
	}

	map<set<string>, vector<string>> ret;
	for (int i = 1; i < k - 1; i++)
	{
		if (ret[vs[i]].size() == 0)
		{
			for (int j = i + 1; j < k; j++)
			{
				if (vs[i] == vs[j])
				{
					ret[vs[i]].push_back(vst[j]);
				}
			}
			if (ret[vs[i]].size() > 0)
			{
				ret[vs[i]].push_back(vst[i]);
			}
		}
	}

	int count = 0;
	for (auto e : ret)
	{
		if (e.second.size() > 1)
		{
			count++;
		}
	}

	cout << count << endl;
	for (auto e : ret)
	{
		if (e.second.size() > 1)
		{
			for (int i = 0; i < e.second.size(); i++)
			{
				cout << "http://";
				cout << e.second[i] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}

