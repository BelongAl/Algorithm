#include<iostream>

using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B)
	{
		int tem = 0;
		do {
			tem = A & B;//找出需要进位的元素
			A = A ^ B;//把AB中不需要进位的位全部存放在A中
			B = tem << 1;//使用B存储进位的位；
		} while (B != 0);//循环到没有再需要进位的元素
		return A;
	}
};

int main()
{
	UnusualAdd a;
	cout << a.addAB(11, 9);
	system("pause");
	return 0;
}