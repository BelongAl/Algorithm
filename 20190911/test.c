#include"List.h"

void Funs()
{
	pList pHead = NULL;
	pList pTail = NULL;
	pListPushBack(&pTail, 3);
	pListPushBack(&pTail, 4);
	pListPushBack(&pTail, 5);
	pListPushBack(&pTail, 9);
	pListPushBack(&pHead, 1);//β��
	pListPushBack(&pHead, 2);
	pListPushBack(&pHead, 3);
	pListPushBack(&pHead, 4);
	pListPushBack(&pHead, 5);
	pListPushBack(&pHead, 6);
	pListPushBack(&pHead, 7);
	pListShow(pHead);//��ӡ
	pListShow(pTail);
	pListDeleteAll(&pHead, 2);
	pListShow(pHead);//��ӡ
	pListReversal1(&pHead);//��ָ������
	pListShow(pHead);
	pListReversal2(&pHead);//ͷ�巨����(�������½ڵ�)
	pListShow(pHead);
	pListReversal3(&pHead);//ͷ�巨���ã������½ڵ㣩
	pListShow(pHead);
	pListReciprocalKal(&pHead, 3);// ����һ����������������е�����k�����
	pListFindMiddle(&pHead);//Ѱ���м�ڵ�
	pListReversal2(&pHead);//ͷ�巨����
	pListShow(pHead);
	pListShow(pTail);
	pList p = pListSplice(&pTail, &pHead);//�ϲ�������������
	pListShow(p);
}

int main()
{
	Funs();
	system("pause");
	return 0;
}