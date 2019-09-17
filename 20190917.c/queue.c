#include"queue.h"

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
	if(NULL == q->_front)
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