#include"list.h"

void Funs()
{
	List pList;
	InitializationList(&pList);
	FrountPushInsert(&pList, 4);
	FrountPushInsert(&pList, 2);
	FrountPushInsert(&pList, 5);
	FrountPushInsert(&pList, 3);
	FrountPushInsert(&pList, 8);
	ShowList(&pList);
	FrountDeleteList(&pList);
	ShowList(&pList);
	BackPushList(&pList, 9);
	BackPushList(&pList, 2);
	BackPushList(&pList, 5);
	BackPushList(&pList, 0);
	ShowList(&pList);
	BackDeleteList(&pList);
	ShowList(&pList);
	ArbitrarilyInsertList(&pList, 3, 8);
	ShowList(&pList);
	ArbitrarilyDeleteList(&pList, 3);
	ShowList(&pList);
	BubbleSortList(&pList);
	ShowList(&pList);
	BinarySearchList(&pList, 3);

}
int main()
{
	Funs();
	system("pause");
	return 0;
}