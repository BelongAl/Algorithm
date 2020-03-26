#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {

	vector<string> res;

	void WholeSort(string str, int index)
	{
		if (index == str.size() - 1)
		{
			res.push_back(str);
			return;
		}
		unordered_map<char, bool> mp;
		for (int i = index; i < str.size(); i++)
		{
			if (!mp[str[i]])
			{
				mp[str[i]] = true;
				swap(str[index], str[i]);
				WholeSort(str, index + 1);
				swap(str[index], str[i]);
			}
		}
	}

public:
	vector<string> Permutation(string str) {
		WholeSort(str, 0);
		return res;
	}
};


int main()
{
	Solution s;
	s.Permutation("abc");

	return 0;
}