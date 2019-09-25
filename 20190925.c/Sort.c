#include"Sort.h"

void Swap(int *left, int *right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

int Less(HDataType left, HDataType right)//С��
{
	return left < right;
}

int Great(HDataType left, HDataType right)//���
{
	return left > right;
}

void AdjustDownWord(int *arr,int parent,Compare compare ,int size)//���µ��� 
{
	int child = parent * 2 + 1;//����
	while (child < size)
	{
		if (child + 1 < size && compare(arr[child+1],arr[child]))
		{	
			child++;
		}
		if (compare(arr[child], arr[parent]))
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}

void HeapInit(HDataType *arr, int size)//�ѵĳ�ʼ��
{
	int parent = (size - 2) / 2;
	while (parent >= 0)//ͨ�����µ�������С��
	{
		AdjustDownWord(arr, parent, Great, size);
		parent--;
	}
}

void HeapSort(int *arr, int size)//������
{
	int i = 0;
	HeapInit(arr+i, size-i);
	while (size > 1)
	{
		Swap(&arr[size - 1], &arr[0]);
		AdjustDownWord(arr, 0, Great, --size);
	}
}

void InsertSort(int *arr, int size)//�������� ���������нӽ�����orԪ�ظ����� �ȶ�
{
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int end = i - 1;
		while (end >= 0 && arr[end] > key)
		{
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = key;
	}
}

void ShellSort(int *arr, int size)//ϣ������ == ���������Ż� ���ȶ�(��Ԫ�ز���) //������һ��һ���ø�������
{
	for (int gap = 10; gap > 0; gap /= 3)
	{
		for (int i = gap; i < size; i++)
		{
			int key = arr[i];
			int end = i - gap;
			while (end >= 0 && arr[end] > key)
			{
				arr[end + gap] = arr[end];
				end = end - gap;
			}
			arr[end + gap] = key;
		}
	}
}

void SelectSort1(int *arr, int size)//ѡ������ ���ȶ� ȱ�ݣ��ظ��Ƚ�
{
	int max = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < size; i++)
	{
		max = arr[0];
		for (j = 1; j < size - i; j++)
		{
			if (arr[j] > arr[max])
			{
				max = j;
			}
		}
		if (max != j - 1)
		{
			Swap(&arr[j - 1], &arr[max]);
		}
	}
}

void SelectSort2(int *arr, int size)//ѡ�������Ż� ���ȶ�
{
	int end = size - 1;
	int begin = 0;
	while (begin < end)
	{
		int max = begin;
		int min = begin;
		int index = begin + 1;
		while (index <= end)
		{
			if (arr[min] > arr[index])
			{
				min = index;
			}
			if (arr[max] < arr[index])
			{
				max = index;
			}
			index++;
		}
		if (max != end)
		{
			Swap(&arr[max], &arr[end]);
		}
		if (min == end)
		{
			min = max;
		}
		if (min != begin)
		{
			Swap(&arr[min], &arr[begin]);
		}
		begin++;
		end--;
	}
}

void BubbleSort(int *arr, int size)//ð������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < size; i++)
	{
		int count = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				count = 1;
				Swap(&arr[j], &arr[j + 1]);
			}
		}
		if (0 == count)
		{
			break;
		}
	}
}

int Partion1(int *arr, int left, int right)//�������򷽷�һ(�ݹ�1)//�ڿӷ�
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

int Partion2(int *arr, int left, int right)//�������򷽷������ݹ�2��//���ȶ� //�ָ
{
	int i = left;
	int j = right - 1;
	int key = arr[right - 1];//��׼ֵ
	while (i < j)
	{
		while (j > i && arr[i] <= key)//�Ҵ��
		{
			i++;
		}
		while (j > i && arr[j] >= key)//��С��
		{
			j--;
		}
		if (i != j)
		{
			Swap(&arr[i], &arr[j]);
		}
	}
	if (i != right - 1)
	{
		Swap(&arr[i], &arr[right - 1]);
	}
	return i;
}

int GetMiddeeIndex(int *array, int left, int right) //������ȡ�з���hoare�汾
{
	int mid = (left + right) / 2;
	if (array[left] <= array[right - 1])
	{
		if (array[mid] < array[left])
		{
			return left;
		}
		else if (array[mid] > array[right - 1])
		{
			return right - 1;
		}
		else
		{
			return mid;
		}
	}
	if (array[left] > array[right - 1])
	{
		if (array[mid] > array[left])
		{
			return left;
		}
		else if (array[mid] < array[right - 1])
		{
			return right - 1;
		}
		else
		{
			return mid;
		}
	}
}

int Partion3(int *arr, int left, int right)//�������򷽷������ݹ�3�� ǰ��ָ�뷨
{
	int i = left;
	int j = left - 1;
	int mid = GetMiddeeIndex(arr, left, right);//�Ż�һ 
	Swap(&arr[mid], &arr[right - 1]);
	int key = arr[right - 1];
	while (i < right)
	{
		if (arr[i] < key && ++j != i)//j��Ǳ�key�����������ߵ�Ԫ�� //iѰ�ұ�keyС������i����
		{
			Swap(&arr[i], &arr[j]);
		}
		i++;
	}
	if (++j != right)
	{
		Swap(&arr[j], &arr[right - 1]);
	}
	return j;
}
int Partion4(int *arr, int left, int right)//�������򷽷���//˫ָ�뷨 ���ȶ�
{
	int i = left;
	int j = right-1;
	int flag = 0;
	while (i < j)
	{
		while (i < j && arr[i] <= arr[j])
		{
			flag ? i++ : j--;
		}
		Swap(&arr[i], &arr[j]);
		flag = !flag;
	}
	return i;
}

void QuickSort1(int *arr, int left, int right)//��������//�ݹ�//ʱ�临�Ӷ� ���O(n��)(����) ����n(log n)(����) //ȡ����һ����׼ֵ������ȡ�з���
{
	if (right - left < 10)//�Ż���
	{
		if (left == 0)
		{
			InsertSort(arr, right - left);//�ռ临�Ӷ� log2N
		}
		else
		{
			InsertSort(arr + left, right - left);
		}
	}
	if (right - left > 1)
	{
		int div = Partion1(arr, left, right);
		QuickSort1(arr, left, div);
		QuickSort1(arr, div + 1, right);
	}
}

void Show(int *arr, int size)//��ӡ
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%-8d", arr[i]);
	}
	printf("\n");
}

int Max(int a, int b)
{
	return a > b ? a : b;
}
int Min(int a, int b)
{
	return a < b ? a : b;
}

void _MergeSort(int *arr, int *tmp, int start, int end)//�鲢����  �������
{
	if (start >= end)
	{
		return;
	}
	int mid = (start + end) / 2;
	_MergeSort(arr, tmp, start, mid);
	_MergeSort(arr, tmp, mid+1, end);
	int a = start;
	int b = mid + 1;
	int c = start;
	while (a <= mid && b <= end)
	{
		if (arr[a] <= arr[b])
		{
			tmp[c] = arr[a];
			a++;
			c++;
		}
		else
		{
			tmp[c] = arr[b];
			b++;
			c++;
		}
	}
	for (; a <= mid; a++,c++)
	{
		tmp[c] = arr[a];
	}
	for (; b <= end; b++,c++)
	{
		tmp[c] = arr[b];
	}
	int i = 0;
	for (i = start; i <= end; i++)
	{
		arr[i] = tmp[i];
	}
}
void MergeSort(int *arr, int size)//�鲢���� nlogn
{
	int *tmp = (int*)malloc(size*sizeof(int));
	_MergeSort(arr, tmp, 0, size-1);
	free(tmp);
}

void QuickSortNonR(int *arr, int size)//���ŷǵݹ� //Ч�ʵ� ʡ�ڴ�
{
	int start = 0;
	int end = size;
	int mid;
	Queue qu;
	QueueInit(&qu);
	QueuePush(&qu, start);
	QueuePush(&qu, end);
	while (!QueueEmpty(&qu))
	{
		start = QueueFrount(&qu);
		QueuePop(&qu);
		end = QueueFrount(&qu);
		QueuePop(&qu);
		mid = Partion3(arr, start, end);//һ�ο���
		if (start < mid)//�������
		{
			QueuePush(&qu, start);
			QueuePush(&qu, mid);
		}
		if (mid+1 < end)//�Һ������
		{
			QueuePush(&qu, mid+1);
			QueuePush(&qu, end);
		}
	}

	QueueDestroy(&qu);
}

 

void QueueInit(Queue *q)// ��ʼ��
{
	assert(q);
	q->_back = NULL;
	q->_front = NULL;
}

QNode *BuyQueueNode(QDataType x)//����һ���½ڵ�
{
	QNode* pNewNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return;
	}
	pNewNode->_data = x;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

void QueuePush(Queue *q, QDataType x)//�����
{
	assert(q);
	QNode *pNewNode = BuyQueueNode(x);
	if (QueueEmpty(q))
	{
		q->_back = pNewNode;
		q->_front = pNewNode;
	}
	else
	{
		q->_back->_pNext = pNewNode;
		q->_back = pNewNode;
	}
}
void QueuePop(Queue *q)//������
{
	assert(q);
	if (q->_front == NULL)
	{
		return;
	}
	QNode *pDelete = q->_front;
	if (NULL == q->_front)
	{
		q->_back = NULL;
		q->_front = NULL;
	}
	else
	{
		q->_front = q->_front->_pNext;
	}
	free(pDelete);
}
QDataType QueueFrount(Queue *q)//��ȡͷ
{
	assert(q);
	return q->_front->_data;
}

QDataType QueueBack(Queue *q)//��ȡβ
{
	assert(q);
	return q->_back->_data;
}

int QueueSize(Queue *q)//���д�С
{
	assert(q);
	int count = 0;
	QNode *pCur = q->_front;
	while (pCur)
	{
		pCur = pCur->_pNext;
		count++;
	}
	return count;
}
int QueueEmpty(Queue *q)//�п�
{
	assert(q);
	return NULL == q->_front;
}

void QueueDestroy(Queue *q)//����
{
	assert(q);
	QNode *pCur = q->_front;
	while (pCur)
	{
		q->_front = pCur->_pNext;
		free(pCur);
		pCur = q->_front;
	}
	q->_back = NULL;
	q->_front = NULL;
}

void QueueShow(Queue *q)//��ӡ
{
	assert(q);
	QNode *qCur = q->_front;
	printf("Ԫ����");
	while (qCur)
	{
		printf("%-3d", qCur->_data);
		qCur = qCur->_pNext;
	}
	printf("\n");
}
