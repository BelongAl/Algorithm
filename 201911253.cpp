#include<iostream>

using namespace std;

int fun(int n, int m)
{
	if (n == 1 || m == 1)
	{
		return 1;
	}
	else
	{
		return fun(n - 1, m) + fun(n, m - 1);
	}
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << fun(n + 1, m + 1) << endl;
	}
	return 0;
}