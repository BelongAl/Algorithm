#include<iostream>

#include"RBtree.h"

using namespace wr;

int main()
{
	RBTree<int> RB;
	RB.insert(4);
	RB.insert(5);
	RB.insert(6);
	RB.insert(2);
	RB.insert(7);
	RB.insert(10);
	RB.insert(8);
	RB.insert(34);
	RB.insert(3);
	RB.insert(9);

	system("pause");
	return 0;
}