#include"List.h"

void Funs()
{
	pList pHead = NULL;
	pList pTail = NULL;
	pListPushBack(&pTail, 3);
	pListPushBack(&pTail, 4);
	pListPushBack(&pTail, 5);
	pListPushBack(&pTail, 9);
	pListPushBack(&pHead, 1);//尾插
	pListPushBack(&pHead, 2);
	pListPushBack(&pHead, 3);
	pListPushBack(&pHead, 4);
	pListPushBack(&pHead, 5);
	pListPushBack(&pHead, 6);
	pListPushBack(&pHead, 7);
	pListShow(pHead);//打印
	pListShow(pTail);
	pListDeleteAll(&pHead, 2);
	pListShow(pHead);//打印
	pListReversal1(&pHead);//三指针逆置
	pListShow(pHead);
	pListReversal2(&pHead);//头插法逆置(不创建新节点)
	pListShow(pHead);
	pListReversal3(&pHead);//头插法逆置（创建新节点）
	pListShow(pHead);
	pListReciprocalKal(&pHead, 3);// 输入一个链表，输出该链表中倒数第k个结点
	pListFindMiddle(&pHead);//寻找中间节点
	pListReversal2(&pHead);//头插法逆置
	pListShow(pHead);
	pListShow(pTail);
	pList p = pListSplice(&pTail, &pHead);//合并两个有序链表
	pListShow(p);
}

int main()
{
	Funs();
	system("pause");
	return 0;
}