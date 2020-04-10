#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

int operat(int a, int b, char c)
{
	if (c == '+') { return a + b; }
	else if (c == '-') { return a - b; }
	else if (c == '*') { return a * b; }
	else { return a / b; }
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}

		stack<int> s;
		for (int i = 0; i < n; i++)
		{
			if ('0' <= v[i][0] && v[i][0] <= '9')
			{
				s.push(atoi(v[i].c_str()));
			}
			else
			{
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();
				s.push(operat(a, b, v[i][0]));
			}
		}
		cout << s.top() << endl;
	}
}