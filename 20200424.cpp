#include<iostream>
#include<string>
#include<vector>

using namespace std;


//规律一
int getnum(int n)
{
	int ret = 1;
	while (n)
	{
		ret *= 10;
		n /= 10;
	}
	return ret;
}

int man()
{
	int l, r;
	cin >> l >> r;

	vector<pair<string, bool>> v;
	v.push_back(make_pair("1", false));
	int i = 1;
	long long tmp = 1;//表示多余的
	while (i < r)
	{
		long long k = i + 1;//表示新追加的
		tmp = tmp * getnum(k);
		if ((k + tmp) % 3 == 0)
		{
			v.push_back(make_pair((v[i - 1].first + to_string(k)), true));
			tmp = 0;
		}
		else
		{
			v.push_back(make_pair((v[i - 1].first + to_string(k)), false));
			tmp = k + tmp;
		}
		i++;
	}

	int ret = 0;
	for (i = l-1; i < r; i++)
	{
		if (v[i].second)
		{
			ret++;
		}
	}

	cout << ret << endl;

	return 0;
}

//规律2
int main()
{
	int l, r;
	while (cin >> l >> r)
	{
		int ret = (r * 2 / 3) - ((l - 1) * 2 / 3);
		cout << ret << endl;
	}
	return 0;
}