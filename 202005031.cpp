#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int rob(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}
	vector<int> dp(nums.size() + 1, 0);
	dp[0] = 0;
	dp[1] = nums[0];
	for (int i = 2; i < dp.size(); i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
	}
	return dp[nums.size()];
}

int main()
{
	vector<int> num{ 2,7,9,3,1 };
	rob(num);
	return 0;
}

