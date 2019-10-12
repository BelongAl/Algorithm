#include<iostream>
#include<vector>

using namespace std;

//Method 1 
/*
int singleNumber(vector<int>& nums) {
	int sum = 0, tmp = 0;
	for (auto &i : nums)
	{
		sum = (sum ^ i) & ~tmp;
		tmp = (tmp ^ i) & ~sum;
	}
	return sum;
}
*/

//Method 2  
int singleNumber(vector<int> &nums)
{
	int sum = 0, count = 0;
	int i;
	for (i = 0; i < 32; i++)
	{
		for (auto j : nums)
		{
			count += j >> i & 1u;
		}
		if (count % 3)
		{
			sum  |= 1u << i;
		}
		count = 0;
	}
	return sum;
}

int main()
{
	vector<int> nums = { 2,2,3,8,5,2,3,5,5,3};
	cout << singleNumber(nums) << endl;
	system("pause");
	return 0;
}