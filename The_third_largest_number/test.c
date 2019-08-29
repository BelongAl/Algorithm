#include<stdio.h>

int Third(int *nums,int numsSize)
{
  int i = 0;
  int min = nums[0];
  while(i < numsSize)//find the smallest number.
  {
    if(min > nums[i])
    {
      min = nums[i];
    }
    i++;
  }
  i = 0;
  int a = min, b = min, c = min; 
  while(i < numsSize)//find the maximum number.
  {
    if(nums[i] >= a)
    {
      a = nums[i];
    }
    i++;
  }
  i = 0;
  while(i < numsSize)//Find the second largest number
  {
    if(nums[i] >= b && nums[i] < a)
    {
      b = nums[i];
    }
    i++;
  }
  i = 0;
  while(i < numsSize)//Find the thired largedt number
  {
    if(nums[i] >= c && nums[i] < b)
    {
      c = nums[i];
    }
    i++;
  }
  if(a != b && a != c && b != c)
  {
    return c;
  }
  else 
  {
     return a;
  }
}

int main()
{
  int arr[] = {2,2,3,1,4,4,5};
  int ret = Third(arr,sizeof(arr)/sizeof(arr[0]));
  printf("%d\n",ret);
  return 0;
}
