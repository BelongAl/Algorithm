#include"List.h"

pList pBuyNewNode(DataType data)//����һ���½ڵ�
{
	pList pNewNode = (pList)malloc(sizeof(List));
	if (NULL == pNewNode)
	{
		assert(0);
		return;
	}
	pNewNode->data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void pListPushBack(pList* pHead, DataType data)//β��
{
	assert(pHead);
	pList pNewNode = pBuyNewNode(data);
	if (NULL == *pHead)
	{
		(*pHead) = pNewNode;
		(*pHead)->data = data;
	} 
	else
	{
		pList pCur = *pHead;
		while (pCur->_pNext)
		{
			pCur = pCur->_pNext;
		}
		pCur->_pNext = pNewNode;
	}
}

void pListShow(pList pHead)//��ӡ
{
	assert(pHead);
	while (pHead)
	{
		printf("--->%d", pHead->data);
		pHead = pHead->_pNext;
	}
	printf("\n");
}

void pListDeleteAll(pList* pHead, DataType val)//ɾ�����������е���val�Ľڵ�
{
	assert(pHead);
	pList pCur = *pHead;
	pList pTmp;
	while (pCur->_pNext)
	{
		if ((*pHead)->data != val)
		{
			break;
		}
		pTmp = (*pHead)->_pNext;
		free(*pHead);
		(*pHead) = pTmp;
	}
	pCur = *pHead;
	pTmp = pCur;
	while (pTmp->_pNext)
	{
		pCur = pTmp->_pNext;
		if (pCur->data == val)
		{
			pTmp->_pNext = pCur->_pNext;
			free(pCur);
		}
		else
		{
			pTmp = pTmp->_pNext;
		}
	}
	if (pTmp->data == val)
	{
		free(pTmp);
	}
}

void pListReversal1(pList *pHead)//��ת������1:��ָ�뷨
{
	assert(pHead);
	pList pFast = *pHead;
	pList pMiddle = *pHead;
	pList pSlow = NULL;
	while (pFast)
	{
		pFast = pFast->_pNext;
		pMiddle->_pNext = pSlow;
		pSlow = pMiddle;
		pMiddle = pFast;
	}
	*pHead = pSlow;
}

void pListReversal2(pList *pHead)//��ת������2��ͷ�巨(������������)
{
	assert(pHead);
	pList pFast = (*pHead)->_pNext;
	pList pSlow = (*pHead);
	(*pHead)->_pNext = NULL;
	while (pFast)
	{
		pSlow = pFast;
		pFast = pFast->_pNext;
		pSlow->_pNext = NULL;
		pSlow->_pNext = (*pHead)->_pNext;
		(*pHead)->_pNext = pSlow;
	}
	pList pCur = pSlow;
	while (pSlow->_pNext)
	{
		pSlow = pSlow->_pNext;
	}
	(*pHead)->_pNext = NULL;
	pSlow->_pNext = *pHead;
	*pHead = pCur;
}

void pListReversal3(pList *pHead)//��ת������3��ͷ�巨(����������)
{
	assert(pHead);
	pList pNewNode = pBuyNewNode(0);
	pList pCur;
	while (*pHead)
	{
		pCur = (*pHead)->_pNext;
		(*pHead)->_pNext = pNewNode->_pNext;
		pNewNode->_pNext = *pHead;
		(*pHead) = pCur;
	}
	*pHead = pNewNode->_pNext;
	free(pNewNode);
}

void pListReciprocalKal(pList *pHead, int k)// ����һ����������������е�����k�����
{
	int tmp = k;
	assert(pHead);
	if (k <= 0)
	{
		return;
	}
	pList pFast = *pHead;
	pList pSlow = *pHead;
	while (--k && pFast)
	{
		pFast = pFast->_pNext;
	}
	if (NULL == pFast)
	{
		return;
	}
	while (pFast->_pNext)
	{
		pFast = pFast->_pNext;
		pSlow = pSlow->_pNext;
	}
	printf("the reciprocal %d is %d\n",tmp, pSlow->data);
}

//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
pList pListSplice(pList *pHead, pList *pTail)
{
	assert(pHead);
	assert(pTail);
	pList insert = *pTail;
	pList beinsert = *pHead;
	pList pNewNode = NULL;
	if ((insert->data) >= (beinsert->data))
	{
		pNewNode = beinsert;
		beinsert = beinsert->_pNext;;
	}
	else
	{
		pNewNode = insert;
		insert = insert->_pNext;
	}
	pList pTmp = pNewNode;
	while(insert && beinsert)
	{
		if ((insert->data) >= (beinsert->data))
		{
			pNewNode->_pNext = beinsert;
			beinsert = beinsert->_pNext;
		}
		else
		{
			pNewNode->_pNext = insert;
			insert = insert->_pNext;
		}
		pNewNode = pNewNode->_pNext;
	}
	if (insert)
	{
		pNewNode->_pNext = insert;
	}
	else
	{
		pNewNode->_pNext = beinsert;
	}
	return pTmp;
}

//����һ������ͷ��� head �ķǿյ����� ������������м��㡣����������м��㣬�򷵻صڶ��� �м���
void pListFindMiddle(pList *pHead)
{
	pList pFast = *pHead;
	pList pSlow = *pHead;
	while (pFast && pFast->_pNext)
	{
		pSlow = pSlow->_pNext;
		pFast = pFast->_pNext->_pNext;
	}
	printf("The intermediate element is %d\n", pSlow->data);
}