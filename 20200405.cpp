#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n <= 0 || m <= 0)
		{
			return -1;
		}
		vector<int> child(n);
		for (int i = 0; i < n; i++)
		{
			child[i] = i;
		}
		int num = 0;
		while (n > 1)
		{
			int tmp = m % n - 1;
			if (tmp == -1)
			{
				tmp = n - 1;
			}
			tmp += num;
			tmp %= n;
			child.erase(child.begin()+tmp , child.begin() + tmp + 1);
			num = tmp;
			n--;
		}
		return child[0];
	}
};

int main()
{
	Solution s;
	s.LastRemaining_Solution(5, 3);
	return 0;
}