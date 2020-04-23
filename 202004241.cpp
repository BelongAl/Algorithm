#include<iostream>
#include<string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string post(n,'0');
		for (int i = 0; i < n; i+=)
		{
			cin >> post[i];
		}
		int i = 0;
		int num = 0;
		while (i < n)
		{
			if (post[i] == '.')
			{
				if ((i + 1 < n && post[i + 1] == '.') ||
					(i + 2 < n && post[i + 2] == '.'))
				{
					i += 2;
				}
				else
				{
					i += 1;
				}
				num++;
			}
			i++;
		}
		cout << num << endl;
	}
	return 0;
}