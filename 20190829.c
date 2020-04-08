#include<stdio.h> 

int Find (char *arr)
{
  char *p = arr;
  char *q = arr+1;
  int count = 0;
  int k = 1;
  while(*q != '\0')
  {
    if(*p != *q)
    {
      p = p-count;
      count = 0;
      q++;
      k++;
    }
    else 
    {
      p++;
      q++;
      count++;
    }
  }
  if(k <= count)
  {
    return 1;
  }
  else 
  return 0;
}

int main()
{
  char *str = "abcdeabcde";
  int ret = Find(str);
  printf("%d\n",ret);
  return 0;
  
}
