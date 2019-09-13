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

void pListPushBack(pList *pHead, DataType data);//尾插
pList pBuyNewNode(DataType data);//创建一个新节点
void pListShow(pList pHead);//打印
void pListDeleteAll(pList *pHead, DataType val);//删除链表中所有等于val的节点
void pListReversal1(pList *pHead);//反转单链表
void pListReversal2(pList *pHead);//反转单链表
void pListReversal3(pList *pHead);//反转单链表
void pListReciprocalKal(pList *pHead, int k);// 输入一个链表，输出该链表中倒数第k个结点
//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
pList pListSplice(pList *pHead, pList *pTail);
//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个 中间结点
void pListFindMiddle(pList *pHead);
//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
pList pListTwoPart(pList *pHead, DataType val);
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头 指针
pList pListDeleteDuplication(pList *pHead);
// 链表的回文结构
pList pListSymmetric1(pList *pHead);//构建数组
pList pListSymmetric2(pList *pHead);//逆转
// 输入两个链表，找出它们的第一个公共结点。
pList pListPublic(pList *pHead, pList *pTail);
//给定一个链表，判断链表中是否有环
DataType pListYNRing(pList *pHead);
void pListRing(pList *pHead);//构建一个带环的链表
//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
void pListFirstRingNode(pList *pHead);
#endif // !_LIST_H_

