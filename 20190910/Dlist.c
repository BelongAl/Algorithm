#include"Dlist.h"

void DListInit(PDLNode* pHead)
{
	assert(pHead);
	*pHead = (PDLNode)malloc(sizeof(DLNode));
	if (NULL == *pHead)
	{
		assert(0);
		return;
	}
	(*pHead)->_pNext = *pHead;
	(*pHead)->_pPre = *pHead;
}

PDLNode BuyDListNode(DLDataType data)
{
	PDLNode pNewNode = (PDLNode)malloc(sizeof(DLNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	pNewNode->_pPre = NULL;
	return pNewNode;
}

void DListPushBack(PDLNode pHead, DLDataType data)
{
	assert(pHead);
	PDLNode pNewNode = BuyDListNode(data);
	pNewNode->_pNext = pHead;
	pNewNode->_pPre = pHead->_pPre;
	pHead->_pPre->_pNext = pNewNode;
	pHead->_pPre = pNewNode;
}

void DListPopBack(PDLNode pHead)
{
	assert(pHead);
	if (pHead->_pNext == pHead)
	{
		return;
	}
	else
	{
		PDLNode pDelNode = pHead->_pPre;
		pHead->_pPre = pHead->_pPre->_pPre;
		pHead->_pPre->_pNext = pHead;
		free(pDelNode);
	}
}

void DListShow(PDLNode pHead)
{
	assert(pHead);
	PDLNode pCur = pHead;
	while (pCur->_pNext != pHead)
	{
		pCur = pCur->_pNext;
		printf("--->%d", pCur->_data);
	}
	printf("\n");
}

void DListPushFront(PDLNode pHead, DLDataType data)
{
	assert(pHead);
	PDLNode pNewNode = BuyDListNode(data);
	pNewNode->_pNext = pHead->_pNext;
	pNewNode->_pPre = pHead;
	pHead->_pNext = pNewNode;
	pNewNode->_pNext->_pPre = pNewNode;
}

void DListPopFront(PDLNode pHead)
{
	assert(pHead);
	if (pHead == pHead->_pNext)
	{
		return;
	}
	else
	{
		PDLNode pDelNode = pHead->_pNext;
		pHead->_pNext = pDelNode->_pNext;
		pDelNode->_pNext->_pPre = pHead;
		free(pDelNode);
	}
}

PDLNode DListFind(PDLNode pHead, DLDataType data)
{
	assert(pHead);
	PDLNode pCur = pHead;
	while (pCur->_pNext != pHead)
	{
		pCur = pCur->_pNext;
		if (pCur->_data == data)
		{
			return pCur;
		}
	}
	return NULL;
}

void DListInsert(PDLNode pos, DLDataType data)
{
	if (NULL == pos)
	{
		return;
	}
	PDLNode pNewNode = BuyDListNode(data);
	pNewNode->_pNext = pos->_pNext;
	pNewNode->_pPre = pos;
	pos->_pNext = pNewNode;
	pNewNode->_pNext->_pPre = pNewNode;
}

void DListEranse(PDLNode pos)
{
	if (NULL == pos)
	{
		return;
	}
	pos->_pNext->_pPre = pos->_pPre;
	pos->_pPre->_pNext = pos->_pNext;
	free(pos);
}

void DListClear(PDLNode pHead)
{
	assert(pHead);
	PDLNode pCur = pHead->_pNext;
	while (pCur != pHead)
	{
		pHead->_pNext = pCur->_pNext;
		free(pCur);
		pCur = pHead->_pNext;
	}	
}

void DListDestroy(PDLNode *pHead)
{
	DListClear(*pHead);
	free(*pHead);
	*pHead = NULL;
}

