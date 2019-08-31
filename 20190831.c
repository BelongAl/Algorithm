#include<stdio.h>
#include<stdlib.h>

char* Helpcount(char *s, int n)
{
  if(n == 1)
    return s;
  else 
  {
    int count;
    char ch[10000];
    char *p = ch;
    while(*s != '\0')
    {
      count = 1;
      while(*s == *(s+1))
      {
        count++;
        s++;
      }
      *p++ = (char)(count + '0');
      *p++ = *s++;
    }
    return Helpcount(ch,n-1);
  }
}
char *countAandSay(int n)
{
  return Helpcount("1",n);
}

int main()
{
  printf("%s\n",countAandSay(7));
  return 0;
}
