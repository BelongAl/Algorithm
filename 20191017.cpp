#include<vector>
#include<iostream>
using namespace std;
//method1
/*class Solution {
public:
	int _max(vector<int>& arr, int *max, int left, int right)
	{
		if (right <= left)
		{
			return arr[left];
		}
		int mid = left / 2 + right / 2;
		int leftdata = _max(arr, max, left, mid);
		int rightdata = _max(arr, max, mid + 1, right);
		int a = 0;
		int amax = arr[left];
		int b = 0;
		int bmax = arr[left];
		mid = (left + right) / 2;
		while (left <= mid)
		{
			a += arr[mid];
			if (a > amax)
			{
				amax = a;
			}
			mid--;
		}
		mid = (left + right) / 2 + 1;
		while (mid <= right)
		{
			b += arr[mid];
			if (b > bmax)
			{
				bmax = b;
			}
			mid++;
		}
		int k = (amax + bmax);
		if (k < leftdata)
		{
			k = leftdata;
		}
		if (k < rightdata)
		{
			k = rightdata;
		}
		*max = k;
		return *max;
	}
	int FindGreatestSumOfSubArray(vector<int> array) {
		int max = array[0];
		_max(array, &max, 0, array.size() - 1);
		return max;
	}
};*/

//method 2
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int max = array[0];
		int count = 0;
		for (auto &i : array)
		{
			if (i < count)
			{
				count = i;
			}
		}
		for (int i = 1; i < array.size(); i++)
		{
			if (count < max)
			{
				count = max;
			}
			if (max + array[i] > array[i])
			{
				max += array[i];
			}
			else
			{
				max = array[i];
			}
		}
		if (count < max)
		{
			count = max;
		}
		return count;
	}
};

int main()
{
	int arr[] = {-2,-8,-1,-5,-9};
	vector<int> brr(arr,arr+5);
	Solution s;
	cout << s.FindGreatestSumOfSubArray(brr) << endl;;
	system("pause");
	return 0;
}