#include<iostream>

#include"RBtree.h"

using namespace wr;

int main()
{
	RBTree<int> RB;

	//insert test
	RB.insert(4);
	RB.insert(5);
	RB.insert(244);
	RB.insert(6);
	RB.insert(2);
	RB.insert(7);
	RB.insert(10);
	RB.insert(8);
	RB.insert(34);
	RB.insert(3);
	RB.insert(0);
	RB.insert(46);
	RB.insert(2030);
	RB.insert(1998);
	RB.insert(27);
	RB.insert(888);
	RB.insert(666);

	//iterator test
	for (auto &e : RB)
	{
		std::cout << e << std::endl;
	}

	//find test
	//std::cout << "Found this element:" << RB.find(34).second.m_data << ": "<<  *RB.find(34).second << std::endl;

	//erase test
	RB.erase(4);

	//iterator test
	for (auto &e : RB)
	{
		std::cout << e << std::endl;
	}

	system("pause");
	return 0;
}