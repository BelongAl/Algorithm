#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int HDataType;
typedef int(*Compare) (HDataType, HDataType); 

int Less(HDataType left, HDataType right)//compare of little heap 
{
  return left<right;
}

int Great(HDataType left, HDataType right)//compare of bit heap 
{
  return left>right;
}

typedef struct Heap//Heap structure
{
  HDataType *_array;
  int _capacity;
  int _size;
  Compare _comp;
}Heap;

void InitHeap(Heap *hp,Compare comp)//Initalization of heap 
{
  assert(hp);
  hp->_array = (HDataType*)malloc(sizeof(HDataType)*3);
  hp->_capacity = 3;
  hp->_size = 0;
  hp->_comp = comp;
}


int Swap(HDataType *left, HDataType *right)
{
  int tmp = *left;
  *left = *right;
  *right = tmp; 
}

void CheckCapacity(Heap*hp)//Inspection capacity 
{
  assert(hp);
  if(hp->_capacity == hp->_size)
  {
    int newcapacity = 2*hp->_capacity;
    HDataType *arr = (HDataType*)realloc(hp->_array,sizeof(HDataType)*newcapacity);
    if(NULL == arr)
    {
      assert(0);
      return;
    }
    hp->_array = arr;
    hp->_capacity = newcapacity;
  }
}

void Adjustup(HDataType *array, int child, Compare comp)//Upword adujutment  
{
    int parent = (child-1)/2;
    while(child)
    {
      if(comp(array[child], array[parent]))
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

void InsertHeap(Heap*hp, HDataType data)//insert
{
  assert(hp);
  CheckCapacity(hp);//Inspection capacity
  hp->_array[hp->_size++] = data;
  Adjustup(hp->_array, hp->_size-1, hp->_comp);
}

void ShowHeap(Heap*hp)
{
  int count = 0;
  while(count < hp->_size)
  {
    printf("%-3d",hp->_array[count]);
    count++;
  }
}

int main()
{
  Heap hp;
  InitHeap(&hp, Great);//Initalization
  InsertHeap(&hp, 1);
  InsertHeap(&hp, 4);
  InsertHeap(&hp, 2);
  InsertHeap(&hp, 3);
  InsertHeap(&hp, 9);
  InsertHeap(&hp, 5);
  InsertHeap(&hp, 7);
  InsertHeap(&hp, 1);
  InsertHeap(&hp, 10);
  InsertHeap(&hp, 6);
  InsertHeap(&hp, 3);
  ShowHeap(&hp);
  return 0;
}






