#include"list.h"

void InitializationList(List *s)
{
	assert(s != NULL);
	s->arr = NULL;
	s->capicity = 0;
	s->size = 0;
}

void CapacityExpansionList(List *s)
{
	assert(s != NULL);
	if (s->size == s->capicity)
	{
		size_t size = ((s->capicity > 0) ? (2 * (s->capicity)) : 5);
		s->capicity = size;
	}
	s->arr = (int*)realloc(s->arr, (s->capicity * sizeof(int)));
}

void FrountPushInsert(List *s, int add)
{
	assert(s != NULL);
	ArbitrarilyInsertList(s,s->size+1,add);
}

void FrountDeleteList(List *s)
{
	assert(s != NULL);
	ArbitrarilyDeleteList(s, s->size);
}

void ShowList(List *s)
{
	assert(s != NULL);
	int i = 0;
	for (i = 0; i < s->size; i++)
	{
		printf("%d", s->arr[i]);
	}
	printf("\n");
}

void BackPushList(List *s, int add) 
{
	assert(s != NULL);
	ArbitrarilyInsertList(s, 1, add);
}

void BackDeleteList(List *s)
{
	assert(s != NULL);
	ArbitrarilyDeleteList(s, 1);
}

void ArbitrarilyInsertList(List *s, size_t num, int add)
{
	assert(s != NULL);
	CapacityExpansionList(s);
	size_t size = s->size;
	while (size >= num)
	{
		s->arr[size] = s->arr[size - 1];
		size--;
	}
	s->arr[size] = add;
	s->size++;
}

void ArbitrarilyDeleteList(List *s, size_t num)
{
	assert(s != NULL);
	if (num > 0)
	{
		num--;
		while (num < s->size)
		{
			s->arr[num] = s->arr[num + 1];
			num++;
		}
		s->size--;
	}
}

void BubbleSortList(List *s)
{
	assert(s != NULL);
	size_t size = s->size-1;
	int i = 0;
	int count = 0;
	while (size)
	{
		for (i = 0; i < size; i++)
		{
			if (s->arr[i + 1] < s->arr[i])
			{
				int tmp = s->arr[i + 1];
				s->arr[i + 1] = s->arr[i];
				s->arr[i] = tmp;
				count++;
			}
		}
		if (count == 0)
		{
			break;
		}
		size--;
	}
}

void BinarySearchList(List *s,int se)
{
	int left = 0;
	int right = (s->size) - 1;
	while (right >= left)
	{
		int mid = (left+right)/2;
		if (s->arr[mid] == se)
		{
			printf("Find the subscript is %d\n", mid);
			break;
		}
		else if (s->arr[mid] > se)
		{
			right = mid;
		}
		else if (s->arr[mid] < se)
		{
			left = mid;
		}
	}
}