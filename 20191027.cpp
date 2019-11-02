#include<iostream>

using namespace std;


class assist {
	static int m_n;
	static int m_sum;
public:
	static unsigned int  GetSum()
	{
		return m_sum;
	}
	assist()
	{
		m_n++;
		m_sum += m_n;
	}
};

int assist::m_n = 0;
int assist::m_sum = 0;

class Slution
{
public:
	int Sum_Solution(int n) {
		assist *p = new assist[n];
		delete[]p;
		p = nullptr;
		return assist::GetSum();	
	}
};

	/*
	int Sum_Solution(int n) {
		if (n == 1)
		{
			return 1;
		}
		else
		{
			return n + Sum_Solution(n - 1);
		}
	}
	*/

	/*
	int Sum_Solution(int n) {
			int ans = n;
			ans && (ans += Sum_Solution(n - 1));
			return ans;
	}
	*/
};

int main()
{
	Slution s;
	cout << s.Sum_Solution(6) << endl;
	system("pause");
	return 0;
}
