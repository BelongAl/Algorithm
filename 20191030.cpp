
#include<iostream>

using namespace std;


//只在堆上创建对象的类
class HeapOnly
{
	HeapOnly()//构造函数私有化，使得外部不能直接调用
	{
		cout << "HeapOnly( )" << endl;
	}
	HeapOnly(const HeapOnly &);//对拷贝构造的不实现可防止拷贝构造在栈上开辟,私有化是防止在类内进行拷贝构造
	//HeapOnly(const HeapOnly &) = delete;//c++11 语法
public:
	static HeapOnly* CreateObject()//借助静态函数可使得不借助对象即可访问到函数
	{
		return new HeapOnly;
	}
};

//只在栈上开辟对象的类
//method one:私有化构造函数(默认拷贝构造函数也是在栈是开辟空间)；
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
//method two:对operator new的重载


int main()
{
	HeapOnly::CreateObject();
	StackOnly1 s (StackOnly1::CreateObject());
	system("pause");
	return 0;
}
