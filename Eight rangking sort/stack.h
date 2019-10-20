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
	int _size_;//表示栈中的有效个数 代表栈顶
}Stack;

void StackInit(Stack *ps)//初始化
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

void CheckCapacity(Stack *ps)//检查容量并扩容
{
	assert(ps);
	if (((ps->_capacity) - (ps->_size_)) <= 2)
	{
		SDataType* p = NULL;
		ps->_capacity *= 2;
		p = (SDataType*)realloc(ps->_array, sizeof(SDataType)*(ps->_capacity));//realloc如果开辟空间失败会返回空，所以不能直接扩容
		if (NULL == p)
		{
			assert(0);
			return;
		}
		ps->_array = p;
	}
}

void StackPush(Stack *ps, SDataType data)//入栈
{
	assert(ps);
	CheckCapacity(ps);
	ps->_array[ps->_size_++] = data;
}

void StackPop(Stack *ps)//出栈
{
	assert(ps);
	if (StackEmpty(ps))
	{
		return;
	}
	ps->_size_--;
}

SDataType StackTop(Stack *ps)//获取栈顶的元素
{
	assert(ps);
	return ps->_array[ps->_size_ - 1];
}

int StackSize(Stack *ps)//大小
{
	assert(ps);
	return ps->_size_;
}

int StackEmpty(Stack *ps)//判空
{
	assert(ps);
	return 0 == ps->_size_;
}

void StackDestroy(Stack *ps)//销毁
{
	assert(ps);
	if (ps->_array)
	{
		ps->_capacity = 0;
		ps->_size_ = 0;
		free(ps->_array);
	}
}

void StackShow(Stack* ps)//打印
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
