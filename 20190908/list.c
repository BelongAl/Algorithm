#include"PList.h"

void SListInit(SList *s)
{
	assert(s);
	s->_pHead = NULL;
}

pNode BuySListNode(SDataType data)
{
	pNode pNewNode = (pNode)malloc(sizeof(Node));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void SListPushBack(SList *s, SDataType data)
{
	assert(s);
	pNode pNewNode = BuySListNode(data);
	if (NULL == s->_pHead)
	{
		s->_pHead = pNewNode;
	}
	else
	{
		pNode pCur = s->_pHead;
		while (pCur->_pNext)
		{
			pCur = pCur->_pNext;
		}
		pCur->_pNext = pNewNode;
	}
}

void SListPopBack(SList *s)
{
	assert(s);
	if (NULL == s->_pHead)
		return;
	else if (NULL == s->_pHead->_pNext)
	{
		free(s->_pHead);
		s->_pHead = NULL;
	}
	else
	{
		pNode pCur = s->_pHead;
		pNode pCre = NULL;
		while (pCur->_pNext)
		{
			pCre = pCur;
			pCur = pCur->_pNext;
		}
		free(pCur);
		pCre->_pNext = NULL;
	}
}

void SListPushFront(SList *s, SDataType data)
{
	assert(s);
	pNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = s->_pHead;
	s->_pHead = pNewNode;
}

void SListPopFront(SList *s)
{
	assert(s);
	if (NULL == s->_pHead)
		return;
	else
	{
		pNode pDelNode = s->_pHead;
		s->_pHead = pDelNode->_pNext;
		free(pDelNode);
	}
}

void SListInsert(pNode pos, SDataType data)
{
	if (NULL == pos)
		return;
	else
	{
		pNode pNewNode = BuySListNode(data);
		pNewNode->_pNext = pos->_pNext;
		pos->_pNext = pNewNode;
	}
}

void SListErase(SList *s, pNode pos)
{
	assert(s);
	if (NULL == pos || NULL == s->_pHead)
		return;
	if (pos == s->_pHead)
	{
		s->_pHead = pos->_pNext;
	}
	else
	{
		pNode pPrePos = s->_pHead;
		while (NULL != pPrePos && pPrePos->_pNext != pos)
		{
			pPrePos = pPrePos->_pNext;
		}
		if (pPrePos)
		{
			pPrePos->_pNext = pos->_pNext;
		}
	}
	free(pos);
}

void PrintSList(SList *s)
{
	assert(s);
	pNode pCur = s->_pHead;
	while (pCur)
	{
		printf("%d--->", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}

pNode SListFind(SList *s, SDataType data)
{
	assert(s);
	pNode pCur = s->_pHead;
	while (pCur)
	{
		if (pCur->_data == data)
		{
			return pCur;
		}
		pCur = pCur->_pNext;
	}
	return NULL;
}

size_t SListSize(SList *s)
{
	assert(s);
	pNode pCur = s->_pHead;
	int count = 0;
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}
	return count;
}
int SListEmpty(SList *s)
{
	assert(s);
	return NULL == s->_pHead;
}

