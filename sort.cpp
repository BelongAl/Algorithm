#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

//ð������  �Ƚ� ���� �ȶ�
void bubble_Sort(int (&array)[10])
{
	int size = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j],array[j+1]);
			}
		}
	}
}

//�������� ���δ���� ����δ�����滻 �ȶ�
void insert_Sort(int (&array)[10])
{
	int size = sizeof(array) / sizeof(array[0]);
	for (int i = 1; i < size; i++)
	{
		int key = array[i];
		int end = i - 1;
		while (end >= 0 && array[end] > key)
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end+1] = key;
	}
}

//ϣ������ �ı����� ��������� ���ȶ�
void shell_Sort(int(&array)[10])
{
	int grap = 3;
	int size = sizeof(array) / sizeof(array[0]);
	while (grap > 0)
	{
		for (int i = grap; i < size; i++)
		{
			int key = array[i];
			int end = i - grap;
			while (end >= 0 && array[end] > key)
			{
				array[end + grap] = array[end];
				end -= grap;
			}
			array[end + grap] = key;
		}
		grap--;
	}
}

//�������� ������Ԫ���������� �ȶ�
void swap_Sort(int (&array)[10])
{
	int size = sizeof(array) / sizeof(array[0]);
	for (int i = size-1; i > 0; i--)
	{
		int max = i;
		for (int j = i-1; j >= 0; j--)
		{
			if (array[max] < array[j])
			{
				max = j;
			}
		}
		swap(array[i], array[max]);
	}
}

class Heap
{
	void adjustUp(int(&array)[10], int i)//���ϵ���  ����
	{
		while (i > 0)
		{
			if (array[i] > array[(i - 1) / 2])
			{
				swap(array[i], array[(i-1)/2]);
				i = (i - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
	void adjustDown(int(&array)[10], int size)//���µ��� ����
	{
		int parent = 0;
		int child = parent * 2 + 1;
		while (child < size)
		{
			if (child + 1 < size && array[child] < array[child + 1])
			{
				child++;
			}
			if (array[child] > array[parent])
			{
				swap(array[child], array[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}

public:
	void heap_Sort(int (&array)[10])
	{
		int size = sizeof(array) / sizeof(array[0]);
		for (int i = 0; i < size; i++)
		{
			adjustUp(array,i);//���ϵ�����������
		}

    	for (int i = size-1; i > 0; i--)
		{
			swap(array[0], array[i]);
			adjustDown(array, i);//���µ��� ����
		}

	}
};


void m_merge_Sort(int (&array)[10], int *tmp, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	m_merge_Sort(array, tmp, begin, mid);
	m_merge_Sort(array, tmp, mid+1, end);
	int a = begin;
	int b = mid+1;
	int c = begin;
	while (a <=  mid  && b <= end)
	{
		if (array[a] <= array[b])
		{
			tmp[c] = array[a++];
		}
		else
		{
			tmp[c] = array[b++];
		}
		c++;
	}
	while (a <= mid)
	{
		tmp[c++] = array[a++];
	}
	while (b <= end)
	{
		tmp[c++] = array[b++];
	}

	int i = 0;
	for (i = begin; i <= end; i++)
	{
		array[i] = tmp[i];
	}


}
void merge_Sort(int (&array)[10])//�鲢����
{
	int size = sizeof(array) / sizeof(array[0]);
	int *tmp = (int*)malloc(size * sizeof(int));
	m_merge_Sort(array, tmp, 0, size-1);
	for (int i = 0; i < size; i++)
	{
		array[i] = tmp[i];
	}
}

int m_quick_Sort(int(&array)[10], int begin, int end)
{
	int key = array[begin];
	int i = begin;
	int j = end;
	while (j > i)
	{
		while (array[j] >= key && j > i)//��С��
		{
			j--;
		}
		while(array[i] <= key && j > i)//�Ҵ��
		{
			i++;
		}
		if (i != j)
		{
			swap(array[i], array[j]);
		}
	}
	if (i != begin)
	{
		swap(array[i], array[begin]);
	}
	return i;
}
void m_quick(int(&array)[10], int begin, int end)
{
	if (end - begin <= 1)
	{
		return;
	}
	else
	{
		int ret = m_quick_Sort(array, begin, end);
		m_quick(array, begin, ret);
		m_quick(array, ret + 1, end);
	}
}

void quick_Sort1(int (&array)[10])//�������� �ݹ�
{
	int size = sizeof(array) / sizeof(array[0]);
	m_quick(array, 0, size-1);
}

void quick_Sort2(int(&array)[10])//�������� �ǵݹ�
{
	int size = sizeof(array) / sizeof(array[0]);

	queue<int> q_quick;
	q_quick.push(0);
	q_quick.push(size-1);

	while(!q_quick.empty())
	{
		int start = q_quick.front();
		q_quick.pop();
		int end = q_quick.front();
		q_quick.pop();
		int mid = m_quick_Sort(array, start, end);
		if (mid > start)
		{
			q_quick.push(start);
			q_quick.push(mid);
		}
		if (mid+1 < end)
		{
			q_quick.push(mid + 1);
			q_quick.push(end);
		}
	}
}

void bucket_Sort(int(&array)[14])//Ͱ����
{
	int size = sizeof(array) / sizeof(array[0]);
	vector<vector<int>> v(size);

	for (int i = 0; i < size; i++)
	{
		v[array[i] / 10].push_back(array[i]);
	}
	for (int i = 0; i < size; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	int k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			array[k] = v[i][j];
			k++;
		}
	}
}

int getDigit(int number, int digit)//��ȡ����digitλ����
{
	int k = pow(10, digit - 1);
	return (number / k) % 10;
}
int get_max_number(int(&array)[14])//��ȡ���λ
{
	int size = sizeof(array) / sizeof(array[0]);
	int max = array[0];
	for (int i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	int ret = 0;
	while (max)
	{
		ret++;
		max /= 10;
	}
	return ret;
}

void radix_Sort(int(&array)[14])//��������
{
	int size = sizeof(array) / sizeof(array[0]);

	int max_digit = get_max_number(array);//��ȡ���λ��
	vector<vector<int>> v(size);

	int digit = 1;

	while (digit <= max_digit)//����λ����
	{
		int k = 0;
		for (int i = 0; i < size; i++)
		{
			v[getDigit(array[i], digit)].push_back(array[i]);
		}
		for (int i = 0; i < size; i++)//��v�е�˳����array
		{
			int j = 0;
			while (j < v[i].size())
			{
				array[k] = v[i][j];
				j++;
				k++;
			}
			v[i].clear();
		}
		digit++;	
	}



}


int main()
{
	int arr[14] = { 6,354,8,100,97,4,56,0,2,7,15,29,40,24 };
	//bubble_Sort(arr);
	//insert_Sort(arr);
	//shell_Sort(arr);
	//swap_Sort(arr);
	//Heap hs;
	//hs.heap_Sort(arr);���ȶ�
	//merge_Sort(arr);�ȶ�
	//quick_Sort1(arr); ���ȶ�
	//quick_Sort2(arr);
	//bucket_Sort(arr);�ȶ�
	radix_Sort(arr);//��������

	for (int i = 0; i < 14; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}