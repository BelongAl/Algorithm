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

void pListInit(pList *pHead, DataType Data);//��������Ĺ���
void pFuns();//���Ժ���
pList pListByuNweNode(DataType data);//�õ�һ���½ڵ�
void pListShow(pList pHead);//��ӡ
void pListComplex(pList *pHead);//���ӻ�
pList pListCopy(pList *pHead);//��������ĸ���

#endif // !_PLIST_H_


