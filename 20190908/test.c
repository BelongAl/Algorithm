#include"PList.h"

void Testlist()
{
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);
	PrintSList(&s);
	SListPopBack(&s);
	PrintSList(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	PrintSList(&s);
	SListPopBack(&s);
	PrintSList(&s);
	SListPushFront(&s, 5);
	SListPushFront(&s, 4);
	SListPushFront(&s, 3);
	SListPushFront(&s, 2);
	SListPushFront(&s, 1);
	PrintSList(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	PrintSList(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	PrintSList(&s);
	SListPushFront(&s, 5);
	SListPushFront(&s, 4);
	SListPushFront(&s, 3);
	SListPushFront(&s, 2);
	SListPushFront(&s, 1);
	PrintSList(&s);
	SListInsert(SListFind(&s,3), 8);
	PrintSList(&s);
	SListErase(&s,SListFind(&s, 4));
	PrintSList(&s);
}
int main()
{
	Testlist();
	system("pause");
	return 0;
}