#ifndef _QUEUE_H_
#define _QUEUE_H_

#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

typedef struct QNode//���нڵ�
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;
 
typedef struct Queue//��������ָ�룬�ֱ�ָ���ͷ�Ͷ�β�Ľڵ�
{
	QNode * _front;//��ͷ
	QNode * _back;//��β
}Queue;

void QueueInit(Queue *q);// ��ʼ��
void QueuePush(Queue *q, QDataType x);//�����
void QueuePop(Queue *q);//������
QDataType QueueFrount(Queue *q);//��ȡͷ
QDataType QueueBack(Queue *q);//��ȡβ
int QueueSize(Queue *q);//���д�С
int QueueEmpty(Queue *q);//�п�
void QueueDestroy(Queue *q);//����
void QueueShow(Queue *q);//��ӡ

#endif // !_QUEUE_H_


