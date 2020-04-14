#include<iostream>
#include<queue>

using namespace std;

class Solution
{
	char m_sign[256] = { 0 };
	queue<char> m_fq;
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (m_sign[ch] == 0)
		{
			m_fq.push(ch);
			m_sign[ch]++;
		}
		else if (m_sign[ch] == 1)
		{
			m_sign[ch]++;
		}

	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		while (!m_fq.empty())
		{
			if (m_sign[m_fq.front()] == 1)
			{
				return m_fq.front();
			}
			m_fq.pop();
		}
		return '#';
	}

};