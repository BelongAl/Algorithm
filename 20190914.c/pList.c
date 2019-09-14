#include"pList.h"

pList pListByuNweNode(DataType data)//�õ�һ���½ڵ�
{
	pList pNewNode = (pList)malloc(sizeof(List));
	pNewNode->next = NULL;
	pNewNode->random = NULL;
	pNewNode->data = data;
}

void pListInit(pList* pHead, DataType data)//��������ĳ�ʼ��//ͷ��
{
	assert(pHead);
	pList pCur = *pHead;
	if (pCur == NULL)
	{
		*pHead = pListByuNweNode(data);
	}
	else
	{
		while (pCur->next)
		{
			pCur = pCur->next;
		}
		pCur->next = pListByuNweNode(data);
	}
}

void pListShow(pList pHead)//��ӡ
{
	assert(pHead);
	while (pHead)
	{
		printf("%d", pHead->data);
		pHead = pHead->next;
	}
	printf("\n");
}

void pListComplex(pList *pHead)//���ӻ�
{
	pList pCur = *pHead;
	pCur->random = pCur->next->next;
	pCur->next->random = pCur;
	pCur->next->next->random = pCur->next->next;
}

pList pListCopy(pList *pHead)//��������ĸ���
{
	assert(pHead);
	pList pCur = *pHead;
	pList pNewNode = NULL;
	while (pCur)//�½�����
	{
		pNewNode = pListByuNweNode(pCur->data);
		pNewNode->next = pCur->next;
		pCur->next = pNewNode;
		pCur = pNewNode->next;
	}
	pCur = *pHead;
	while (pCur)//���ӻ�
	{
		if (pCur->random)
		{
			pCur->next->random = pCur->random->next;
			pCur = pCur->next->next;
		}
		else
		{
			pCur = pCur->next->next;
		}
	}
	pCur = *pHead;
	pList pCopy = pCur->next;
	pList pTmp = pCur->next;
	while (pCur)//���
	{
		pCur->next = pTmp->next;
		pCur = pCur->next;
		if (pCur)
		{
			pTmp->next = pCur->next;
			pTmp = pTmp->next;
		}
	}
	return pCopy;
}