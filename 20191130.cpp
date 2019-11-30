#include<iostream>

using namespace std;

int Find(int *arr, int size, int key)
{
	int left = 0;
	int right = size - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[left] > arr[mid])
		{
			right = mid;
		}
		else if (arr[left] < arr[mid])
		{
			left = mid;
		}
		else
		{
			break;
		}
	}
	if (key <= arr[left] && key >= arr[0])
	{
		left = 0;
		right = right;
	}
	else
	{
		left = right;
		right = size;
	}
	while (left < right)
	{
		mid = (left + right) / 2;
		if (arr[mid] == key)
		{
			return mid;
		}
		else if (key > arr[mid])
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}
	return -1;
}

int main()
{
	int arr[] = { 6,7,8,1,2,3,4,5 };
	cout << "Found the subscript of this number is" << Find(arr,sizeof(arr)/sizeof(arr[0]),7) << endl;
	system("pause");
	return 0;
}