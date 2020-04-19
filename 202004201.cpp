#include<iostream>
#include<queue>

using namespace std;

class Solution {
	priority_queue<int> m_maxheap;//默认大根堆
	priority_queue<int, vector<int>, greater<int>> m_minheap;//小根堆
	int count = 0;
public:
	void Insert(int num)
	{
		count++;
		if (count == 1)
		{
			m_maxheap.push(num);
			return;
		}
		int max = m_maxheap.top();
		if (num <= max)
		{
			if (m_maxheap.size() == m_minheap.size())
			{
				m_maxheap.push(num);
			}
			else
			{
				m_maxheap.pop();
				m_maxheap.push(num);
				m_minheap.push(max);
			}
		}
		else
		{
			if (m_maxheap.size() == m_minheap.size())
			{
				int min = m_minheap.top();
				if (min < num)
				{
					m_minheap.pop();
					m_minheap.push(num);
					m_maxheap.push(min);
				}
				else
				{
					m_maxheap.push(num);
				}
			}
			else
			{
				m_minheap.push(num);
			}
		}
	}

	double GetMedian()
	{
		if ((m_maxheap.size() + m_minheap.size()) % 2 == 0)
		{
			double tmp1 = m_maxheap.top();
			double tmp2 = m_minheap.top();
			return (tmp1 + tmp2) / 2;
		}
		else
		{
			double tmp1 = m_maxheap.top();
			return tmp1;
		}
	}

};

int main()
{
	Solution s;
	//5,2,3,4,1,6,7,0,8
	s.Insert(5);
	cout << s.GetMedian() << endl;
	s.Insert(2);
	cout << s.GetMedian() << endl;
	s.Insert(3);
	cout << s.GetMedian() << endl;
	s.Insert(4);
	cout << s.GetMedian() << endl;
	s.Insert(1);
	cout << s.GetMedian() << endl;
	s.Insert(6);
	cout << s.GetMedian() << endl;
	s.Insert(7);
	cout << s.GetMedian() << endl;
	s.Insert(0);
	cout << s.GetMedian() << endl;
	s.Insert(8);
	cout << s.GetMedian() << endl;
	return 0;
}