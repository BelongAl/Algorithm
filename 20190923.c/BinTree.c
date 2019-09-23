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

BTNode *_CreateBinTree(char *array, int size, int* index, BTDataType invalid)//二叉树的创建
{
	//根节点
	BTNode *pRoot = NULL;
	int count = 0;
	if (*index < size && array[*index] != invalid)
	{
		count++;
		pRoot = BuyBinTeeNode(array[*index]);
		++*index;
		//根的左子树
		pRoot->_pLeft = _CreateBinTree(array, size, index, invalid);
		++*index;
		//根的右子树
		pRoot->_pRight = _CreateBinTree(array, size, index, invalid);
	}
	return pRoot;
}

BTNode *CreateBinTree(char *array, int size, BTDataType invaild)//二叉树的创建
{
	//根节点
	int index = 0;
	return _CreateBinTree(array, size, &index, invaild);
}

//前序遍历：根-》根的左子树-》根的右子树 递归 
void PreOrder(BTNode *pRoot)
{
	if (pRoot)
	{
		printf("%-2c", pRoot->data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}
//中序遍历：根的左子树-》根-》根的右子树 递归
void InOrder(BTNode *pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%-2c", pRoot->data);
		InOrder(pRoot->_pRight);
	}
}
//后序遍历：根的左子树-》根的右子树-》根 递归
void PostOrder(BTNode *pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%-2c", pRoot->data);;
	}
}

void DestroyBinTree(BTNode **pRoot)//销毁使用后序
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

int GetLeafCount(BTNode *pRoot)//计算二叉树中有多少个叶子节点
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
//Copy *CopyBinTree(BTNode **pRoot,BTNode **p)//二叉树的拷贝 //概念 
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

int _GetBinTreeSize(BTNode *pRoot, int *k)//计算二叉树有多少个节点
{
	if (pRoot)
	{
		*k = *k+1;
		_GetBinTreeSize(pRoot->_pLeft, k);
		_GetBinTreeSize(pRoot->_pRight, k);
	}
	return *k;
}
int GetBinTreeSize(BTNode *pRoot )//计算二叉树有多少个节点
{
	if (NULL == pRoot)
	{
		return 0;
	}
	int k = 0;
	return _GetBinTreeSize(pRoot, &k);
}

int count = 0;
int _GetBinTreeHeight(BTNode *pRoot ,int *k)//计算树的深度
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
int GetBinTreeHeight(BTNode *pRoot)//计算树的深度
{
	int k = 0;
	_GetBinTreeHeight(pRoot, &k);
	return count;
}

int _GetKLeveNodeCount(BTNode* pRoot, int k, int *m)//获取二叉树中第k层的节点数1
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
int GetKLeveNodeCount1(BTNode *pRoot, int k)//获取二叉树中第k层的节点数1
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

int GetKLeveNodeCount2(BTNode *pRoot, int k)//获取二叉树中第k层的节点数2
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

BTNode *BinaryTreeFind(BTNode *pRoot, BTDataType x)//返回为x元素的位置
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
	if (pNode = BinaryTreeFind(pRoot->_pLeft, x))//左子树找
	{
		return pNode;
	}
	return BinaryTreeFind(pRoot->_pRight, x);//右子树找
}

void LeveIOrder(BTNode *pRoot)//层序遍历
{
	if (NULL == pRoot)
	{
		return;
	}
	printf("层序遍历结果：");
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
	QueueDestroy(&q);//销毁
}


void Swap(BTNode **left, BTNode **right)//交换
{
	BTNode *tmp = *left;
	*left = *right;
	*right = tmp;
}

void Mirror(BTNode *pRoot)//二叉树镜像1
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

void MirrorNor(BTNode *pRoot)//二叉树镜像2
{
	if (pRoot)
	{
		Swap(&pRoot->_pLeft, &pRoot->_pRight);
		MirrorNor(pRoot->_pLeft);
		MirrorNor(pRoot->_pRight);
	}
}









void QueueInit(Queue *q)// 初始化
{
	assert(q);
	q->_back = NULL;
	q->_front = NULL;
}

QNode *BuyQueueNode(QDataType x)//创建一个新节点
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

void QueuePush(Queue *q, QDataType x)//入队列
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
void QueuePop(Queue *q)//出队列
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
QDataType QueueFrount(Queue *q)//获取头
{
	assert(q);
	return q->_front->_data;
}

QDataType QueueBack(Queue *q)//获取尾
{
	assert(q);
	return q->_back->_data;
}

int QueueSize(Queue *q)//队列大小
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
int QueueEmpty(Queue *q)//判空
{
	assert(q);
	return NULL == q->_front;
}

void QueueDestroy(Queue *q)//销毁
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

void QueueShow(Queue *q)//打印
{
	assert(q);
	QNode *qCur = q->_front;
	printf("元素是");
	while (qCur)
	{
		printf("%-3d", qCur->_data);
		qCur = qCur->_pNext;
	}
	printf("\n");
}