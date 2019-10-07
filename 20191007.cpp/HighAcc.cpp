#include"HighAcc.h"

int main()
{
	string s1("123");
	string s2("123");
	HighAcc num1(s1);
	HighAcc num2(s2);

	cout << (string)(num1 + num2) << endl;
	cout << (string)(num1 * num2) << endl;
	system("pause");
	return 0;
}