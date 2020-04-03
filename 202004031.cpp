// write your code here cpp
#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
	static bool compare(vector<int> a, vector<int> b)
	{
		return a[0] < b[0];
	}
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> res;
		for (double n = 2; ((n*n) + n) <= 2 * sum; n++)
		{
			double x = ((2 * sum) - (n*n) + n) / (2 * n);
			int y = x;
			if (y == x)
			{
				vector<int> tmp;
				for (int i = 0; i < n; i++)
				{
					tmp.push_back(y);
					y++;
				}
				res.push_back(tmp);
			}
		}
		sort(res.begin(), res.end(), compare);
		return res;
	}
};


int main()
{


	Solution s;
	s.FindContinuousSequence(3);

	return 0;
}