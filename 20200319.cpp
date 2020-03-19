#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;


class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordSet{ wordList.begin(), wordList.end() };//�洢���õĵ��ʱ�
		if (wordSet.find(endWord) == wordSet.end()) return 0;

		int res = 1;
		unordered_set<string> beginSet{ beginWord };//�洢��ʼ�ĵ���
		unordered_set<string> endSet{ endWord };//�洢�����ĵ���
		while (!beginSet.empty()) 
		{
			res++;
			unordered_set<string> nextSet;//�洢��һ��
			for (auto & word : beginSet) //���woedSet����������ڵĵ��ʾ�ɾ��
			{
				wordSet.erase(word);
			}
			for (auto & word : beginSet) 
			{
				for (int i = 0; i < word.size(); i++) //�����滻��λ��
				{
					string nextWord = word;
					for (char j = 'a'; j <= 'z'; j++) //�����滻����ĸ
					{
						nextWord[i] = j;
						if (endSet.find(nextWord) != endSet.end())//���滻���Ŀ����ĸһ���ͷ���
						{
							return res;
						}
						if (wordSet.find(nextWord) != wordSet.end()) //����ÿһ���²�Ŀ��
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