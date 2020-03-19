#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;


class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordSet{ wordList.begin(), wordList.end() };//存储可用的单词表
		if (wordSet.find(endWord) == wordSet.end()) return 0;

		int res = 1;
		unordered_set<string> beginSet{ beginWord };//存储开始的单词
		unordered_set<string> endSet{ endWord };//存储结束的单词
		while (!beginSet.empty()) 
		{
			res++;
			unordered_set<string> nextSet;//存储下一次
			for (auto & word : beginSet) //如果woedSet里面存在现在的单词就删除
			{
				wordSet.erase(word);
			}
			for (auto & word : beginSet) 
			{
				for (int i = 0; i < word.size(); i++) //控制替换的位置
				{
					string nextWord = word;
					for (char j = 'a'; j <= 'z'; j++) //控制替换的字母
					{
						nextWord[i] = j;
						if (endSet.find(nextWord) != endSet.end())//若替换后和目标字母一样就返回
						{
							return res;
						}
						if (wordSet.find(nextWord) != wordSet.end()) //保存每一个下层目标
						{
							nextSet.insert(nextWord);
						}
					}
				}
			}
			beginSet = nextSet;
			if (beginSet.size() > endSet.size()) 
			{
				swap(beginSet, endSet);
			}
		}
		return 0;
	}
};

int man()
{

	Solution s;
	string s1("hot");
	string s2("dot");
	string s3("dog");
	string s4("lot");
	string s5("log");
	string s6("cog");
	vector<string> vs;
	vs.push_back(s1);
	vs.push_back(s2);
	vs.push_back(s3);
	vs.push_back(s4);
	vs.push_back(s5);
	vs.push_back(s6);
	s.ladderLength("hit", "cog", vs);
	return 0;
}