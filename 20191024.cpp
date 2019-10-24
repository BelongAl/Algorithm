#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i)
		{
			if (nums[i] == 0 && i != nums.size() - 1)
			{
				return false;
			}
			else
			{
				i += nums[i];
			}
			if (i == nums.size() - 1)
			{
				return true;
			}
		}
		return false;
	}
};

int main()
{
	int arr[] = {0};
	vector<int> v(arr, arr + 5);
	Solution s;
	cout << s.canJump(v) << endl;
	system("pause");
	return 0;
}