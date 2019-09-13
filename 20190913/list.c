#include"List.h"

pList pBuyNewNode(DataType data)//创建一个新节点
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

void pListPushBack(pList* pHead, DataType data)//尾插
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

void pListShow(pList pHead)//打印
{
	assert(pHead);
	while (pHead)
	{
		printf("--->%d", pHead->data);
		pHead = pHead->_pNext;
	}
	printf("\n");
}

void pListDeleteAll(pList* pHead, DataType val)//删除链表中所有等于val的节点
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

void pListReversal1(pList *pHead)//反转单链表1:三指针法
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

void pListReversal2(pList *pHead)//反转单链表2：头插法(不创建新链表)
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

void pListReversal3(pList *pHead)//反转单链表3：头插法(创建新链表)
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

void pListReciprocalKal(pList *pHead, int k)// 输入一个链表，输出该链表中倒数第k个结点
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

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
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

//给定一个带有头结点 head 的非空单链表 ，返回链表的中间结点。如果有两个中间结点，则返回第二个 中间结点
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

//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
pList pListTwoPart(pList *pHead, DataType val)
{
	assert(pHead);
	pList pTmp = *pHead;
	pList pCur = (*pHead)->_pNext;
	while (pCur)
	{
		if ((pCur)->data < val)
		{
			pTmp->_pNext = pCur->_pNext;
			pCur->_pNext = *pHead;
			*pHead = pCur;
			pCur = pTmp;
		}
		else
		{
			pTmp = pCur;
		}
		pCur = pCur->_pNext;
	}
	return *pHead;
}

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头 指针
pList pListDeleteDuplication(pList* pHead)
{
	while (*pHead)
	{
		if ((*pHead)->data == (*pHead)->_pNext->data)
		{
			(*pHead) = (*pHead)->_pNext;
		}
		else if ((*pHead)->_pNext == NULL || (*pHead)->_pNext->_pNext == NULL|| (*pHead)->_pNext->data != (*pHead)->_pNext->_pNext->data)
		{
			(*pHead) = (*pHead)->_pNext;
			break;
		}
		else
		{
			(*pHead) = (*pHead)->_pNext;
		}
	}
	pList pFast = (*pHead)->_pNext;
	pList pMiddle = *pHead;
	pList pSlow = NULL;
	int count = 0;
	while (pFast)
	{
		if (pFast->data == pMiddle->data)
		{
			pFast = pFast->_pNext;
			count++;
		}
		else if (count > 0)
		{
			pSlow->_pNext = pFast;
			pMiddle = pFast;
			pFast = pFast->_pNext;
			count = 0;
		}
		else
		{
			pSlow = pMiddle;
			pFast = pFast->_pNext;
			pMiddle = pMiddle->_pNext;
		}
	}
	if (pMiddle->_pNext != pFast)
	{
		pSlow->_pNext = NULL;
	}
	return *pHead;
}

//判断链表是否为回文
pList pListSymmetric1(pList *pHead)//开辟数组
{
	assert(pHead);
	if ((*pHead)->_pNext == NULL)
	{
		return 1;
	}
	DataType *arr  = (DataType*)malloc(900*(sizeof(DataType)));
	pList pCur = *pHead;
	int size = 0;
	while(pCur)
	{
		arr[size++] = pCur->data;
		pCur = pCur->_pNext;
	}
	int i = 0;
	size--;
	while (i < size)
	{
		if (arr[i] == arr[size])
		{
			i++;
			size--;
		}
		else
		{
			free(arr);
			return 0;
		}
	}
	free(arr);
	return 1;
}
//判断链表是否为回文
pList pListSymmetric2(pList *pHead)//逆转
{
	assert(pHead);
	if ((*pHead)->_pNext == NULL)
	{
		return 1;
	}
	pList pFast = *pHead;
	pList pSlow = *pHead;
	pList pSlowPre = NULL;
	while (pFast && pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlowPre = pSlow;
		pSlow = pSlow->_pNext;
	}
	pSlowPre->_pNext = NULL;
	pListReversal1(&pSlow);
	pList pCur = *pHead;
	while (pCur && pSlow)
	{
		if ((pCur)->data != pSlow->data)
		{
			return 0;
		}
		pCur = pCur->_pNext;
		pSlow = pSlow->_pNext;
	}
	return 1;
}

// 输入两个链表，找出它们的第一个公共结点。
pList pListPublic(pList *pHead, pList *pTail)
{
	assert(pHead && pTail);
	pList pCur = *pHead;
	pList pTmp = *pTail;
	if (pCur == NULL || pTmp == NULL)
	{
		return 0;
	}
	int i = 1;
	int j = 1;
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
		i++;
	}
	while (pTmp->_pNext)
	{
		pTmp = pTmp->_pNext;
		j++;
	}
	if (pTmp != pCur)
	{
		return 0;
	}
	pCur = *pHead;
	pTmp = *pTail;
	while(i > j)
	{
		pCur = pCur->_pNext;
		i--;
	}
	while(i <j)
	{
		pTmp = pTmp->_pNext;
		j--;
	}
	while (pCur->_pNext)
	{
		if (pCur == pTmp)
		{
			return pCur->data;
		}
		pCur = pCur->_pNext;
		pTmp = pTmp->_pNext;
	}
}

//给定一个链表，判断链表中是否有环
DataType pListYNRing(pList *pHead)
{
	pList pCur = *pHead;
	pList pTmp = (*pHead)->_pNext->_pNext;
	while (pTmp && pTmp->_pNext)
	{
		if (pTmp == pCur)
		{
			return 1;
		}
		pTmp = pTmp->_pNext->_pNext;
		pCur = pCur->_pNext;
	}
	return 0;
}
void pListRing(pList *pHead)//构建一个带环的链表
{
	pList pCur = *pHead;
	pList pTmp = pCur->_pNext->_pNext;
	while (pCur->_pNext)
	{
		pCur = pCur->_pNext;
	}
	pCur->_pNext = pTmp;
}

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
void pListFirstRingNode(pList *pHead)
{
	pList pFast = *pHead;
	pList pSlow = *pHead;
	pList pTmp = NULL;
	while (pFast||pFast->_pNext)
	{
		pFast = pFast->_pNext->_pNext;
		pSlow = pSlow->_pNext;
		if (pFast == pSlow)
		{
			pTmp = pFast;
			break;
		}
	}
	if(NULL == pFast || NULL == pFast->_pNext)
	{
		return;
	}
	pSlow = *pHead;
	while (1)
	{
		pTmp = pTmp->_pNext;
		pSlow = pSlow->_pNext;
		if (pSlow = pTmp)
		{
			printf("The entry point is%p and is vale is %d\n", pSlow, pSlow->data);
			return;
		}
	}
}
