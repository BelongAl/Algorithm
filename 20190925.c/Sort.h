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


void Swap(int *left,int *right);//交换
int Less(HDataType left, HDataType right);//小堆
int Great(HDataType left, HDataType right);//大堆
void AdjustDownWord(int *arr, int parent, Compare compare, int size);//向下调整 
void HeapInit(HDataType *arr, int size);//堆的初始化
void InsertSort(int *arr, int size);//插入排序 适用于序列接近有序or元素个数少 稳定
void ShellSort(int *arr, int size);//希尔排序 == 插入排序优化 不稳定(隔元素插入)
void SelectSort1(int *arr, int size);//选择排序 不稳定 缺陷：重复比较
void SelectSort2(int *arr, int size);//选择排序优化 不稳定
void HeapSort(int *arr, int size);//堆排序
void BubbleSort(int *arr, int size);//冒泡排序
int Partion1(int *arr, int left, int right);//快速排序方法一(递归1)
int Partion2(int *arr, int left, int right);//快速排序方法二（递归2）//不稳定
int GetMiddeeIndex(int *array, int left, int right); //（三数取中法）
int Partion3(int *arr, int left, int right);//快速排序方法三（递归3）
void QuickSort1(int *arr, int left, int right);//快速排序//递归//时间复杂度 最差O(n方)(单侧) 最优n(log n)(均分) //取三拿一做基准值（三数取中法）
void MergeSort(int *arr, int size);//归并排序
void Show(int *arr, int size);//打印
int Max(int a, int b);
int Min(int a, int b);
void QuickSortNonR(int *arr, int right);//快排非递归


#endif // !_HEAP_H_
