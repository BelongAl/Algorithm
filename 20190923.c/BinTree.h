#ifndef _BINTREE_C_
#define _BINTREE_C_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef char BTDataType;
typedef struct BTNode//二叉树节点
{
	struct BTNode *_pLeft;//孩子表示法
	struct BTNode *_pRight;
	BTDataType data;
}BTNode;

typedef struct Copy//拷贝结构
{
	BTNode** beCopy;
	BTNode** Copy;
}Copy;


typedef BTNode* QDataType;

typedef struct QNode//队列节点
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;

typedef struct Queue//定义两个指针，分别指向队头和队尾的节点
{
	QNode * _front;//队头
	QNode * _back;//队尾
}Queue;

void QueueInit(Queue *q);// 初始化
void QueuePush(Queue *q, QDataType x);//入队列
void QueuePop(Queue *q);//出队列
QDataType QueueFrount(Queue *q);//获取头
QDataType QueueBack(Queue *q);//获取尾
int QueueSize(Queue *q);//队列大小
int QueueEmpty(Queue *q);//判空
void QueueDestroy(Queue *q);//销毁
void QueueShow(Queue *q);//打印


void PreOrder(BTNode *pRoot);//前序遍历：根-》根的左子树-》根的右子树
void InOrder(BTNode *pRoot);//中序遍历：根的左子树-》根-》根的右子树
void PostOrder(BTNode *pRoot);//后序遍历：根的左子树-》根的右子树-》根
void LeveIOrder(BTNode *pRoot);//层序遍历
BTNode *_CreateBinTree(char *array, int size, int* index, BTDataType invalid);//二叉树的建立
BTNode *CreateBinTree(char *array, int size, BTDataType invaild);
void DestroyBinTree(BTNode **pRoot);//二叉树的销毁
Copy *CopyBinTree(BTNode **pRoot, BTNode **p);//二叉树的拷贝 
int GetBinTreeSize(BTNode *pRoot);//计算二叉树有多少个节点
int GetLeafCount(BTNode *pRoot);//计算二叉树中有多少个叶子节点
int GetBinTreeHeight(BTNode *pRoot);//计算树的深度
int GetKLeveNodeCount1(BTNode *pRoot,int k);//获取二叉树中第k层的节点数1
int GetKLeveNodeCount2(BTNode *pRoot, int k);//获取二叉树中第k层的节点数2
BTNode *BinaryTreeFind(BTNode *root, BTDataType x);//返回为x元素的位置
void Mirror(BTNode *pRoot);//二叉树镜像 层序
void MirrorNor(BTNode *pRoot);//检查镜像是否成功
void Swap(BTNode **left, BTNode **right);//二叉树镜像 前序

#endif // !_BINTREE_C_
