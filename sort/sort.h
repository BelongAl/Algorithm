#pragma once

#include<vector>
#include<algorithm>
#include<stack>

typedef bool(*compare)(int, int);

bool Great(int left, int right)
{
	return left > right;
}
bool Less(int left, int right)
{
	return left < right;
}

class Sort
{
public:
	//bubble sort
	//O(n)-O(n^2)
	void BubbleSort(std::vector<int> v)
	{
		int i = 0;
		int j = 0;
		int index = 0;
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v.size() - 1 - i; j++)
			{
				if (v[j + 1] < v[j])
				{
					std::swap(v[j+1], v[j]);
					index = 1;
				}
			}
			if (index = 0)
			{
				break;
			}
			index = 0;
		}
		Print(v);
	}

	//quick sort
	void QuickSort(std::vector<int> v)
	{
		int left = 0;
		int right = v.size() - 1;
		modular(v, left, right);
		Print(v);
	}

	//insert sort
	//��������������С�����ݻ��Ҷȵ׵����  O(n)-O(n^2)
	void InsertSort(std::vector<int> v)
	{
		int key = 0;
		for (int i = 1; i < v.size(); i++)
		{
			key = v[i];//��ǵ�һ��δ�����Ԫ�أ�
			int end = i - 1;//Ѱ��key�����keyС��Ԫ��
			while (end >= 0 && v[end] > key)
			{
				v[end + 1] = v[end];
				end--;
			}
			v[end + 1] = key;
		}
		Print(v);
	}

	//shell sort
	//���ڲ���������Ż���ʹ�ø����󽵵�����Ҷ�
	void ShellSort(std::vector<int> v)
	{
		for (int grap = 10; grap > 0; grap /= 3)
		{
			int key = 0;
			for (int i = grap; i < v.size(); i++)
			{
				key = v[i];//��ǵ�һ��δ�����Ԫ�أ�
				int end = i - grap;//Ѱ��key�����keyС��Ԫ��
				while (end >= 0 && v[end] > key)
				{
					v[end + grap] = v[end];
					end -= grap;
				}
				v[end + grap] = key;
			}
		}
		Print(v);
	}

	//select sort
	void SlectSort(std::vector<int> v)
	{
		int begin = 0;
		int end = v.size() - 1;
		while (end > begin)
		{
			//Ѱ����С����ǰ��
			//Ѱ�����������
			int min = begin;
			int max = end;
			for (int i = begin; i <= end; i++)
			{
				if (v[i] < v[min])
				{
					min = i;
				}
				if (v[i] > v[max])
				{
					max = i;
				}
			}
			std::swap(v[min], v[begin]);
			if (max == begin)
			{
				max = min;
			}
			std::swap(v[max], v[end]);
			end--;
			begin++;
		}
		Print(v);
	}

	//heap sort
	void HeapSort(std::vector<int> v)
	{
		//ʹ�����ϵ����㷨��һ�������
		for (int i = 1; i < v.size(); i++)
		{
			AdjustUp(v, i, Great);
		}
		//ʹ�����µ����㷨����
		int size = v.size() - 1;
		for (size; size > 0;)
		{
			std::swap(v[size], v[0]);
			size--;
			AdjustDown(v, size, Great);
		}

		Print(v);
	}

	//merge sort
	void MergeSort(std::vector<int> v)
	{
		std::vector<int> tmp(v);
		m_MegrgSort(v,0,v.size()-1, tmp, Less);
		Print(v);
	}

	//bucket sort
	void BucketSort(std::vector<int> v)
	{
		std::vector<std::vector<int>> bucket(10);
		for (int i = 0; i < v.size(); i++)//��λ����ͬ�Ľ��з���
		{
			bucket[v[i] / 10].push_back(v[i]);
		}
		for (int i = 0; i < 10; i++)
		{
			if (!bucket[i].empty())
			{
				std::sort(bucket[i].begin(), bucket[i].end());
			}
		}
		int k = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < bucket[i].size(); j++)
			{
				v[k++] = bucket[i][j];
			}
		}

		Print(v);
	}

	//��������
	/*
	1�����ո�λ����
	2������ʮλ����
	3��.....
	*/
	void StdradixSort(std::vector<int> v)
	{
		int max_digit = get_max_number(v);//��ȡ���λ��
		std::vector<std::vector<int>> res(10);

		int digit = 1;

		while (digit <= max_digit)//����λ����
		{
			int k = 0;
			for (int i = 0; i < v.size(); i++)
			{
				res[getDigit(v[i], digit)].push_back(v[i]);
			}
			for (int i = 0; i < 10; i++)//��v�е�˳����array
			{
				int j = 0;
				while (j < res[i].size())
				{
					v[k] = res[i][j];
					j++;
					k++;
				}
				res[i].clear();
			}
			digit++;
		}

		Print(v);
	}

	//�ǵݹ����
	void NRqucikSort(std::vector<int> v)
	{
		std::stack<int> s;
		s.push(v.size() - 1);
		s.push(0);
		while (!s.empty())
		{
			int begin = s.top();
			s.pop();
			int end = s.top();
			s.pop();
			int mid = OnceQuick(v, begin, end);
			if (mid != -1)
			{
				s.push(mid - 1);
				s.push(begin);
				s.push(end);
				s.push(mid+1);
			}
		}

		Print(v);
	}

private:

	int getDigit(int number, int digit)//��ȡ����digitλ����(ÿһλ����)
	{
		int k = pow(10, digit - 1);
		return (number / k) % 10;
	}
	int get_max_number(std::vector<int> v)//��ȡ���λ
	{
		int max = v[0];
		for (int i = 0; i < v.size(); i++)//��ȡ���ֵ
		{
			if (v[i] > max)
			{
				max = v[i];
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

	//�鲢����
	void m_MegrgSort(std::vector<int> &v, int begin, int end, std::vector<int> &tmp, compare com)
	{
		if (end - begin <= 0)
		{
			return;
		}
		int mid = (begin + end) / 2;
		m_MegrgSort(v, begin, mid, tmp, com);
		m_MegrgSort(v, mid+1, end, tmp, com);
		int i = begin;
		int j = mid + 1;
		int k = begin;
		while (i <= mid && j <= end)
		{
			if (com(v[j], v[i]))
			{
				tmp[k++] = v[j++];
			}
			else
			{
				tmp[k++] = v[i++];
			}
		}
		while (i <= mid)
		{
			tmp[k++] = v[i++];
		}
		while (j <= end)
		{
			tmp[k++] = v[j++];
		}
		v = tmp;
	}

	//���ϵ����㷨
	void AdjustUp(std::vector<int> &v, int child, compare com)
	{
		int parent = (child - 1) / 2;
		while (parent >= 0)
		{
			if (com(v[child],v[parent]))
			{
				std::swap(v[child], v[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}

	//���µ����㷨
	void AdjustDown(std::vector<int> &v, int size, compare com)
	{
		int parent = 0;
		int child = 1;
		while (child <= size)
		{
			if (child + 1 <= size && com(v[child + 1], v[child]))
			{
				child++;
			}
			if (com(v[child], v[parent]))
			{
				std::swap(v[child], v[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}

	//����
	void modular(std::vector<int> &v, int left, int right)
	{
		int ret = OnceQuick(v, left, right);
		if (ret == -1) 
		{
			return;
		}
		modular(v, left, ret - 1);
		modular(v, ret + 1, right);
	}
	int OnceQuick(std::vector<int> &v, int left, int right)
	{
		//ʹ������ȡ�з������Ż�
		if (right <= left)
		{
			return -1;
		}
		while (right > left)
		{
			while (right > left && v[right] >= v[left])
			{
				right--;
			}
			std::swap(v[right], v[left]);
			while (right > left && v[left] <= v[right])
			{
				left++;
			}
			std::swap(v[right], v[left]);
		}
		return left;
	}

	//��ӡ
	void Print(std::vector<int> v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}
};