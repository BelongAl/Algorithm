#include<stdio.h>

int hammingDistance(int x, int y)
{
  int count = 0;
  int z = x^y;
  while(z)
  {
    if(z&1 == 1)
      count ++;
    z = z>>1;
                                    
  }
  return count;
}

int main()
{
   printf("%d\n",hammingDistance(4,1));
   return 0;
}
