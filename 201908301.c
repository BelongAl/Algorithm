#include<stdio.h>

int reverse(int x)
{
  int k = 0;
  while(x)
  {
    k = k*10 + x%10;
    x = x/10;
  }
  if(k > 2147483648 || k < -2147483648)
  {
    return 0;
  }
  return k;
}
int main()
{
  printf("%d\n",reverse(1234));
  return 0;
}
