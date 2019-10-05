
*#include<iostream>
*#include<string>

using namespace std;

class Solution {
public:
	void reverseString(string & s) {
		int i, j;
		for (i = 0, j = s.size() - 1; i < j; i++, j--)
		{
			swap(s[i], s[j]);
		}
	}
	string addStrings(string num1, string num2) {
		string s;
		reverseString(num1);
		reverseString(num2);
		int i = 0;
		char st = NULL;
		while (i < num1.size() && i < num2.size())
		{
			if (num1[i] + num2[i] + st > '0' + '9')
			{
				char t = (num1[i] + num2[i] + st) % ('9'+1);
				st = (num1[i] + num2[i] + st) / ('9'+1);
	
				s.push_back(t);
			
			}
			else
			{
				char t = (num1[i] + num2[i]+st)-'0' ;
				st = NULL;
				s.push_back(t);
			}
			i++;
		}
		while (i < num1.size())
		{
			if (st != NULL)
			{
				if ((st + num1[i]) > '9')
				{
					s.push_back(((st + num1[i])%'9') + '0'-1);
					st = (st + num1[i]) % '9';
				}
				else
				{
					s.push_back(st + num1[i]);
					st = NULL;
				}
			}
			else
			{
				s.push_back(num1[i]);
			}
			i++;
		}
		while (i < num2.size())
		{
			if (st != NULL)
			{
				if ((st + num2[i]) > '9')
				{
					s.push_back(((st + num2[i]) % '9') + '0' - 1);
					st = (st + num2[i]) % '9';
				}
				else
				{
					s.push_back(st + num2[i]);
					st = NULL;
				}
			}
			else
			{
				s.push_back(num2[i]);
			}
			i++;
		}
		if (st != NULL)
		{
			s.push_back(st + '0');
		}
		reverseString(s);
		return s;
	}
};
int main()
{
	Solution sol;
	string s1("983");
	string s2("364");
	cout << sol.addStrings(s1, s2) << endl;
	system("pause");
	return 0;
}