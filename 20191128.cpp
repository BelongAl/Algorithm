#include<iostream>

using namespace std;

int total = 0;

void Swap(int &left, int &right)
{
	int tmp = left;
	left = right;
	right = tmp;
}

void Print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	total++;
	cout << endl;
}

void Run(int *arr, int size, int n)
{
	if (size - 1 == n)
	{
		Print(arr,size);
		return;
	}
	for (int i = n; i < size; i++)
	{
		swap(arr[n], arr[i]);
		Run(arr, size, n+1);
		swap(arr[n], arr[i]);
	}
}

int main()
{
	int array[3] = { 1,2,3 };
	Run(array,sizeof(array)/sizeof(array[0]),0);
	system("pause");
	return 0;
}
