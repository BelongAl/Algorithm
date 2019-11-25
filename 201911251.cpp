#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int n = 0;
	vector<string> vs;
	cin >> n;
	vs.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vs[i];
	}
	if (n == 1)
	{
		cout << "both";
		return 0;
	}
	bool length = true;
	bool lex = true;
	for (int i = 1; i < n; i++)
	{
		if (vs[i].size() < vs[i - 1].size())
		{
			length = false;
			break;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (vs[i - 1] > vs[i])
		{
			lex = false;
			break;
		}
	}
	if (length && lex)
	{
		cout << "both";
	}
	else if (length)
	{
		cout << "lengths";
	}
	else if (lex)
	{
		cout << "lexicographically";
	}
	else
	{
		cout << "none";
	}
	system("pause");
	return 0;
}