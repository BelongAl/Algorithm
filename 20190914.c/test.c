#include"pList.h"

void pFuns()
{
	pList pHead = NULL;
	pListInit(&pHead, 1);//ͷ��
	pListInit(&pHead, 2);
	pListInit(&pHead, 3);
	pListInit(&pHead, 4);
	pListComplex(&pHead);//���ӻ�
	pListShow(pHead);//��ӡ
    pList p = pListCopy(&pHead);
	pListShow(pHead);//��ӡ
	pListShow(p);
}

int main()
{
	pFuns();
	system("pause");
	return 0;
}