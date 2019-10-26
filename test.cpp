#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	bool coin(vector<int> &left, vector<int> &right)
	{
		if (left[0] > right[1])
		{
			return false;
		}
		else if (left[1] < right[0])
		{
			return false;
		}
		return true;
	}

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.size() < 2)
		{
			return intervals;
		}
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> arr(intervals.size(), vector<int>(2, 0));
		int j = 0;
		int i = 0;
		int judje = 0;
		while (j < intervals.size() - 1)
		{
			if (!coin(intervals[j], intervals[j + 1]))
			{
				if (judje == 1)
				{
					i++;
				}
				else
				{
					arr[i][0] = intervals[j][0];
					arr[i][1] = intervals[j][1];
					i++;
				}
				judje = 0;
			}
			else if (coin(intervals[j], intervals[j + 1]))
			{
				arr[i][0] = min(intervals[j][0], intervals[j + 1][0]);
				arr[i][1] = max(intervals[j + 1][1], intervals[j][1]);
				intervals[j + 1][0] = min(intervals[j][0], intervals[j + 1][0]);
				intervals[j + 1][1] = max(intervals[j + 1][1], intervals[j][1]);
				judje = 1;
			}
			j++;
		}
		if (intervals[j][1] > arr[i][1])
		{
			arr[i][0] = intervals[j][0];
			arr[i][1] = intervals[j][1];
		}
		arr.resize(i + 1);
		return arr;
	}
};

int main()
{
	vector<vector<int>> arr(10, vector<int>(2, 0));
	arr = { { 2, 3 }, { 4, 5 }, { 6, 7 }, { 8, 9 }, { 1, 10 } };
	arr.resize(5);
	Solution s;
	arr = s.merge(arr);
	system("pause");
	return 0;
}