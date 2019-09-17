#ifndef _QUEUE_H_
#define _QUEUE_H_

#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int QDataType;

typedef struct QNode//队列节点
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;
 
typedef struct Queue//定义两个指针，分别指向队头和队尾的节点
{
	QNode * _front;//队头
	QNode * _back;//队尾
}Queue;

void QueueInit(Queue *q);// 初始化
void QueuePush(Queue *q, QDataType x);//入队列
void QueuePop(Queue *q);//出队列
QDataType QueueFrount(Queue *q);//获取头
QDataType QueueBack(Queue *q);//获取尾
int QueueSize(Queue *q);//队列大小
int QueueEmpty(Queue *q);//判空
void QueueDestroy(Queue *q);//销毁
void QueueShow(Queue *q);//打印

#endif // !_QUEUE_H_


