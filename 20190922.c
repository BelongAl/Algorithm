#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int HDataType;
typedef struct Heap//构建
{
  HDataType *_array;
  int _size;
  int _capacity;
}Heap;

void Swap(HDataType *left, HDataType *right)//交换
{
  int tmp = *left;
  *left = *right;
  *right = tmp;
}

void AdjusttDownWard(HDataType *array, int size,int parent)//向下调整
{
  int child = parent*2 + 1;//标记左儿子节点
  while(child<size)
  {
    if(child+1 < size && array[child+1] <  array[child])//求出儿子节点中的较小节点
    {
      child++;
    }
    if(array[child] < array[parent])
    {
      Swap(&array[child],&array[parent]);
    }
    parent = child;
    child = parent*2+1;
  }
}


void HeapInit(Heap *hp ,HDataType *array, int size)//初始化并且把前五个元素放入堆中
{
  assert(hp);
  hp->_array = (HDataType*) malloc(sizeof(HDataType)*size);
  hp->_capacity = size;
  hp->_size = 0;
  while(hp->_size < size)
  {
    hp->_array[hp->_size] = array[hp->_size];
    hp->_size++;
  }
  int parent = 0;
  while(parent < size/2)
  {
    AdjusttDownWard(hp->_array,hp->_size,parent);
    parent++;
  }
}

void TopFive(Heap *hp, HDataType *arr, int size)//求数组中前大数字
{
  assert(hp);
  int count = hp->_size;
  while(count < size)
  {
    if(arr[count] > hp->_array[0])
    {
      Swap(&arr[count],&hp->_array[0]);
      AdjusttDownWard(hp->_array, hp->_size, 0);
    }
    count++;
  }
}

void ShowHeap(Heap *hp)
{
  assert(hp);
  int count = 0;
  printf("The top five largest numbers are: ");
  while(count < hp->_size)
  {
    printf("%-3d",hp->_array[count]);
    count++;
  }
  printf("\n");
}

int main()
{
  HDataType arr[] = {1,8,23,5,76,90,12,15,7,2,14,66,88,33,12,48,95,46};
  Heap hp;
  HeapInit(&hp, arr, 5);
  TopFive(&hp,arr,sizeof(arr)/sizeof(arr[0]));
  ShowHeap(&hp);
  return 0;
}






