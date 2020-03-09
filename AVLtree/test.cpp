#include"AVL.h"

int main()
{
	AVLtree<int> av(3);
	av.insert(1);
	av.insert(2);
	av.insert(6);
	av.insert(4);
	av.insert(5);
	av.insert(6);
	av.insert(7);
	av.insert(8);
	av.insert(9);
	av.insert(66);

	av.erase(4);

	return 0;
}