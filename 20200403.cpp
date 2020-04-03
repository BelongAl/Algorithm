// write your code here cpp
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main()
{
	string str1;
	string str2;
	while (getline(cin, str1))
	{
		getline(cin, str2);
		//对str1进行解析
		string tmp;
		bool sign = false;
		unordered_map<string, bool> mp;

		for (int i = 0; i < str1.size(); i++)
		{
			if (str1[i] == '"')
			{
				if (tmp.size() != 0)
				{
					string t(tmp.begin() + 1, tmp.end());
					cout << t << endl;
					mp[t] = true;
					i++;
					tmp.clear();
					sign = !sign;
					continue;
				}
				sign = !sign;
			}
			if (str1[i] == ',' && !sign)
			{
				mp[tmp] = true;
				cout << tmp << endl;
				tmp.clear();
				continue;
			}
			tmp.push_back(str1[i]);
		}

		if (tmp.size() != 0)
		{
			cout << tmp << endl;
			mp[tmp] = true;
		}

		if (tmp.size() != 0)
		{
			cout << tmp << endl;
			mp[tmp] = true;
		}
		if (mp[str2])
		{
			cout << "Ignore" << endl;
		}
		else
		{
			cout << "Important" << endl;
		}
	}


	return 0;
}