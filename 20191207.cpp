#include<iostream>
#include<vector>

using namespace std;

double Power(double base, int exponent) {
	if (base == 0 || exponent == 0)
	{
		return 0;
	}
	return pow(base,exponent);
}

int main()
{
	cout << Power(3.4, 7);
	system("pause");
	return 0;
}