#include"Vector.h"

int main()
{
	wr::Vector<int> v1;
	wr::Vector<int> v2(5, 6);
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	int a[] = { 1,2,3,4 };
	wr::Vector<int> v3(a, a + 2);
	v2.insert(v2.begin(),a+1,a+3);
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << endl;
	v2.erase(v2.begin(),v2.end()-1);
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	system("pause");
	return 0;
}