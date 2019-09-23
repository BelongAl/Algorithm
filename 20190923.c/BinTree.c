#include"BinTree.h"

BTNode *BuyBinTeeNode(BTDataType data)
{
	BTNode *pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	return pNewNode;
}

BTNode *_CreateBinTree(char *array, int size, int* index, BTDataType invalid)//�������Ĵ���
{
	//���ڵ�
	BTNode *pRoot = NULL;
	int count = 0;
	if (*index < size && array[*index] != invalid)
	{
		count++;
		pRoot = BuyBinTeeNode(array[*index]);
		++*index;
		//����������
		pRoot->_pLeft = _CreateBinTree(array, size, index, invalid);
		++*index;
		//����������
		pRoot->_pRight = _CreateBinTree(array, size, index, invalid);
	}
	return pRoot;
}

BTNode *CreateBinTree(char *array, int size, BTDataType invaild)//�������Ĵ���
{
	//���ڵ�
	int index = 0;
	return _CreateBinTree(array, size, &index, invaild);
}

//ǰ���������-������������-������������ �ݹ� 
void PreOrder(BTNode *pRoot)
{
	if (pRoot)
	{
		printf("%-2c", pRoot->data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}
//�������������������-����-������������ �ݹ�
void InOrder(BTNode *pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%-2c", pRoot->data);
		InOrder(pRoot->_pRight);
	}
}
//�������������������-������������-���� �ݹ�
void PostOrder(BTNode *pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%-2c", pRoot->data);;
	}
}

void DestroyBinTree(BTNode **pRoot)//����ʹ�ú���
{
	assert(pRoot);
	if (*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

int GetLeafCount(BTNode *pRoot)//������������ж��ٸ�Ҷ�ӽڵ�
{
	if (NULL == pRoot)
	{
		return 0;
	}
	if (NULL == pRoot->_pLeft)
	{
		return 1;
	}
	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}
//
//Copy *CopyBinTree(BTNode **pRoot,BTNode **p)//�������Ŀ��� //���� 
//{
//	Copy* pCopy = (Copy*)malloc(sizeof(Copy));
//	pCopy->beCopy = pRoot;
//	pCopy->Copy = p;
//	if (*pCopy->beCopy)
//	{
//		*pCopy->Copy = BuyBinTeeNode((*pCopy->beCopy)->data);
//		Copy *a = CopyBinTree(&(*pCopy->beCopy)->_pLeft, &(*pCopy->Copy)->_pLeft);
//		(*pCopy->Copy)->_pLeft = a->Copy;
//		Copy *b = CopyBinTree(&(*pCopy->beCopy)->_pRight, &(*pCopy->Copy)->_pRight);
//		(*pCopy->Copy)->_pRight = b->Copy;
//	}
//	return pCopy;
//}

int _GetBinTreeSize(BTNode *pRoot, int *k)//����������ж��ٸ��ڵ�
{
	if (pRoot)
	{
		*k = *k+1;
		_GetBinTreeSize(pRoot->_pLeft, k);
		_GetBinTreeSize(pRoot->_pRight, k);
	}
	return *k;
}
int GetBinTreeSize(BTNode *pRoot )//����������ж��ٸ��ڵ�
{
	if (NULL == pRoot)
	{
		return 0;
	}
	int k = 0;
	return _GetBinTreeSize(pRoot, &k);
}

int count = 0;
int _GetBinTreeHeight(BTNode *pRoot ,int *k)//�����������
{
	if (pRoot)
	{
		*k = *k + 1;
		_GetBinTreeHeight(pRoot->_pLeft, k);
		_GetBinTreeHeight(pRoot->_pRight, k);
	}
	if (*k > count)
	{
		count = *k;
	}
	*k = *k - 1;
	return *k;
}
int GetBinTreeHeight(BTNode *pRoot)//�����������
{
	int k = 0;
	_GetBinTreeHeight(pRoot, &k);
	return count;
}

int _GetKLeveNodeCount(BTNode* pRoot, int k, int *m)//��ȡ�������е�k��Ľڵ���1
{
	if (pRoot)
	{
		*m = *m + 1;
		if (*m == k)
		{
			count++;
		}
		_GetKLeveNodeCount(pRoot->_pLeft,k, m);
		_GetKLeveNodeCount(pRoot->_pRight,k, m);
	}
	if (pRoot)
	{
		*m = *m-1;
	}
	return *m;
}
int GetKLeveNodeCount1(BTNode *pRoot, int k)//��ȡ�������е�k��Ľڵ���1
{
	if (NULL == pRoot || k < 0)
	{
		return 0;
	}
	count = 0;
	int m = 0;
	_GetKLeveNodeCount(pRoot, k, &m);
	return count;
}

int GetKLeveNodeCount2(BTNode *pRoot, int k)//��ȡ�������е�k��Ľڵ���2
{
	if (NULL == pRoot || k < 0)
	{
		return 0;
	}
	if (1 == k)
	{
		return 1;
	}
	return GetKLeveNodeCount2(pRoot->_pLeft, k - 1) + GetKLeveNodeCount2(pRoot->_pRight, k - 1);
}

BTNode *BinaryTreeFind(BTNode *pRoot, BTDataType x)//����ΪxԪ�ص�λ��
{
	if (NULL == pRoot)
	{
		return NULL;
	}
	if (x == pRoot->data)
	{
		return pRoot;
	}
	BTNode *pNode = NULL;
	if (pNode = BinaryTreeFind(pRoot->_pLeft, x))//��������
	{
		return pNode;
	}
	return BinaryTreeFind(pRoot->_pRight, x);//��������
}

void LeveIOrder(BTNode *pRoot)//�������
{
	if (NULL == pRoot)
	{
		return;
	}
	printf("������������");
	Queue q;
	QueueInit(&q);
	QueuePush(&q,pRoot);
	while (!QueueEmpty(&q))
	{
		BTNode *pCur = QueueFrount(&q);
		printf("%-2c", pCur->data);
		if (pCur->_pLeft)
		{
			QueuePush(&q, pCur->_pLeft);
		}
		if (pCur->_pRight)
		{
			QueuePush(&q, pCur->_pRight);
		}
		QueuePop(&q);
	}
	printf("\n");	
	QueueDestroy(&q);//����
}


void Swap(BTNode **left, BTNode **right)//����
{
	BTNode *tmp = *left;
	*left = *right;
	*right = tmp;
}

void Mirror(BTNode *pRoot)//����������1
{
	if (NULL == pRoot)
	{
		return NULL;
	}
	Queue q;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while(!QueueEmpty(&q))
	{
		BTNode *pCur = QueueFrount(&q);
		Swap(&pCur->_pLeft, &pCur->_pRight);
		if (pCur->_pLeft)
		{
			QueuePush(&q, pCur->_pLeft);
		}
		if (pCur->_pRight)
		{
			QueuePush(&q, pCur->_pRight);
		}
		QueuePop(&q);
	}
}

void MirrorNor(BTNode *pRoot)//����������2
{
	if (pRoot)
	{
		Swap(&pRoot->_pLeft, &pRoot->_pRight);
		MirrorNor(pRoot->_pLeft);
		MirrorNor(pRoot->_pRight);
	}
}









void QueueInit(Queue *q)// ��ʼ��
{
	assert(q);
	q->_back = NULL;
	q->_front = NULL;
}

QNode *BuyQueueNode(QDataType x)//����һ���½ڵ�
{
	QNode* pNewNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return;
	}
	pNewNode->_data = x;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void QueuePush(Queue *q, QDataType x)//�����
{
	assert(q);
	QNode *pNewNode = BuyQueueNode(x);
	if (QueueEmpty(q))
	{
		q->_back = pNewNode;
		q->_front = pNewNode;
	}
	else
	{
		q->_back->_pNext = pNewNode;
		q->_back = pNewNode;
	}
}
void QueuePop(Queue *q)//������
{
	assert(q);
	if (q->_front == NULL)
	{
		return;
	}
	QNode *pDelete = q->_front;
	if (NULL == q->_front)
	{
		q->_back = NULL;
		q->_front = NULL;
	}
	else
	{
		q->_front = q->_front->_pNext;
	}
	free(pDelete);
}
QDataType QueueFrount(Queue *q)//��ȡͷ
{
	assert(q);
	return q->_front->_data;
}

QDataType QueueBack(Queue *q)//��ȡβ
{
	assert(q);
	return q->_back->_data;
}

int QueueSize(Queue *q)//���д�С
{
	assert(q);
	int count = 0;
	QNode *pCur = q->_front;
	while (pCur)
	{
		pCur = pCur->_pNext;
		count++;
	}
	return count;
}
int QueueEmpty(Queue *q)//�п�
{
	assert(q);
	return NULL == q->_front;
}

void QueueDestroy(Queue *q)//����
{
	assert(q);
	QNode *pCur = q->_front;
	while (pCur)
	{
		q->_front = pCur->_pNext;
		free(pCur);
		pCur = q->_front;
	}
	q->_back = NULL;
	q->_front = NULL;
}

void QueueShow(Queue *q)//��ӡ
{
	assert(q);
	QNode *qCur = q->_front;
	printf("Ԫ����");
	while (qCur)
	{
		printf("%-3d", qCur->_data);
		qCur = qCur->_pNext;
	}
	printf("\n");
}