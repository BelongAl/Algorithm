#include"mlist.h"

int main()
{
	wr::list<int> l(4, 5);
	for (auto &i : l)
	{
		cout << i << " ";
	}
	wr::list<int> k(l);
	for (auto &i : k)
	{
		cout << i << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}