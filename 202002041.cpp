#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
	int find(vector<int> v, int &left, int &right, int target)
	{
		while (right >= left)
		{
			int mid = (right + left) / 2;
			if (v[mid] > target)
			{
				right = mid - 1;
			}
			else if (v[mid] < target)
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
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> v(2, -1);
		int left = 0;
		int right = nums.size() - 1;

		int r = find(nums, left, right, target);
		if (r == -1)
		{
			return v;
		}

		//Find the left border
		while (1)
		{
			int ret = find(nums, left, right, target);
			if (ret == -1 || left == right)
			{
				v[0] = right;
				break;
			}
			if (right - left == 1)
			{
				if (nums[left] == target)
				{
					v[0] = left;
					break;
				}
				else
				{
					v[0] = right;
					break;
				}
			}
			right = ret;
		}

		left = 0;
		right = nums.size()-1;
		//Find the right border
		while (1)
		{
			int ret = find(nums, left, right, target);
			if (ret == -1 || left == right)
			{
				v[1] = left;
				break;
			}
			if (right - left == 1)
			{
				if (nums[right] == target)
				{
					v[1] = right;
					break;
				}
				else
				{
					v[1] = left;
					break;
				}
			}
			left = ret;
		}
		return v;
	}
};


int main()
{

	vector<int> v;
	v.push_back(2);
	v.push_back(2);

	Solution s;
	s.searchRange(v,2);

	system("pause");
	return 0;
}