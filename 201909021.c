#include<stdio.h>

void Conversion(unsigned int n , char *str)
{
  int i = 0;
  while(n > 0)
  {
    if(n%16 < 10 )
    {
      str[i] = (n%16) + '0';
    }
    else 
    {
      str[i] = (n%16) + 87;
    }
    n = n>>4;
    i++;
  }
  str[i] = '\0';
  int j = i-1;
  i = 0;
  while(j > i)
  {
    str[i] ^= str[j];
    str[j] ^= str[i];
    str[i++] ^= str[j--];
  }
}
char *toHex(int num)
{
    char *s = (char*)malloc(9);
    if(num == 0)
    {
      s[0] == '0';
      s[1] == '\0';
    }
    else if(num > 0)
    {
      Conversion(num , s);  
    }
    else if(num < 0)
    {
      Conversion((unsigned int) num, s);
    }
    return s;
}
int main()
{
  int k = 0;
  printf("please import k=");
  scanf("%d",&k);
  char *str = toHex(k);
  printf("%s\n",str);
  return 0;
}
