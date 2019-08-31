#include<stdio.h>
#include<string.h>

int lengthoflastword(char *s)
{
  char *p = s;
  char *q = s;
  while(*p != '\0')
  {
    if(*p == ' ' && *(p+1) != ' ' && *(p+1) != '\0')
    {
      q = p;
      q++;
    }
    p++;
  }
  int count = 0;
  while(*q != '\0' && *q != ' ')
  {
    count++;
    q++;
  }
  return count;
}
int main()
{
  char *str = "i am wang rui";
  printf("%d\n",lengthoflastword(str));
  return 0;
}
