#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1;
	string s2;
	cin >> s1;
	cin >> s2;
	int count = 0;
	int i = 0;
	int j = 0;
	while (i < s1.size() && j < s2.size())
	{
		if ((s1[i] == s2[j] && s1[i] != '*') || s1[i] == '?')
		{
			i++;
			j++;
		}
		else if (s1[i] == '*')
		{
			count = s1.size() - i - 1;
			while (j < s2.size() - count && (('0' < s2[j] && s2[j] < '9') || ('a' < s2[j] && s2[j] < 'z') || ('A' < s2[j] && s2[j] < 'Z') ) )
			{
				j++;
			}
			i++;
		}
		else
		{
			break;
		}
	}
	if (i == s1.size() && j == s2.size())
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
	system("pause");
	return 0;
}