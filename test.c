#include<stdio.h>
int hanmingDistance(int x ,int y)
{
  int count = 0;
  while(x != 0 || y != 0)
  {
    if((x&1) != (y&1))
    {
      count++;
    }
    x = x>>1;
    y = y>>1;
  }
  return count;
}
int main()
{
  int ret = hanmingDistance(1,4);
  printf("%d\n",ret);
  return 0;
}
