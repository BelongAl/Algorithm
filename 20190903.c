#include<stdio.h>
#include<stdlib.h>

bool containsNearbyDuplicate(int* nums, int numsSize, int k)
{
  int i = 0;
  int j = 0;
  for(i=0 ;i<numsSize; i++)
  {
    for(j=i+1; j<numsSize; j++)
    {
      if(nums[i] == nums[j])
      {
        if(j>i && (j-i)<k)
        {
          return true;
        }
        else if(i>=j && (i-j)<=k)
        {
          return true;
        }
      }
    }
  }
  return false;
}
int main()
{
  int arr[] = {1,2,3,1,4};
  containsNearbyDuplicate(arr,sizeof(arr)/sizeof(arr[0]),3);
  return 0;
}
