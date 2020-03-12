#include<iostream>

using namespace std;

bool ReplaceBlank(char *std)
{
	if (std == nullptr)
	{
		return false;
	}
	char *p = std;
	int countblack = 0;
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			countblack++;
		}
		p++;
	}
	countblack *= 2;
	while (countblack)
	{
		*(p + countblack) = *p;
		if (*p == ' ')
		{
			*p++ = '%';
			*p++ = '2';
			*p++ = '0';
			countblack -= 2;
		}
		p--;
	}

}

int main()
{
	char *str = new char[100];
	char std[] = "I'm so happy";
	for (int i = 0; i < sizeof(std); i++)
	{
		str[i] = std[i];
	}
	ReplaceBlank(str);
	cout << str << endl;
	system("pause");
	return 0;
}