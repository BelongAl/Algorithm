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

pList pListinit(pList *pHead);//��ʼ��
void pListPushBack(pList pHead, DataType data);//β��
pList pBuyNewNode(DataType data);//����һ���½ڵ�
void pListShow(pList pHead);//��ӡ
void pListDeleteAll(pList *pHead, DataType val);//ɾ�����������е���val�Ľڵ�
void pListReversal(pList *pHead);//��ת������
void pListReciprocalKal(pList *pHead);// ����һ����������������е�����k�����
//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
pList pListSplice(pList *pHead, pList *pTail);
//����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ��� �м���
void pListFindMiddle(pList *pHead);

#endif // !_LIST_H_

