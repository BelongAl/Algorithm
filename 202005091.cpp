#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(vector<int>& v1, vector<int>& v2)
{
	return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
}

class Solution {
public:
	int videoStitching(vector<vector<int>>& clips, int T) {
		int t = 0;
		sort(clips.begin(), clips.end(), cmp);
		int i = 0, ans = 0, last_t;
		while (i < clips.size() && t < T) {
			if (clips[i][0] <= t) {
				last_t = t;
				while (i < clips.size() && clips[i][0] <= last_t) {
					t = max(t, clips[i][1]);
					i++;
				}
				ans++;
			}
			else {
				break;
			}
		}
		return t >= T ? ans : -1;
	}
};

int main()
{
	vector<vector<int>> v{ {0,2}, {4,6}, {8,10}, {1,9}, {1,5}, {5,9}, {9, 10} };
	Solution s;
	s.videoStitching(v, 3);
	return 0;
}