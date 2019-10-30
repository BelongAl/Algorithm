
#include<iostream>

using namespace std;


//ֻ�ڶ��ϴ����������
class HeapOnly
{
	HeapOnly()//���캯��˽�л���ʹ���ⲿ����ֱ�ӵ���
	{
		cout << "HeapOnly( )" << endl;
	}
	HeapOnly(const HeapOnly &);//�Կ�������Ĳ�ʵ�ֿɷ�ֹ����������ջ�Ͽ���,˽�л��Ƿ�ֹ�����ڽ��п�������
	//HeapOnly(const HeapOnly &) = delete;//c++11 �﷨
public:
	static HeapOnly* CreateObject()//������̬������ʹ�ò��������󼴿ɷ��ʵ�����
	{
		return new HeapOnly;
	}
};

//ֻ��ջ�Ͽ��ٶ������
//method one:˽�л����캯��(Ĭ�Ͽ������캯��Ҳ����ջ�ǿ��ٿռ�)��
class StackOnly1
{
	StackOnly1()
	{
		cout << "StackOnly( )" << endl;
	}
public:
	static StackOnly1 CreateObject()
	{
		return StackOnly1();
	}
};
//method two:��operator new������


int main()
{
	HeapOnly::CreateObject();
	StackOnly1 s (StackOnly1::CreateObject());
	system("pause");
	return 0;
}
