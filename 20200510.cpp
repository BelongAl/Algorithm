#include<string>
#include<algorithm>
#include<vector>

using namespace std;
//
//class Solution {
//
//	bool judje(string s, int left, int right)
//	{
//		for (; left < right; left++, right--)
//		{
//			if (s[left] != s[right])
//			{
//				return false;
//			}
//		}
//		return true;
//	}
//
//public:
//	int minCut(string s) {
//		if (s.size() < 1)
//		{
//			return 0;
//		}
//		int n = s.size() + 1;
//		vector<int> v(n, INT_MAX);
//		v[0] = 0;
//		for (int i = 1; i < n; i++)//表示v的下标
//		{
//			for (int j = 0; j < i; j++)//表示s的下标
//			{
//				if (judje(s, j, i - 1) == true)
//				{
//					v[i] = min(v[i], v[j] + 1);
//				}
//			}
//		}
//		return v[n - 1] - 1;
//	}
//};


class Solution1
{
public:
	int minCut(string s) 
	{
 		int len = s.size();
		vector<int> vec(len, 0);
		vector<vector<bool> > bvec(len, vector<bool>(len, false));
		for (int i = 0; i < len; i++)//控制元素
		{
			vec[i] = i;//最坏的情况
			for (int j = i; j >= 0; j--)
			{
				if ((s[i] == s[j]) && (i - j < 2 || bvec[i - 1][j + 1]))//如果是回文
				{
					bvec[i][j] = true;
					if (j == 0)//i以前的全部是回文
						vec[i] = min(vec[i], 0);
					else//
						vec[i] = min(vec[i], vec[j - 1] + 1);
				}
			}
		}
		return vec[len - 1];
	}
};


int main()
{
	Solution1 s;
	s.minCut("ccaacabacb");


	return 0;
}