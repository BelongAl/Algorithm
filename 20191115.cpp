#include<iostream>

using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B)
	{
		int tem = 0;
		do {
			tem = A & B;//�ҳ���Ҫ��λ��Ԫ��
			A = A ^ B;//��AB�в���Ҫ��λ��λȫ�������A��
			B = tem << 1;//ʹ��B�洢��λ��λ��
		} while (B != 0);//ѭ����û������Ҫ��λ��Ԫ��
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