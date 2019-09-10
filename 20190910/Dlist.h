#ifndef _DLIST_H_
#define _DLIST_h_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DLDataType;

typedef struct DListNode
{
	struct DListNode* _pNext;
	struct DListNode* _pPre;
	DLDataType _data;
}DLNode,*PDLNode;

void DListInit(PDLNode *pHead);
void DListPushBack(PDLNode *pHead, DLDataType data);
void DListPopBack(PDLNode pHead);
void DListPushFront(PDLNode pHead, DLDataType data);
void DListPopFront(PDLNode pHead);
void DListInsert(PDLNode pos, DLDataType data);
void DListEranse(PDLNode pos);
void DListClear(PDLNode pHead);
void DListDestroy(PDLNode PHEAD);
void DListShow(PDLNode pHead);
PDLNode DListFind(PDLNode pHead, DLDataType data);

#endif // !_DLIST_H_
