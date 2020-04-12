#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

int main()
{
	int number[8] = { 3,3,3,3,3,4,3,4 };
	int arr[91] = {0};
	int j = number[0];
	int count = 2;
	for (int i = 65; i < 91; i++)
	{
		arr[i] = count;
		j--;
		if (j == 0)
		{
			count++;
			j = number[count - 2];
		}
	}
	count = 0;
	int n;
	while (cin >> n)
	{
		if (count > 0)
		{
			cout << endl;
		}
		count++;
		set<string> res;
		while (n--)
		{
			string s;
			cin >> s;
			string tmp;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == '-')
				{
					continue;
				}
				else
				{
					if ('0' <= s[i] && s[i] <= '9')
					{
						tmp.push_back(s[i]);
					}
					else
					{
						tmp.push_back(arr[s[i]] + '0');
					}
					if (tmp.size() == 3)
					{
						tmp.push_back('-');
					}
				}
			}
			res.insert(tmp);
		}
		for (auto e : res)
		{
			cout << e << endl;
		}
	}

 	return 0;
}