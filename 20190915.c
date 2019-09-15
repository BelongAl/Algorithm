#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef char DataType;

typedef struct Stack
{
  DataType *array;
  size_t capacity;
  size_t size;
}Stack;

void StackInit(Stack *ps)//初始化
{
  assert(ps);
  ps->array = (DataType*)malloc(sizeof(DataType)*3);
  if(NULL == ps->array)
  {
    assert(0);
    return;
  }
  ps->capacity = 3;
  ps->size = 0;
}

void StackCapacity(Stack *ps)//检查容量并扩容
{
  assert(ps);
  if(ps->capacity == ps->size)
  {
    ps->capacity *= 2;
    DataType *p = (DataType*)realloc(ps->array,(ps->capacity)*sizeof(DataType));
    if(NULL == p)
    {
      assert(0);
      return;
    }
    ps->array = p;
  }
}

void StackPushBack(Stack *ps, DataType data)//入栈
{
  assert(ps);
  StackCapacity(ps);
  ps->array[ps->size++] = data;
}

void StackPopBack(Stack *ps)//出栈
{
  assert(ps);
  ps->size--;
}

void StackShow(Stack *ps)//打印
{
  assert(ps);
  size_t count = 0;
  while(count < ps->size)
  {
    printf("%-3c",ps->array[count++]);
  }
  printf("\n");
}

DataType StackTop(Stack *ps)//获得栈顶
{
  return ps->array[(ps->size)-1];
}

void StackDestary(Stack *ps)//摧毁
{
  assert(ps);
  if(ps->array)
  {
    free(ps->array);
    ps->capacity = 0;
    ps->size = 0;
  }
}

int main()
{
  Stack p;
  StackInit(&p);
  DataType s[5] = "{(]}";
  int i = 0;
  while(i<4)
  {
    if(s[i] == '{' || s[i] == '(' || s[i] == '[' )
    {
      StackPushBack(&p, s[i]);
    }
    else 
    {
      if(p.size > 0)
      {
        DataType a = StackTop(&p);
        if(s[i] == ')' && a == '(')
        {}
        else if(s[i] == '}' && a == '{')
        {}
        else if(s[i] == ']' && a == '[')
        {}
        else 
        {
          printf("error\n");
          return 0;
        }
        StackPopBack(&p);
      }
    }
    i++;
  }
  if(p.size == 0)
  {
    printf("right\n");
    return 0;
  }
  printf("error\n");
  return 0;
}












