#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int HDataType;
typedef int(*pCom) (HDataType , HDataType);

int Less(HDataType left, HDataType right)
{
  return left<right;
}
int Great(HDataType left, HDataType right)
{
  return left>right;
}

typedef struct Heap
{
  HDataType * _array;
  int _capacity;
  int _size;
  pCom compare;
}Heap;

void InitHeap(Heap *hp,pCom compare)
{
  assert(hp);
  hp->_array = (HDataType*)malloc(sizeof(HDataType)*3);
  hp->_capacity = 3;
  hp->_size = 0;
  hp->compare = compare;

}

void Swap(HDataType *left, HDataType *right)
{
  HDataType tmp = *left;
  *left = *right;
  *right = tmp;
}

void AdjustDownword(HDataType *array, HDataType parent, pCom compare,int count)
{
  HDataType child = parent*2+1; 
  while (child < count)
  {
    if (child + 1 < count && compare(array[child+1],array[child]))
    {
      child += 1;             
    }
    if (compare(array[child], array[parent]))
    {
      Swap(&array[child], &array[parent]);
      parent = child;
      child = parent * 2 + 1;
    }
    else
    {
      return;
    }
                  
  }
}

void AdjustUpword(HDataType *array, HDataType child, pCom compare)
{
  HDataType parent = (child-1)/2;
  while(child)
  {
    if(compare(array[child], array[parent]))
    {
      Swap(&array[child], &array[parent]);
      child = parent;
      parent = (child-1)/2;
    }
    else 
    {
      return;
    }
  }
}

void CheckCapacity(Heap *hp)
{
  assert(hp);
  if(hp->_capacity == hp->_size)
  {
    int newcapacity = 2*hp->_capacity;
    HDataType *arr = realloc(hp->_array, newcapacity*sizeof(HDataType));
    if(NULL != arr)
    {
      hp->_array = arr;
      hp->_capacity = newcapacity;
    }
  }
}

void InsertHeap(Heap *hp, HDataType data)
{
  assert(hp);
  CheckCapacity(hp);
  hp->_array[hp->_size++] = data;
  AdjustUpword(hp->_array,hp->_size-1,hp->compare);
}

void HeapShow(Heap *hp)
{
  assert(hp);
  int count = 0;
  while(count < hp->_size)
  {
    printf("%d",hp->_array[count]);
    count++;
  }
  printf("\n");
}

void SortHeap(Heap *hp)
{
  assert(hp);
  int big = hp->_size - 1;
  while(big)
  {
    Swap(&hp->_array[0], &hp->_array[big]);
    AdjustDownword(hp->_array, 0, Great,big);
    big--;
  }
}

int main()
{
  Heap hp;
  InitHeap(&hp,Great);
  HDataType arr[] = {1,5,2,6,8,3,4,9,0,7};
  int k = 0;
  while(k < (sizeof(arr)/sizeof(arr[0])))
  {
    InsertHeap(&hp, arr[k++]);
  }
  HeapShow(&hp);
  SortHeap(&hp);
  HeapShow(&hp);
  return 0;
}























