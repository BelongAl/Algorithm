#ifndef _PLIST_H_
#define _PLIST_H_

#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

typedef struct Node
{
	struct Node *next;
	struct Node *random;
	DataType data;
}List,*pList;

void pListInit(pList *pHead, DataType Data);//复杂链表的构建
void pFuns();//测试函数
pList pListByuNweNode(DataType data);//得到一个新节点
void pListShow(pList pHead);//打印
void pListComplex(pList *pHead);//复杂化
pList pListCopy(pList *pHead);//复杂链表的复制

#endif // !_PLIST_H_


