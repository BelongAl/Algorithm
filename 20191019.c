#include<iostream>
#include<vector>

using namespace std;

int FindNumber(int *arr, int right, int k)
{
	int left = 0;
	int mid = (left + right) / 2;
	while(left < right)
	{
		if (arr[mid] == k)
		{
			return mid;
		}
		if (arr[mid] > arr[left])
		{
			if (k > arr[mid])
			{
				left = mid;
			}
			else
			{
				if (k >= arr[left])
				{
					right = mid;
				}
				else
				{
					left = mid;
				}
			}
		}
		else
		{
			if (k < arr[mid])
			{
				right = mid;
			}
			else
			{
				if (k >= arr[left])
				{
					right = mid;
				}
				else
				{
					left = mid;
				}
			}
		}
		mid = (left + right) / 2;
	}
}

int main()
{
	int arr[] = {19,23,45,76,1,4,12,16 };
	cout << arr[FindNumber(arr, sizeof(arr) / sizeof(arr[0]), 23)] << endl;;
	system("pause");
	return 0;
}