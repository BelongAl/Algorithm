#ifndef _HEAP_H_
#define _HEAP_H_

#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>

typedef int QDataType;

typedef struct QNode
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;

typedef struct Queue
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

#define SIZE 100000
typedef int HDataType;

typedef int(*Compare) (HDataType, HDataType);


typedef struct Heap
{
	HDataType *_array;
	int _capacity;
	int _size;
	Compare _pCor;
}Heap;


void Swap(int *left,int *right);//����
int Less(HDataType left, HDataType right);//С��
int Great(HDataType left, HDataType right);//���
void AdjustDownWord(int *arr, int parent, Compare compare, int size);//���µ��� 
void HeapInit(HDataType *arr, int size);//�ѵĳ�ʼ��
void InsertSort(int *arr, int size);//�������� ���������нӽ�����orԪ�ظ����� �ȶ�
void ShellSort(int *arr, int size);//ϣ������ == ���������Ż� ���ȶ�(��Ԫ�ز���)
void SelectSort1(int *arr, int size);//ѡ������ ���ȶ� ȱ�ݣ��ظ��Ƚ�
void SelectSort2(int *arr, int size);//ѡ�������Ż� ���ȶ�
void HeapSort(int *arr, int size);//������
void BubbleSort(int *arr, int size);//ð������
int Partion1(int *arr, int left, int right);//�������򷽷�һ(�ݹ�1)
int Partion2(int *arr, int left, int right);//�������򷽷������ݹ�2��//���ȶ�
int GetMiddeeIndex(int *array, int left, int right); //������ȡ�з���
int Partion3(int *arr, int left, int right);//�������򷽷������ݹ�3��
void QuickSort1(int *arr, int left, int right);//��������//�ݹ�//ʱ�临�Ӷ� ���O(n��)(����) ����n(log n)(����) //ȡ����һ����׼ֵ������ȡ�з���
void MergeSort(int *arr, int size);//�鲢����
void Show(int *arr, int size);//��ӡ
int Max(int a, int b);
int Min(int a, int b);
void QuickSortNonR(int *arr, int right);//���ŷǵݹ�


#endif // !_HEAP_H_
