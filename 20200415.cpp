#include<iostream>

using namespace std;

class Solution {
public:
	bool isNumeric(char* string)
	{
		int i = 0;
		int count = 0;
		int point = 0;
		while (string[i] != '\0')
		{
			if ('0' <= string[i] && string[i] <= '9')
			{
				i++;
			}
			else if ((string[i] == '-' || string[i] == '+') &&
				(i == 0 || (count == 1 && (string[i - 1] == 'e' || string[i - 1] == 'E'))))
			{
				i++;
			}
			else if(string[i] == 'e' || string[i] == 'E' && count == 0)
			{
				if (string[i + 1] == '\0')
				{
					return false;
				}
				i++;
				count++;
			}
			else if (string[i] == '.' && point == 0)
			{
				if (count == 1)
				{
					return false;
				}
				i++;
				point++;
			}
			else
			{
				return false;
			}
		}
		return true;
	}

};

int main()
{
	Solution s;
}