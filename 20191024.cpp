#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() < 2)
		{
			return true;
		}
		int count = nums.size() - 1;
		bool*ptr = new bool[count--];
		int t = nums.size() - 1;
		if (nums[count] > 0)
		{
			ptr[count] = true;
			t = count--;
		}
		else
		{
			ptr[count--] = false;
		}
		for (int i = count; i >= 0; i--)
		{
			int tmp = nums[i];
			if ((i + tmp) >= t)
			{
				ptr[i] = true;
				t = i;
			}
			else
			{
				ptr[i] = false;
			}
		}
		return ptr[0];
	}
};
int main()
{
	int arr[] = { 2, 0, 0 };
	vector<int> v(arr, arr + 3);
	Solution s;
	cout << s.canJump(v) << endl;
	system("pause");
	return 0;
}