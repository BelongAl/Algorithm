#ifndef _HEAP_H_
#define _HEAP_H_


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int heapType;

typedef int(*Compare)(heapType, heapType);


typedef struct Heap
{
	int *arr;
	int _capacity;
	int _size;
	Compare _compare;
}Heap;


void _CheckCapacity(Heap *heap)//����
{
	if (heap->_capacity == heap->_size)
	{
		heap->_capacity *= 2;
		heapType *arr = (heapType*)realloc(heap->arr, sizeof(heapType)*heap->_capacity);
		if (arr == NULL)
		{
			return;
		}
		heap->arr = arr;
	}
}

void InsetHeap(Heap *heap, int data)//���뺯��
{
	assert(heap);
	_CheckCapacity(heap);
	heap->arr[heap->_size++] = data;
	heap->_size;
}

void InitHeap(Heap *heap, Compare compare)//�ѵĳ�ʼ��
{
	heap->arr = (heapType*)malloc(sizeof(heapType) * 3);
	heap->_capacity = 3;
	heap->_size = 0;
	heap->_compare = compare;
}

void Swap(heapType *left, heapType *right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}


void DoAdjustment(int *arr, int parent, int size)//���µ���
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
		}
		parent = child;
		child = parent * 2 + 1;
	}
}

void UpAdjustment(Heap *heap, int child)//���ϵ���
{
	assert(heap);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (heap->_compare(heap->arr[child], heap->arr[parent]))
		{
			Swap(&heap->arr[child], &heap->arr[parent]);
		}
		child = parent;
		parent = (child - 1) / 2;
	}
}

void GreatHeap(Heap * heap, int *arr, int size)//������
{
	assert(heap);
	for (int i = 0; i < size; i++)
	{
		InsetHeap(heap, *(arr + i));

		UpAdjustment(heap, i);
	}
}
#endif