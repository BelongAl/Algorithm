#ifndef _LIST_H_
#define _LIST_H_

#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;


typedef struct pList
{
	struct pList *_pNext;
	DataType data;
}List,*pList;

pList pListinit(pList *pHead);//初始化
void pListPushBack(pList pHead, DataType data);//尾插
pList pBuyNewNode(DataType data);//创建一个新节点
void pListShow(pList pHead);//打印
void pListDeleteAll(pList *pHead, DataType val);//删除链表中所有等于val的节点
void pListReversal(pList *pHead);//反转单链表
void pListReciprocalKal(pList *pHead);// 输入一个链表，输出该链表中倒数第k个结点
//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
pList pListSplice(pList *pHead, pList *pTail);
//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个 中间结点
void pListFindMiddle(pList *pHead);

#endif // !_LIST_H_

