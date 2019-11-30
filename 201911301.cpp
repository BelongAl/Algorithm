#include<iostream>
#include<vector>

using namespace std;

int gcb(int a, int b)
{
	if (b == 0)
		return a;
	return gcb(b, a%b);
}


int fun(vector<int> v, int a)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] <= a)
		{
			a += v[i];
		}
		else
		{
			a += gcb(v[i], a);
		}
	}
	return a;
}

int main()
{
	int a, n;
	while (cin >> n >> a)
	{
		vector<int> def;
		def.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> def[i];
		}
		cout << fun(def, a) << endl;
	}
	return 0;
}