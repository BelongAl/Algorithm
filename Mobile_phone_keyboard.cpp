#include<iostream>
#include<vector>
#include<string>

using namespace std;

namespace _tmp
{
	string numLetter[] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
}


class Solution {
public:
	void dealLetterCombinations(string &digits, size_t pos, vector<string> &alldata)
	{
		static string res = digits;//为res确定大小
		if (pos < digits.size())
		{
			for (auto &i : _tmp::numLetter[digits[pos] - '2'])
			{
				res[pos] = i;
				dealLetterCombinations(digits, pos + 1, alldata);
			}
		}
		else
		{
			cout << res << endl;
			alldata.push_back(res);
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> res;
		dealLetterCombinations(digits, 0, res);
		return res;
	}
};
//class Solution {
//public:
//	void dealLetterCombinations(string &digits, size_t pos, vector<string> &alldata)
//	{
//		string m_numLetter[] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
//		static string res = digits;
//		if (pos < digits.size())
//		{
//			for (auto &i : m_numLetter[digits[pos] - '2'])
//			{
//				res[pos] = i;
//				dealLetterCombinations(digits, pos + 1, alldata);
//			}
//		}
//		else
//		{
//			cout << res << endl;
//			alldata.push_back(res);
//		}
//	}
//
//	vector<string> letterCombinations(string digits) {
//		vector<string> res;
//		if (digits.size() == 0)
//		{
//			return res;
//		}
//		dealLetterCombinations(digits, 0, res);
//		return res;
//	}
//};
int main()
{
	Solution s;
	string digits = "23";
	s.letterCombinations(digits);
	system("pause");
	return 0;
}