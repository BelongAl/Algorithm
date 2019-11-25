#include<iostream>

using namespace std;

//method 1
/*
int minCommonMultiple(int A, int B)
{
	int ret = A > B ? A : B;
	int min = A < B ? A : B;
	while (1)
	{
		if (ret % A == 0 && ret % B == 0)
		{
			return ret;
		}
		if (ret % min == 0)
		{
			ret += min;
		}
		else
		{
			ret++;
		}
	}
}

int main()
{
	int A, B;
	while (cin >> A >> B)
	{
		cout << minCommonMultiple(A, B) << endl;
	}
	return 0;
}
*/

//method 2
#include<iostream>

using namespace std;

int maxCommonDivisor(int a, int b)
{
	while (int r = a % b)
	{
		a = b;
		b = r;
	}
	return b;
}

int main()
{
	int A, B;
	while (cin >> A >> B)
	{
		cout << A * B / maxCommonDivisor(A, B) << endl;
	}
	return 0;
}
