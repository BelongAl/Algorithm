//×Ö·û´®ÇÐ¸î
#include<iostream>
#include<cstring>
#include<unordered_set>
#include<vector>

class Solution {
public:
	bool wordBreak(std::string s, std::unordered_set<std::string> &dict) {
		int len = s.size();
		std::vector<bool> canbreak(len+1, false);
		canbreak[0] = true;
		for (int i = 1; i <= len; i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (canbreak[j] && dict.find(s.substr(j, i - j)) != dict.end())//If the first I characters can form a word and 
																			   //j toI words can also form a word
				{
					canbreak[i] = true;
					break;
				}
			}
		}
		return canbreak[len];
	}
};

int main()
{
	return 0;
}
