#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		char str[5] = "NESW";
		int i = 0;
		while (n--)
		{
			char c;
			cin >> c;
			if(c == 'L')
			{ 
				i--;
				if (i == -1)
				{
					i = 3;
				}
			}
			else
			{
				i++;
				if (i == 4)
				{
					i = 0;
				}
			}
		}
		cout << str[i] << endl;
	}
	return 0;
}