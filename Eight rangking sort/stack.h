#ifndef _STACK_H_
#define _STACK_H_

#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SDataType;

typedef struct Stack
{
	SDataType *_array;
	int _capacity;
	int _size_;//��ʾջ�е���Ч���� ����ջ��
}Stack;

void StackInit(Stack *ps)//��ʼ��
{
	assert(ps);
	ps->_array = (SDataType*)malloc(sizeof(SDataType) * 3);
	if (NULL == ps->_capacity)
	{
		assert(0);
		return;
	}
	ps->_capacity = 3;
	ps->_size_ = 0;
}

void CheckCapacity(Stack *ps)//�������������
{
	assert(ps);
	if (((ps->_capacity) - (ps->_size_)) <= 2)
	{
		SDataType* p = NULL;
		ps->_capacity *= 2;
		p = (SDataType*)realloc(ps->_array, sizeof(SDataType)*(ps->_capacity));//realloc������ٿռ�ʧ�ܻ᷵�ؿգ����Բ���ֱ������
		if (NULL == p)
		{
			assert(0);
			return;
		}
		ps->_array = p;
	}
}

void StackPush(Stack *ps, SDataType data)//��ջ
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size_++] = data;
}

void StackPop(Stack *ps)//��ջ
{
	assert(ps);
	if (StackEmpty(ps))
	{
		return;
	}
	ps->_size_--;
}

SDataType StackTop(Stack *ps)//��ȡջ����Ԫ��
{
	assert(ps);
	return ps->_array[ps->_size_ - 1];
}

int StackSize(Stack *ps)//��С
{
	assert(ps);
	return ps->_size_;
}

int StackEmpty(Stack *ps)//�п�
{
	assert(ps);
	return 0 == ps->_size_;
}

void StackDestroy(Stack *ps)//����
{
	assert(ps);
	if (ps->_array)
	{
		ps->_capacity = 0;
		ps->_size_ = 0;
		free(ps->_array);
	}
}

void StackShow(Stack* ps)//��ӡ
{
	assert(ps);
	int tmp = 0;
	while (tmp < ps->_size_)
	{
		printf("%-3d", ps->_array[tmp]);
		tmp++;
	}
	printf("\n");
}

#endif // !_STACK_H_
