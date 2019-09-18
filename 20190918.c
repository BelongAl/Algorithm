#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

typedef int HDataType;

typedef struct Heap//定义
{
  HDataType *_array;
  int _size;
  int _capacity;
}Heap;

void Swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void AdjustDown(HDataType *array, int size, int parent )//一次获得小堆替换
{
  int child = parent*2+1;//定义左孩子（小孩子）
  while(child < size)
  {
    if(child+1 < size && array[child] > array[child+1])//找到较小子节点
    {
      child += 1;
    }
    if(array[child] < array[parent])
    {
      Swap(&array[child],&array[parent]);
      parent = child;
      child = parent*2 + 1;
    }
    else 
    {
      return;
    }
  }
}

void InitHeap(Heap *hp, HDataType *arr, HDataType size)//堆的初始化
{
  assert(hp);
  hp->_array = (HDataType*)malloc(sizeof(HDataType)*size);
  if(NULL == hp->_array)
  {
    assert(0);
    return ;
  }
  hp->_capacity = size;
  hp->_size = 0;
  while(size--)
  {
    hp->_array[hp->_size] = arr[hp->_size];
    hp->_size++;
  }
  size = hp->_size;
  int root = ((size-2)/2);
  while(root>=0)
  {
    AdjustDown(hp->_array, hp->_size, root);
    root--;
  }
}

void DestoryHeap(Heap *hp)//堆的销毁
{
  assert(hp);
  if(hp->_array)
  {
    free(hp->_array);
    hp->_capacity = 0;
    hp->_size = 0;
  }

}

void ShowHeap(Heap *hp)
{
  assert(hp);
  int size = hp->_size;
  int count = 0;
  while(size--)
  {
    printf("%-2d",hp->_array[count]);
    count++;
  }
  printf("\n");
}

int main()
{
  Heap hp;
  HDataType arr[] = {1,4,6,2,3,8,0,9,5,7};
  InitHeap(&hp, arr, sizeof(arr)/sizeof(arr[0]));
  ShowHeap(&hp);
  DestoryHeap(&hp);

  return 0;
}
