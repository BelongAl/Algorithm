#include<iostream>
#include<string>
using namespace std;

string Length(string str)
{
	int count = 0; 
	int max = 0;
	int index = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			count = 0;
		}
		else
		{
			count++;
			if (count > max)
			{
				max = count;
				index = i - max + 1;
			}
		}
	}
	string res;
	for (int i = index; i < index + max; i++)
	{
		res.push_back(str[i]);
	}
	return res;
}

int main()
{
	char arr[] = "abcd12345ed125ss123456789";
	string str(arr);
	cout << Length(arr);
	system("pause");
	return 0;
}
