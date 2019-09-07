#ifndef _LIST_H_
#define _LIST_H_

#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct SeqList
{
	int *arr;
	size_t size;
	size_t capicity;
}List;

void ShowList(List *s);
void InitializationList(List *s);
void CapacityExpansionList(List *s);
void FrountPushInsert(List *s , int add);
void FrountDeleteList(List *s);
void BackPushList(List *s, int add);
void BackDeleteList(List *s);
void ArbitrarilyInsertList(List *s, int num, int add);
void ArbitrarilyDeleteList(List *s, int num);
void BubbleSortList(List *s);
void BinarySearchList(List *s);

#endif 