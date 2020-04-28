#include<vector>
#include<algorithm>

using namespace std;

//f[i][j] = min(f[i-1][j], f[i-1][j-1]) + triangle[i][j];

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		vector<vector<int>> f(triangle.size() + 1, vector<int>(triangle[triangle.size()-1].size() + 2, 0));
		for (int i = 1; i < triangle.size() + 1; i++)
		{
			int j = 1;
			for (; j <= i; j++)
			{
				f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + triangle[i - 1][j - 1]; 
			}
			f[i][0] = f[i][1];
			f[i][j] = f[i][j - 1];
		}
		int ret = INT_MAX;
		for (int i = 1; i < f[0].size(); i++)
		{
			if (f[f.size() - 1][i] < ret)
			{
				ret = f[f.size() - 1][i];
			}
		}
		return ret;
	}
};

int main()
{
	vector<vector<int>> v;
	vector < int> v1{2};
	vector < int> v2{3, 4};
	vector < int> v3{6, 5, 7};
	vector < int> v4{4, 1, 8, 3};
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	Solution s;
	s.minimumTotal(v);
	return 0;
}