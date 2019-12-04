#include<iostream>
#include<vector>

using namespace std;

void Code(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		long long f1 = 1;
		long long f2 = 1;
		long long f3 = 1;
		int tmp = v[i];
		while ((tmp - 1) > 0)
		{
			f1 = f2;
			f2 = f3;
			f3 = f1 + f2;
			tmp--;
			if (f3 >= 10000)
			{
				f3 %= 10000;
			}
		}
		if (f3 > 999)
		{
			cout << f3 % 10000;
		}
		else if (f3 > 99)
		{
			cout << "0" << f3;
		}
		else if (f3 > 9)
		{
			cout << "00" << f3;
		}
		else
		{
			cout << "000" << f3;
		}
	}

}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> v(n, 0);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		Code(v);
		cout << endl;
	}
	return 0;
}
