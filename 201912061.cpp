#include<iostream>
#include<string>

using namespace std;

void transformation(string add, int k, int j, string ab)
{
	while (j > 0)
	{
		int tmp = ab[j] - '0';
		if (tmp < 10)
		{
			if (add[k] == 0)
			{
				add[k] += tmp + '0';
			}
			else
			{
				add[k] += tmp;
			}
		}
		else
		{
			if (add[k] != 0)
			{
				add[k] += tmp % 10;
			}
			else
			{
				add[k] += tmp % 10 + '0';
			}
			if (add[k + 1] != 0)
			{
				add[k + 1] += tmp / 10;
			}
			else
			{
				add[k + 1] += tmp / 10 + '0';
			}
		}
		if (add[k] > '9')
		{
			tmp = add[k] - '0';
			add[k] = tmp % 10 + '0';
			if (add[k + 1] != 0)
			{
				add[k + 1] += tmp / 10;
			}
			else
			{
				add[k + 1] += tmp / 10 + '0';
			}
		}
		j--;
		k++;
	}
}


bool compare(string a, string b, string c)
{
	int i = a.size() - 1, j = b.size() - 1;
	int adds = i > j ? i : j;
	adds += 3;
	string add(adds, 0);
	int k = 0;
	while (i >= 0 && j >= 0)
	{
		int tmp = a[i] + b[j] - 2 * '0';
		if (tmp < 10)
		{
			if (add[k] == 0)
			{
				add[k] += tmp + '0';
			}
			else
			{
				add[k] += tmp;
			}
		}
		else
		{
			if (add[k] != 0)
			{
				add[k] += tmp % 10;
			}
			else
			{
				add[k] += tmp % 10 + '0';
			}
			if (add[k + 1] != 0)
			{
				add[k + 1] += tmp / 10;
			}
			else
			{
				add[k + 1] += tmp / 10 + '0';
			}
		}
		if (add[k] > '9')
		{
			tmp = add[k] - '0';
			add[k] = tmp%10 + '0';
			if (add[k + 1] != 0)
			{
				add[k + 1] += tmp / 10;
			}
			else
			{
				add[k + 1] += tmp / 10 + '0';
			}
		}
		i--;
		j--;
		k++;
	}
	transformation(add, k, j, a);
	transformation(add, k, j, b);
	k = 0;
	while (add[k])
	{
		k++;
	}
	for (int i = 0, j = k-1; i < j; i++,j--)
	{
		char tmp = add[i];
		add[i] = add[j];
		add[j] = tmp;
	}
	if (k > c.size())
	{
		return true;
	}
	else if (k < c.size())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < k; i++)
		{
			if (c[i] < add[i])
			{
				return true;
			}
			else if(c[i] > add[i])
			{
				return false;
			}
		}
	}
	return false;
}

int main()
{
	string a, b, c;
	while (cin >> a >> b >> c)
	{
		if (compare(a, b, c) && compare(a, c, b) && compare(b, c, a))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}