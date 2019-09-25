#include"Sort.h"

int main()
{
	//int arr[] = { 10,5,2,4,9,6,4,3,0,4,92,3,48,0,18,27 };
	srand(time(NULL));//设置随机数种子
	int arr[SIZE];
	int i = 0;
	for (i = 0; i < SIZE; i++)
	{
		arr[i] = rand();
	}
	Show(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));//插入排序 稳定 //顺序表的插入
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));//希尔排序 == 插入排序优化 不稳定(隔元素插入)

	//SelectSort1(arr, sizeof(arr) / sizeof(arr[0]));//选择排序 //不稳定
	//SelectSort2(arr,sizeof(arr)/sizeof(arr[0]));//选择排序优化 //
	//HeapSort(arr, sizeof(arr) / sizeof(arr[0]));//堆排序 不稳定

	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));//冒泡 稳定 //交换排序
	//QuickSort1(arr, 0, sizeof(arr) / sizeof(arr[0]));//快速排序//递归 //不稳定
	QuickSortNonR(arr,sizeof(arr) / sizeof(arr[0]));//快速排序//非递归 //不稳定

	//MergeSort(arr, sizeof(arr) / sizeof(arr[0]));//归并排序

	Show(arr, sizeof(arr) / sizeof(arr[0]));
	system("pause");
	return 0;
}