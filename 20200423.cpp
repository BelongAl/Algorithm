#include<iostream>
#include<algorithm>

using namespace std;

//贪心算法
class Solution1 {
public:
	int cutRope(int number) {
		int ret = 0;//表示分为一段的时候
		int divided = 2;
		while (1)
		{
			int n = number / divided;//表示每一段基础长度
			int k = number % divided;//表示在基础上需要加上的
			int tmp;
			if (k > 0)
			{
				tmp = pow(n, (divided - k)) * pow(n + 1, k);
			}
			else
			{
				tmp = pow(n, (divided - k));
			}
			if (tmp > ret)
			{
				ret = tmp;
			}
			else
			{
				return ret;
			}
			divided++;
		}
	}
};

//动态规划
class Solution {
public:
	int cutRope(int number) {
		if (number == 2)
		{
			return 1;
		}
		if (number == 3)
		{
			return 2;
		}
		int x = number / 3;
		int y = number % 3;
		if (y == 0)
		{
			return pow(3, x);
		}
		else if (y == 1)
		{
			return pow(3, x - 1) * 4;
		}
		else if (y == 2)
		{
			return pow(3, x) * 2;
		}
	}
};

int main()
{
	Solution s;
	int ret = s.cutRope(5);
	return 0;
}