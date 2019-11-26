#include<iostream>
#include"AVL_TREE.h"

int main()
{
	wr::AVLtree<int> avlt1;
	avlt1.insert(1);
	avlt1.insert(2);
	avlt1.insert(3);
	avlt1.insert(4);
	avlt1.insert(5);
	avlt1.insert(6);

	wr::AVLtree<int> avlt2;
	avlt2.insert(6);
	avlt2.insert(5);
	avlt2.insert(4);
	avlt2.insert(3);
	avlt2.insert(2);
	avlt2.insert(1);

	wr::AVLtree<int> avlt3;
	avlt3.insert(4);
	avlt3.insert(2);
	avlt3.insert(9);
	avlt3.insert(1);
	avlt3.insert(6);
	avlt3.insert(3);
	avlt3.insert(5);
	avlt3.insert(0);

	system("pause");
	return 0;
}