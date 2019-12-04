#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int tmp = 0;
		int m[3];
		for (int i = 0; i < s.size(); i++)
		{
			tmp += s[i] - '0';
			m[0] = tmp % 10;
			m[1] = (tmp / 10) % 10;
			m[2] = tmp / 100;
		}
		while (m[2] != 0 || m[1] != 0)
		{
			tmp = m[0] + m[1] + m[2];
			m[0] = tmp % 10;
			m[1] = tmp / 10;
			m[2] = tmp / 100;
		}
		cout << m[0];
	}
	system("pause");
	return 0;
}