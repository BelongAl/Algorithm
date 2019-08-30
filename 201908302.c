#include<stdio.h>
#include<string.h>

char * longestCommonPrefix(char **strs , int strsSize)
{
  if(strs == NULL || strsSize == 0)
  {
    return " ";
  }
  int i = 0;
  int j = 0;
  char *str  = (char*)calloc(128,sizeof(char));
  while(1)
  {
    i = 0;
    while(i < strsSize - 1)
    {
      if(strlen(strs[i]) == 0)
      {
        return " ";
      }
      if(strs[i][j] == '\0')
      {
        return str;
      }
      if(strs[i][j] != strs[i+1][j])
      {
        return str;
      }
      i++;
    }
    str[j] = strs[0][j];
    j++;
  }
  return str;
}

int main()
{
  char *str[] = {"flower","flow","flight"};
  char *arr = longestCommonPrefix(str,sizeof(str)/sizeof(str[2]));
  printf("%s\n",arr);
  return 0;
}
