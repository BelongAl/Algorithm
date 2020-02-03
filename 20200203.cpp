#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
	int Find(vector<int>& nums, int target, int left)
	{
		int right = nums.size() - 1;
		while (right >= left)
		{
			int mid = (right + left) / 2;
			if (nums[mid] > target)
			{
				right = mid - 1;
			}
			else if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				return mid;
			}
		}
		return -1;
	}
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> v;
		vector<int> tmp(nums);
		sort(nums.begin(), nums.end());//≈≈–Ú
		for (int i = 0; i < nums.size(); i++)
		{
			int left = nums[i];
			int right = target - left;
			int ret = Find(nums, right, i + 1);
			if (ret >= 0)
			{
				int k = 0;
				int j = 0;
				for (; j < tmp.size(); j++)
				{
					if (tmp[j] == nums[i])
					{
						v.push_back(j);
						break;
					}
				}
				for (; k < tmp.size(); k++)
				{
					if (tmp[k] == nums[ret] && j != k)
					{
						v.push_back(k);
						break;
					}
				}
				return v;
			}
		}
		return v;
	}
};
int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(4);
	v.push_back(3);
	v.push_back(0);

	Solution s;
	s.twoSum(v, 0);

	system("pause");
	return 0;
}