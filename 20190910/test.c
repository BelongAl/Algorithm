#include"Dlist.h"

void Funs()
{
	PDLNode pHead = NULL;
	DListInit(&pHead);
	DListPushBack(pHead, 1);
	DListPushBack(pHead, 2);
	DListPushBack(pHead, 3);
	DListShow(pHead);
	DListPopBack(pHead);
	DListShow(pHead);
	DListPushFront(pHead, 3);
	DListPushFront(pHead, 4);
	DListShow(pHead);
	DListPopFront(pHead);
	DListShow(pHead);
	DListInsert(DListFind(pHead, 3), 8);
	DListInsert(DListFind(pHead, 1), 9);
	DListInsert(DListFind(pHead, 8), 7);
	DListInsert(DListFind(pHead, 2), 7);
	DListShow(pHead);
	DListEranse(DListFind(pHead, 7));
	DListEranse(DListFind(pHead,1));
	DListShow(pHead);
	DListClear(pHead);
	DListShow(pHead);
	DListDestroy(&pHead);
}
int main()
{
	Funs();
	system("pause");
	return 0;
}