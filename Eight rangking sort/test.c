#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"heap.h"
#include"stack.h"

int Less(heapType left, heapType right)
{
	return left < right;
}

int Great(heapType left, heapType right)
{
	return left > right;
}


//Insertion sort
void InsertSort(int* arr, int size)
{
	int index = 0;
	for(index = 0; index < size; index++)
	{
		int key = arr[index];
		int sindex = index - 1;
		for (sindex; sindex >= 0; sindex--)
		{
			if (key >= arr[sindex])
			{
				break;
			}
			else
			{
				arr[sindex+1] = arr[sindex];
			}
		}
		arr[sindex + 1] = key;
	}
}

//Shell sort
void ShellSort(int *arr, int size)
{
	for (int k = 5; k > 0; k--)
	{
		for (int i = k; i < size; i++)
		{
			int key = arr[i];
			int end = i - k;
			while (end >=0 && key < arr[end])
			{
				arr[end + k] = arr[end];
				end -= k;
			}
			arr[end + k] = key;
		}
	}
}

//selection sort

void SelectionSort(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = arr[i];
		int count = i;
		for (int j = i; j < size; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				count = j;
			}
		}
		Swap(&arr[i], &arr[count]);
	}
}

//heap sort
void HeapSort(int *arr, int size)
{
	Heap hp;
	InitHeap(&hp,Great);
	GreatHeap(&hp, arr, size);
	for (int i = 0; i < size; i++)
	{
		arr[i] = hp.arr[i];
	}
	while (size > 0)
	{
		Swap(&arr[0], &arr[size-1]);
		size--;
		DoAdjustment(arr, 0, size);
	}
}

//exchange sort
void BubbSort(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

//quick sort
void _QuickSort(int *arr, int left ,int right)
{
	if (left >= right)
	{
		return;
	}
	int tmp = arr[left];
	int l = left;
	int r = right;
	while (left < right)
	{
		while (right > left && arr[right] >= tmp)
		{
			right--;
		}
		Swap(&arr[left], &arr[right]);
		while (right > left && arr[left] <= tmp)
		{
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	_QuickSort(arr, l, right - 1);
	_QuickSort(arr, right+1, r);
}
void QuickSort(int *arr, int size)
{
	_QuickSort(arr, 0, size-1);
}

//merge sort
void _MergeSort(int *arr, int *tmp, int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	_MergeSort(arr, tmp, start, mid);
	_MergeSort(arr, tmp, mid+1,end);
	int count = mid+1;
	int a = start;
	int i = start;
	while (start <= mid && count <= end)
	{
		if (arr[start] <= arr[count])
		{
			tmp[i++] = arr[start++];
		}
		else
		{
			tmp[i++] = arr[count++];
		}
	}
	while (start <= mid)
	{
		tmp[i++] = arr[start++];
	}
	while (count <= end)
	{
		tmp[i++] = arr[count++];
	}
	for (i = a; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}
void MergeSort(int *arr, int size)
{
	int *tmp = (int*)malloc(sizeof(int)*size);
	_MergeSort(arr,tmp,0,size-1);
	free(tmp);
}

//Non comparison sort
void NCompSort(int *arr, int size)
{
	int count = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (count < arr[i])
		{
			count = arr[i];
		}
	}
	int *tmp = (int*)calloc(count + 1, sizeof(int));

	for (int i = 0; i < size; i++)
	{
		tmp[arr[i]]++;
	}
	int i = 0;
	int j = 0;
	while (i < count+1)
	{
		if (tmp[i] > 0)
		{
			arr[j] = i;
			tmp[i]--;
			j++;
			i--;
		}
		i++;
	}
}

int Partion1(int *arr, int left, int right)//快速排序方法一(递归1)//挖坑法
{
	int i = left;
	int j = right - 1;
	int key = arr[left];
	while (i < j)
	{
		while (j > i && arr[j] >= key)
		{
			j--;
		}
		arr[i] = arr[j];
		while (j > i && arr[i] <= key)
		{
			i++;
		}
		arr[j] = arr[i];
	}
	arr[i] = key;
	return i;
}

void NreQuickSort(int *arr, int size)
{
	Stack st;
	StackInit(&st);
	StackPush(&st,size);
	StackPush(&st,0);
	while (!StackEmpty(&st))
	{
		int left = StackTop(&st);
		StackPop(&st);
		int right = StackTop(&st);
		int mid = Partion1(arr, left, right);
		if (mid > left)
		{
			StackPush(&st, mid);
			StackPush(&st, left);
		}
		if (right > mid+1)
		{
			StackPush(&st, right);
			StackPush(&st, mid + 1);
		}
	}
}

int main()
{
	int arr[] = { 4,7,2,8,0,9,8,1,5,6 };
	for (int i = 0; i < 10; i++)
	{
		printf("%-3d", arr[i]);
	}
	printf("\n");
	//InsertSort(arr,sizeof(arr)/sizeof(arr[0]));
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectionSort(arr, sizeof(arr) / sizeof(arr[0]));
	//HeapSort(&arr, sizeof(arr) / sizeof(arr[0]));
	//BubbSort(arr, sizeof(arr) / sizeof(arr[0]));
	//QuickSort(arr,sizeof(arr)/sizeof(arr[0]));
	//MergeSort(arr, sizeof(arr) / sizeof(arr[0]));
	//NCompSort(arr, sizeof(arr) / sizeof(arr[0]));
	NreQuickSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < 10; i++)
	{
		printf("%-3d", arr[i]);
	}
	system("pause");
	return 0;
}