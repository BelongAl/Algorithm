#include"RB_tree.h"
#include<iostream>

using namespace std;

int main()
{
	wr::RBTree<int> rbt;
	rbt.insert(1);
	rbt.insert(2);
	rbt.insert(3);
	rbt.insert(4);
	rbt.insert(5);
	system("pause");
	return 0;
}