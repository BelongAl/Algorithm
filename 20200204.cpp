#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		//find effect str
		string effect;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				continue;
			}
			else if (str[i] == '+' || str[i] == '-')
			{
				effect.push_back(str[i]);
				i++;
				if (str[i] < '0' || str[i] > '9')
				{
					return 0;
				}
				while (i < str.size() && '0' <= str[i] && str[i] <= '9')
				{
					if (str[i] == '0' && effect.size() == 1)
					{
						i++;
						continue;
					}
					effect.push_back(str[i++]);
				}
				break;
			}
			else if (str[i] < '0' || str[i] > '9')
			{
				return 0;
			}
			while (i < str.size() && '0' <= str[i] && str[i] <= '9')
			{
				if (effect.size() == 0 && str[i] == '0')
				{
					i++;
					continue;
				}
				effect.push_back(str[i++]);
			}
			break;
		}
		//transformation
		long long ret = 0;
		int index = 0;
		int i = 0;
		if (effect[i] == '-' || effect[i] == '+')
		{
			if (effect[i] == '-')
			{
				index = 1;
			}
			i++;
		}
		long long digit = 1;
		for (int j = effect.size() - 1; j >= i; j--)
		{
			int tmp = effect[j] - '0';
			ret += tmp * digit;
			digit *= 10;
			if (ret > INT32_MAX)
			{
				if (index == 1)
				{
					return INT32_MIN;
				}
				else
				{
					return INT32_MAX;
				}
			}
		}
		if (index == 1)
		{
			ret *= -1;
		}
		return ret;
	}

};

int main()
{
	char st[21] = "20000000000000000000";

	string str(st,st+21);

	Solution s;
	s.myAtoi(str);

	system("pause");
	return 0;
}