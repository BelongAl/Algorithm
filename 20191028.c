#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * addBinary(char * a, char * b) {
	int sizea = strlen(a);
	int sizeb = strlen(b);
	int size = (sizea > sizeb ? sizea : sizeb) + 1;
	char *arr = (char*)calloc(size+1, sizeof(char));
	int k = 0;
	int i = sizea - 1;
	int j = sizeb - 1;
	char tmp;
	while (i >= 0 && j >= 0)
	{
		tmp = (a[i] - '0') + (b[j] - '0');
		arr[k] = tmp + '0';
		k++;
		j--;
		i--;
	}
	while (i >= 0)
	{
		arr[k] = a[i];
		k++;
		i--;
	}
	while (j >= 0)
	{
		arr[k] = b[j];
		k++;
		j--;
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] == '3' && i !=  k-1)
		{
			tmp = ('1' - '0') + (arr[i + 1] - '0');
			arr[i] = '1';
			arr[i + 1] = tmp + '0';
		}
		else if (arr[i] == '2' && i != k-1)
		{
			tmp = ('1' - '0') + arr[i + 1] - '0';
			arr[i] = '0';
			arr[i + 1] = tmp + '0';
		}
		if (i == k - 1)
		{
			if (arr[i] == '3')
			{
				arr[i + 1] = '1';
				arr[i] = '1';
				k++;
			}
			else if (arr[i] == '2')
			{
				arr[i + 1] = '1';
				arr[i] = '0';
				k++;
			}
		}
	}
	for (i = 0, j = k - 1; i < j; i++, j--)
	{
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}

	return arr;
}


int main() 
{
	char *a = "1";
	char *b = "11";
	printf("%s\n", addBinary(a, b));
	system("pause");
	return 0;
}