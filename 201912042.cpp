#include<iostream>
#include<stack>

using namespace std;

class step
{
public:
	int m_y;
	int m_x;
	step(int y, int x) :
		m_y(y),
		m_x(x)
	{

	}
};

int maxDivisor(int m_y, int m_x)
{
	int k = m_x - 1;
	while (k-- && k > 1)
	{
		if (m_y%k == 0)
		{
			return k;
		}
	}
	return -1;
}

int minStep(int m, int n)
{
	int p = m;
	stack<step> s;
	int min = -1;
	s.push(step(m, m));
	int index = 1;
	while (1)
	{
		step tmp = s.top();
		int ret = 0;
		if (index == 1)//查找公约数的方式
		{
			ret = maxDivisor(tmp.m_y, tmp.m_y);
		}
		else
		{
			ret = maxDivisor(tmp.m_y, tmp.m_x);
		}
		if (ret == -1)
		{
			if (tmp.m_y == p)
			{
				break;
			}
			index = 0;
			s.pop();
		}
		if (tmp.m_y+ret >= n)
		{
			if (tmp.m_y+ret == n && ((s.size() < min) || (min == -1)))
			{
				min = s.size();
				break;
			}
			s.pop();
			index = 0;
		}
		else
		{
			if (ret != -1)
			{
				s.top().m_x = ret;
				s.push(step(tmp.m_y + ret, ret));
				index = 1;
			}
		}
	}
	return min;
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		cout << minStep(m,n);
	}
	system("pause");
	return 0;
}