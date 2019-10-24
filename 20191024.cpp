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
		if (nums[count] > 0)
		{
			ptr[count--] = true;
		}
		else
		{
			ptr[count--] = false;
		}
		for (int i = count; i >= 0; i--)
		{
			int tmp = nums[i];
			if ((i + tmp) >= nums.size() - 1)
			{
				ptr[i] = true;
			}
			else
			{
				int j = 1;
				for (j; j <= tmp; j++)
				{
					if (ptr[i + j] == true)
					{
						ptr[i] = true;
						break;
					}
				}
				if (j > tmp)
				{
					ptr[i] = false;
				}
			}
		}
		return ptr[0];
	}
};
int main()
{
	int arr[] = { 2, 3, 1, 0, 4 };
	vector<int> v(arr, arr + 5);
	Solution s;
	cout << s.canJump(v) << endl;
	system("pause");
	return 0;
}