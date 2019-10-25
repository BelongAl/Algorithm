#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int i = 0;
		int k = 0;
		for (int j = 0; j < intervals.size() - 1; j++)
		{
			if (intervals[j][1] >= intervals[j + 1][0])
			{
				intervals[j + 1][0] = intervals[j][0];
				intervals[i][0] = intervals[j + 1][0];
				intervals[i][1] = intervals[j + 1][1];
				k = 1;
				j++;
			}
			else
			{
				if (k == 1)
				{
					j++;
					i++;
				}
				intervals[i][0] = intervals[j][0];
				intervals[i][1] = intervals[j][1];
				if (k == 0)
				{
					j++;
					i++;
				}
				k = 0;

			}
		}
		intervals.resize(i);
		return intervals;
	}
};