#include"Sort.h"

int main()
{
	//int arr[] = { 10,5,2,4,9,6,4,3,0,4,92,3,48,0,18,27 };
	srand(time(NULL));//�������������
	int arr[SIZE];
	int i = 0;
	for (i = 0; i < SIZE; i++)
	{
		arr[i] = rand();
	}
	Show(arr, sizeof(arr) / sizeof(arr[0]));
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));//�������� �ȶ� //˳���Ĳ���
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));//ϣ������ == ���������Ż� ���ȶ�(��Ԫ�ز���)

	//SelectSort1(arr, sizeof(arr) / sizeof(arr[0]));//ѡ������ //���ȶ�
	//SelectSort2(arr,sizeof(arr)/sizeof(arr[0]));//ѡ�������Ż� //
	//HeapSort(arr, sizeof(arr) / sizeof(arr[0]));//������ ���ȶ�

	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));//ð�� �ȶ� //��������
	//QuickSort1(arr, 0, sizeof(arr) / sizeof(arr[0]));//��������//�ݹ� //���ȶ�
	QuickSortNonR(arr,sizeof(arr) / sizeof(arr[0]));//��������//�ǵݹ� //���ȶ�

	//MergeSort(arr, sizeof(arr) / sizeof(arr[0]));//�鲢����

	Show(arr, sizeof(arr) / sizeof(arr[0]));
	system("pause");
	return 0;
}