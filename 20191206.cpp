#include<iostream>

using namespace std;

int Add(int num1, int num2)
{
	int tmp = 0;
	while (num1)
	{
		tmp = num1 & num2;//�ҳ���Ҫ��λ��
		num2 = num2 ^ num1;//�ҳ�����Ҫ��λ��
		tmp <<= 1;
		num1 = tmp;
	}
	return num2;
}

int main()
{
	cout << Add(14, 3) << endl;
	system("pause");
	return 0;
}