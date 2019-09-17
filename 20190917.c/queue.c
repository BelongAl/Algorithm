#include"queue.h"

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