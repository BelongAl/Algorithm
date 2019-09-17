#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SDataType;


typedef struct Stack//栈
{
  SDataType *arr;
  size_t capacity;
  size_t size;
}Stack;

void StackInit(Stack *ps)//Initialization of stacks
{
  assert(ps);
  ps->arr = (SDataType*)malloc(sizeof(SDataType)*3);
  if(NULL == ps->arr)
  {
    assert(0);
    return;
  }
  ps->capacity = 0;
  ps->size = 0;
}

void StackCapacity(Stack *ps)//check capacity and expand capacity 
{
  assert(ps);
  if(ps->size == ps->capacity)
  {
    ps->capacity *= 2;
    SDataType *p = (SDataType*)realloc(ps->arr,ps->capacity); 
    if(NULL != p)
    {
      ps->arr = p;
    }
  }
}

void StackPush(Stack *ps, SDataType data)//Access Stack 
{
  assert(ps);
  StackCapacity(ps);//Check capacity and expand capacity 
  ps->arr[ps->size++] = data;
}

void StackPop(Stack *ps)//Stack out
{
  assert(ps);
  ps->size--;
}

SDataType StackTop(Stack *ps)//Get the top element of the stack 
{
  assert(ps);
  return ps->arr[ps->size-1];
}

void StackDestroy(Stack *ps)//Destroy stack 
{
  assert(ps);
  if(ps->arr)
  {
    ps->capacity = 0;;
    ps->size = 0;
    free(ps->arr);
  }
}

void StackShow(Stack *ps)//printing
{
  assert(ps);
  size_t count = 0;
  while(count < (ps->size))
  {
    printf("%-3d",ps->arr[count]);
    count++;
  }
  printf("\n");
}

typedef struct Queue//queue 
{
  Stack q1;
  Stack q2;
}Queue;

void QueueInit(Queue *q)//Initialization Queue 
{
  assert(q);
  StackInit(&q->q1);
  StackInit(&q->q2);
}

void QueuePush(Queue *q, SDataType x)//Access Queue 
{
  assert(q);
  StackPush(&q->q1, x);
}


void QueuePop(Queue *q)//Queue out 
{
  assert(q);
  if(0 == q->q2.size)
  {
    int count = q->q1.size; 
    while(count > 0)
    {
      StackPush(&q->q2, StackTop(&q->q1));
      StackPop(&q->q1);
      count--;
    }
  }
  StackPop(&q->q2);
}

SDataType QueueTop(Queue *q)//get top element of Queue 
{
  assert(q);
  if(0 == q->q2.size)
  {
    int count = q->q1.size; 
    while(count > 0)
    {
      StackPush(&q->q2, StackTop(&q->q1));
      StackPop(&q->q1);
      count--;
    }
  }
  return StackTop(&q->q2);
}

void QueueShow(Queue *q)
{
  assert(q);
  if(q->q2.size > 0)
  {
    StackShow(&q->q2);
  }
  if(q->q1.size > 0)
  {
    StackShow(&q->q1);
  }
}

int main()
{
  Queue q;
  QueueInit(&q);
  QueuePush(&q,1);
  QueuePush(&q,2);
  QueuePush(&q,3);
  QueueShow(&q);
  printf("The head element of queue is %d\n",QueueTop(&q));
  QueuePop(&q);
  QueuePush(&q,4);
  QueueShow(&q);
}




