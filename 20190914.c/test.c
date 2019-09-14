#include"pList.h"

void pFuns()
{
	pList pHead = NULL;
	pListInit(&pHead, 1);//头插
	pListInit(&pHead, 2);
	pListInit(&pHead, 3);
	pListInit(&pHead, 4);
	pListComplex(&pHead);//复杂化
	pListShow(pHead);//打印
    pList p = pListCopy(&pHead);
	pListShow(pHead);//打印
	pListShow(p);
}

int main()
{
	pFuns();
	system("pause");
	return 0;
}