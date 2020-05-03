#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	int minDifficulty(vector<int>& jobDifficulty, int d) {
		if (jobDifficulty.size() < d)
		{
			return -1;
		}
		vector<vector<int>> dp(d + 1, vector<int>(jobDifficulty.size() + 1, INT_MAX));

		int maxdif = 0;
		for (int i = 1; i <= jobDifficulty.size(); i++)//��ʼ��, ʱ��Ϊһ��Ĺ����Ѷ�
		{
			dp[1][i] = max(maxdif, jobDifficulty[i - 1]);
			maxdif = dp[1][i];
		}

		for (int i = 2; i <= d; i++)//��������
		{
			for (int j = i; j <= jobDifficulty.size(); j++)//ǰj������
			{
				int curdif = jobDifficulty[j - 1];//��ʾ��j���������Ѷ�
				for (int k = j; k >= i; k--)
				{
					curdif = max(curdif, jobDifficulty[k - 1]);
					dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + curdif);
				}
			}
		}
		return dp[d][jobDifficulty.size()];
	}
};

int main()
{
	Solution s;
	vector<int> v{ 6, 2, 8, 4, 7 };
	s.minDifficulty(v, 4);
	return 0;
}