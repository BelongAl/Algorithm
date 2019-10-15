#include<stdio.h>
#include<stdlib.h>

/* method 1
int lengthOfLongestSubstring(char * s) {
	int i = 0;
	int j = 0;
	int count = 0;
	int max = 0;
	int  index = 0;;
	int ret = 0;
	for (i; i < strlen(s); i++)
	{
		index = 0;
		for (j = ret; j < i; j++)
		{
			if (s[j] == s[i])
			{
				index = 1;
				break;
			}
		}
		if (index == 1)
		{
			count = 0;
			ret = j+1;
			i = j;
		}
		else
		{
			count++;
			if (count > max)
			{
				max = count;
			}
		}
	}
	return max;
}*/

//method 2
int lengthOfLongestSubstring(char * s) {
	if (NULL == s || strlen(s) == 0)
	{
		return 0;
	}
	char *arr = (int*)malloc(512 * sizeof(int));
	int i = 0;
	arr[s[i]] = s[i];
	arr[256 + s[i++]] = i;
	int count = 1;
	int max = 1;
	while (s[i])
	{
		if (s[i] == arr[s[i]] && (arr[256 + s[i]] + 1) < strlen(s))
		{
			i = arr[256 + s[i]] + 1;
			char *brr = (int*)malloc(512 * sizeof(int));
			free(arr);
			arr = brr;
			count = 0;
		}
		else if (s[i] != arr[s[i]])
		{
			arr[s[i]] = s[i];
			arr[256 + s[i++]] = i;
			count++;
		}
		if (max < count)
		{
			max = count;
		}
	}
	return max;
}

int main()
{
	char *s = "abb";
	printf("%d\n",lengthOfLongestSubstring(s));
	system("pause");
	return 0;
}