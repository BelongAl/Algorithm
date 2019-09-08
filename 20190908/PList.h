#ifndef _LIST_H_
#define _LIST_H_

#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<malloc.h>

typedef int SDataType;

typedef struct SListNode
{
	SDataType _data;
	struct SListNode *_pNext;
}Node, *pNode;

typedef struct SList
{
	pNode _pHead;
}SList;

void SListInit(SList *s);
void SListPushBack(SList *s, SDataType data);
void SListPopBack(SList *s);
void SListPushFront(SList *s, SDataType data);
void SListPopFront(SList *s);
void SListInsert(pNode pos, SDataType data);
void SListErase(pNode pos);
void PrintSList(SList *s);
void Testlist();
pNode SListFind(SList *s, SDataType data);
size_t SListSize(SList *s);
int SListEmpty(SList *s);

#endif
