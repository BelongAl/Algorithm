#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int backPackII(int m, vector<int> &A, vector<int> &V) 
	{
		int num = A.size();
		vector<vector<int>> max_value(num + 1, vector<int>(m+1, 0));
		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (A[i - 1] <= j)
				{
					max_value[i][j] = max(max_value[i - 1][j], max_value[i - 1][j - A[i - 1]] + V[i - 1]);
				}
				else
				{
					max_value[i][j] = max_value[i - 1][j];
				}
			}
		}
		return max_value[num][m];
	}
};

int main()
{
	return 0;
}