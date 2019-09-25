#include"Sort.h"

void Swap(int *left, int *right)
{
	int tmp = *left;
	*left = *right;
	*right = tmp;
}

int Less(HDataType left, HDataType right)//小堆
{
	return left < right;
}

int Great(HDataType left, HDataType right)//大堆
{
	return left > right;
}

void AdjustDownWord(int *arr,int parent,Compare compare ,int size)//向下调整 
{
	int child = parent * 2 + 1;//左孩子
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

void HeapInit(HDataType *arr, int size)//堆的初始化
{
	int parent = (size - 2) / 2;
	while (parent >= 0)//通过向下调整建立小堆
	{
		AdjustDownWord(arr, parent, Great, size);
		parent--;
	}
}

void HeapSort(int *arr, int size)//堆排序
{
	int i = 0;
	HeapInit(arr+i, size-i);
	while (size > 1)
	{
		Swap(&arr[size - 1], &arr[0]);
		AdjustDownWord(arr, 0, Great, --size);
	}
}

void InsertSort(int *arr, int size)//插入排序 适用于序列接近有序or元素个数少 稳定
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

void ShellSort(int *arr, int size)//希尔排序 == 插入排序优化 不稳定(隔元素插入) //让数组一点一点变得更加有序
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

void SelectSort1(int *arr, int size)//选择排序 不稳定 缺陷：重复比较
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

void SelectSort2(int *arr, int size)//选择排序优化 不稳定
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

void BubbleSort(int *arr, int size)//冒泡排序
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

int Partion2(int *arr, int left, int right)//快速排序方法二（递归2）//不稳定 //分割法
{
	int i = left;
	int j = right - 1;
	int key = arr[right - 1];//基准值
	while (i < j)
	{
		while (j > i && arr[i] <= key)//找大的
		{
			i++;
		}
		while (j > i && arr[j] >= key)//找小的
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

int GetMiddeeIndex(int *array, int left, int right) //（三数取中法）hoare版本
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

int Partion3(int *arr, int left, int right)//快速排序方法三（递归3） 前后指针法
{
	int i = left;
	int j = left - 1;
	int mid = GetMiddeeIndex(arr, left, right);//优化一 
	Swap(&arr[mid], &arr[right - 1]);
	int key = arr[right - 1];
	while (i < right)
	{
		if (arr[i] < key && ++j != i)//j标记比key大的数中最左边的元素 //i寻找比key小的数和i交换
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
int Partion4(int *arr, int left, int right)//快速排序方法四//双指针法 不稳定
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

void QuickSort1(int *arr, int left, int right)//快速排序//递归//时间复杂度 最差O(n方)(单侧) 最优n(log n)(均分) //取三拿一做基准值（三数取中法）
{
	if (right - left < 10)//优化二
	{
		if (left == 0)
		{
			InsertSort(arr, right - left);//空间复杂度 log2N
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

void Show(int *arr, int size)//打印
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

void _MergeSort(int *arr, int *tmp, int start, int end)//归并排序  必须后序
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
void MergeSort(int *arr, int size)//归并排序 nlogn
{
	int *tmp = (int*)malloc(size*sizeof(int));
	_MergeSort(arr, tmp, 0, size-1);
	free(tmp);
}

void QuickSortNonR(int *arr, int size)//快排非递归 //效率低 省内存
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
		mid = Partion3(arr, start, end);//一次快排
		if (start < mid)//左孩子入队
		{
			QueuePush(&qu, start);
			QueuePush(&qu, mid);
		}
		if (mid+1 < end)//右孩子入队
		{
			QueuePush(&qu, mid+1);
			QueuePush(&qu, end);
		}
	}

	QueueDestroy(&qu);
}

 

void QueueInit(Queue *q)// 初始化
{
	assert(q);
	q->_back = NULL;
	q->_front = NULL;
}

QNode *BuyQueueNode(QDataType x)//创建一个新节点
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

void QueuePush(Queue *q, QDataType x)//入队列
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
void QueuePop(Queue *q)//出队列
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
QDataType QueueFrount(Queue *q)//获取头
{
	assert(q);
	return q->_front->_data;
}

QDataType QueueBack(Queue *q)//获取尾
{
	assert(q);
	return q->_back->_data;
}

int QueueSize(Queue *q)//队列大小
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
int QueueEmpty(Queue *q)//判空
{
	assert(q);
	return NULL == q->_front;
}

void QueueDestroy(Queue *q)//销毁
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

void QueueShow(Queue *q)//打印
{
	assert(q);
	QNode *qCur = q->_front;
	printf("元素是");
	while (qCur)
	{
		printf("%-3d", qCur->_data);
		qCur = qCur->_pNext;
	}
	printf("\n");
}
