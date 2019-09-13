#include"List.h"

void Funs()
{
	pList pHead = NULL;
	pList pTail = NULL;
	pListPushBack(&pTail, 3);
	pListPushBack(&pTail, 4);
	pListPushBack(&pTail, 5);
	pListPushBack(&pTail, 9);
	pListPushBack(&pHead, 5);//尾插
	pListPushBack(&pHead, 6);//尾插
	pListPushBack(&pHead, 8);//尾插
	pListPushBack(&pHead, 2);
	pListPushBack(&pHead, 3);
	pListPushBack(&pHead, 4);
	pListPushBack(&pHead, 3);
	pListPushBack(&pHead, 2);
	pListPushBack(&pHead, 8);//尾插
	pListPushBack(&pHead, 6);//尾插
	pListPushBack(&pHead, 5);
	//pListPushBack(&pHead, 1);
	//pListPushBack(&pHead, 1);
	//pListPushBack(&pHead, 5);
	//pListPushBack(&pHead, 5);
	//pListPushBack(&pHead, 4);
	//pListPushBack(&pHead, 4);
	//pListPushBack(&pHead, 6);
	//pListPushBack(&pHead, 6);
	//pListPushBack(&pHead, 7);
	//pListPushBack(&pHead, 9);
	pListShow(pHead);//打印
	pListShow(pTail);
	pListDeleteAll(&pHead, 2);
	pListShow(pHead);//打印
	pListReversal1(&pTail);//三指针逆置
	pListShow(pTail);
	pListReversal2(&pHead);//头插法逆置(不创建新节点)
	pListShow(pHead);
	pListReversal3(&pHead);//头插法逆置（创建新节点）
	pListShow(pHead);
	pListReciprocalKal(&pHead, 3);// 输入一个链表，输出该链表中倒数第k个结点
	pListFindMiddle(&pHead);//寻找中间节点
	pListReversal2(&pHead);//头插法逆置
	pListShow(pHead);
	//pListShow(pTail);
	//pList p = pListSplice(&pTail, &pHead);//合并两个有序链表
	//pListShow(p);
	//pListShow(pHead);
	//pList two = pListTwoPart(&pHead, 2);//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
	//pListShow(two);
	//pListDeleteDuplication(&pHead);////在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头 指针
	//pListShow(pHead);
	int ret1 = pListSymmetric1(&pHead);//新建数组回文
	printf("%d\n", ret1);
	int ret2 = pListSymmetric2(&pHead);//逆转回文
	printf("%d\n", ret2);
	pTail->_pNext->_pNext = pHead->_pNext;//构建具有公共节点的两个单链表
	pListShow(pHead);
	pListShow(pTail);
	int ret = pListPublic(&pHead, &pTail);//// 输入两个链表，找出它们的第一个公共结点。
	printf("%d\n", ret);
	DataType k = pListYNRing(&pHead);//判断链表中是否有环
	printf("%d\n", k);
	pListRing(&pHead);//构建一个带环链表
	k = pListYNRing(&pHead);//判断链表中是否有环
	printf("%d\n", k);
	pListFirstRingNode(&pHead);//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
}

int main()
{
	Funs();
	system("pause");
	return 0;
}