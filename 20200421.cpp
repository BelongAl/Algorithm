#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> res;
		if (num.size() < size)
		{
			return res;
		}
		for (int i = 0; i < num.size() - size + 1; i++)
		{
			int max = num[i];
			for (int j = i + 1;  j < i + size; j++)
			{
				if (max < num[j])
				{
					max = num[j];
				}
			}
			res.push_back(max);
		}
		return res;
	}
};

int main()
{
	vector<int> v = { 2,3,4,2,6,2,5,1 };
	Solution s;
	v = s.maxInWindows(v, 3);
	return 0;
}