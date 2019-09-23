#ifndef _BINTREE_C_
#define _BINTREE_C_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

typedef char BTDataType;
typedef struct BTNode//�������ڵ�
{
	struct BTNode *_pLeft;//���ӱ�ʾ��
	struct BTNode *_pRight;
	BTDataType data;
}BTNode;

typedef struct Copy//�����ṹ
{
	BTNode** beCopy;
	BTNode** Copy;
}Copy;


typedef BTNode* QDataType;

typedef struct QNode//���нڵ�
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;

typedef struct Queue//��������ָ�룬�ֱ�ָ���ͷ�Ͷ�β�Ľڵ�
{
	QNode * _front;//��ͷ
	QNode * _back;//��β
}Queue;

void QueueInit(Queue *q);// ��ʼ��
void QueuePush(Queue *q, QDataType x);//�����
void QueuePop(Queue *q);//������
QDataType QueueFrount(Queue *q);//��ȡͷ
QDataType QueueBack(Queue *q);//��ȡβ
int QueueSize(Queue *q);//���д�С
int QueueEmpty(Queue *q);//�п�
void QueueDestroy(Queue *q);//����
void QueueShow(Queue *q);//��ӡ


void PreOrder(BTNode *pRoot);//ǰ���������-������������-������������
void InOrder(BTNode *pRoot);//�������������������-����-������������
void PostOrder(BTNode *pRoot);//�������������������-������������-����
void LeveIOrder(BTNode *pRoot);//�������
BTNode *_CreateBinTree(char *array, int size, int* index, BTDataType invalid);//�������Ľ���
BTNode *CreateBinTree(char *array, int size, BTDataType invaild);
void DestroyBinTree(BTNode **pRoot);//������������
Copy *CopyBinTree(BTNode **pRoot, BTNode **p);//�������Ŀ��� 
int GetBinTreeSize(BTNode *pRoot);//����������ж��ٸ��ڵ�
int GetLeafCount(BTNode *pRoot);//������������ж��ٸ�Ҷ�ӽڵ�
int GetBinTreeHeight(BTNode *pRoot);//�����������
int GetKLeveNodeCount1(BTNode *pRoot,int k);//��ȡ�������е�k��Ľڵ���1
int GetKLeveNodeCount2(BTNode *pRoot, int k);//��ȡ�������е�k��Ľڵ���2
BTNode *BinaryTreeFind(BTNode *root, BTDataType x);//����ΪxԪ�ص�λ��
void Mirror(BTNode *pRoot);//���������� ����
void MirrorNor(BTNode *pRoot);//��龵���Ƿ�ɹ�
void Swap(BTNode **left, BTNode **right);//���������� ǰ��

#endif // !_BINTREE_C_
