#include<iostream>

using namespace std;

class Solution
{
	public:
		double Power(double base, int exponent)
		{
			if (base == 0)
			{
				if (exponent < 0)
				{
					perror("error");
				}
				else
				{
					return 0;
				}
			}
			if (exponent == 0)
			{
				return 1;
			}
			long long p = abs((long long)exponent);//absÈ¡¾ø¶ÔÖµ
			double r = 1.0;
			while (p)
			{
				if (p & 1)
				{
					r *= base;
				}
				base *= base;
				p >>= 1;
			}
			return exponent < 0 ? 1 / r : r;
		}
};

int main()
{
	Solution s;
	cout << s.Power(2.34, -5) << endl;
	system("pause");
	return 0;
}