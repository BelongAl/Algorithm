#include<string>
#include<cstring>
#include<iostream>

using namespace std;
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
			{
				count += 2;
			}
		}
		for (int i = length; i < length + count; i++)
		{
			str[i] = ' ';
		}
		str[length + count] = '\0';
		int i = length - 1;
		int j = length - 1;
		while (i >= 0)
		{
			if (str[i] == ' ')
			{
				while (j != i)
				{
					str[j + count] = str[j];
					j--;
				}
				count -= 2;
				str[i] = '%';
				str[i + 1] = '2';
				str[i + 2] = '0';
				j += 2;
			}
			i--;
		}
	}
};
int main()
{
	Solution s;
	char str[17] = "hello  world";
	s.replaceSpace(str,12);
	cout << str << endl;
	system("pause");
	return 0;
}




