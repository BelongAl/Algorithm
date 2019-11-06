#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	string ret;
	getline(cin, s);
	int k = s.size() - 1;
	for (int i = s.size(); i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			for (int j = i + 1; j <= k; j++)
			{
				ret.push_back(s[j]);
			}
			k = i - 1;
			ret.push_back(s[i]);
		}
	}
	k = 0;
	while (s[k] != ' ')
	{
		ret.push_back(s[k]);
		k ++;
	}
	cout << ret << endl;
	system("pause");
	return 0;
}