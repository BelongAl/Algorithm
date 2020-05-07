#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	int cost(string& s, int l, int r) //表示把字符串变成回文串所需要的最少步骤

	{
		int ret = 0;
		for (int i = l, j = r; i < j; ++i, --j) 
		{
			if (s[i] != s[j]) 
			{
				++ret;
			}
		}
		return ret;
	}

	int palindromePartition(string& s, int k) 
	{
		int n = s.size();
		vector<vector<int>> f(n + 1, vector<int>(k + 1, INT_MAX));
		f[0][0] = 0;
		for (int i = 1; i <= n; ++i)//表示前i个字符
		{
			for (int j = 1; j <= min(k, i); ++j) //表示分解成几部
			{
				if (j == 1) //分割成一块
				{
					f[i][j] = cost(s, 0, i - 1);
				}
				else //转移方程
				{
					for (int i0 = j - 1; i0 < i; ++i0) //一一例举，找出分割较少的，j-1表示最少分割成j个需要的最少字符数，然后一一列举。
					{
						f[i][j] = min(f[i][j], f[i0][j - 1] + cost(s, i0, i - 1));//f[i][j]表示把s的前i个字符分割成j个回文串需要的最少修改步骤
					}
				}
			}
		}

		return f[n][k];
	}
};


int main()
{
	string s("daabbc");
	Solution so;
	so.palindromePartition(s, 3);
	return 0;
}