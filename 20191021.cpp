#include<iostream>
#include<string>
#include<vector>;
#include<algorithm>
using namespace std;

// Violence algorithm
/*
class Solution {
public:
	int Judge(string s, int left, int right)
	{
		int i = left;
		int j = right;
		int count = 0;
		while (left <= right){
			if (s[left] != s[right]){
				return 0;
			}
			count += 2;
			left++;
			right--;
		}
		if ((j - i) % 2 - 1)
		{
			return count-1;
		}
		return count;
	}
	string longestPalindrome(string s) {
		if (s.size() == 1)
		{
			return s;
		}
		if (s.size() == 2)
		{
			if (s[0] == s[1])
			{
				return s;
			}
			else
			{
				string res;
				res.push_back(res[0]);
				return res;
			}
		}
		int inupt = 0;
		int size = 0;
		for (int i = 0; i < s.size(); i++)//起始
		{
			for (int j = i+1; j < s.size(); j++)//结束
			{
				int k = Judge(s, i, j);
				if (k > size)
				{
					size = k;
					inupt = i;
				}
			}
		}
		string res;
		for (int i = 0; i < size; i++)
		{
			res.push_back(s[inupt++]);
		}
		return res;
	}
};
*/ 

//Central expansion method
/*
class Solution {
public:
	string longestPalindrome(string s)
	{
		if (s.length() < 1)
		{
			return "";
		}
		int start = 0, end = 0;
		for (int i = 0; i < s.length()-1; i++)
		{
			int len1 = expandAroundCenter(s, i, i);
			int len2 = expandAroundCenter(s, i, i + 1);
			int len = max(len1, len2);
			if (len > end - start)
			{
				start = i - (len - 1) / 2;
				end = i + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}

	int expandAroundCenter(string s, int left, int right)
	{
		int L = left, R = right;
		while (L >= 0 && R < s.length() && s[L] == s[R])
		{
			L--;
			R++;
		}
		return R - L - 1;
	}
};
*/

//dynamic programming
class Solution {
public:
	string longestPalindrome(string s) {
		int size = s.size();
		if (size < 1)
		{
			return s;
		}
		bool **arr = new bool*[size];//定义二维数组
		for (int i = 0; i < size; i++)
		{
			*(arr + i) = new bool[size];
		}
		int length = 1;
		int index = 0;
		for (int i = 0; i < size; i++)
		{
			arr[i][i] = true;
			for (int j = 0; j < i; j++)
			{
				if (s[i] == s[j] && (i - j == 1 || arr[j + 1][i - 1]))
				{
					arr[j][i] = true;
					if ((i - j + 1) > length)
					{
						length = i - j + 1;
						index = j;
					}
				}
				else
				{
					arr[j][i] = false;
				}
			}
		}
		delete[]arr;
		return s.substr(index, length);
	}
};


int main()
{
	string s("dd");
	Solution max;
	string res = max.longestPalindrome(s);
	cout << res << endl;
	system("pause");
	return 0;
}