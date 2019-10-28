#include<stack>
#include<iostream>

using namespace std;

class MinStack {
	stack<int> s1;
	stack<int> s2;// ×îÐ¡Õ»
public:
	/** initialize your data structure here. */

	MinStack()
	{}

	void push(int x) {
		if (s2.empty() || s2.top() >= x)
		{
			s2.push(x);
		}
		s1.push(x);
	}

	void pop() {
		if (!s2.empty() && s1.top() == s2.top())
		{
			s2.pop();
		}
		if (!s1.empty())
		{
			s1.pop();
		}
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return s2.top();
	}
};

int main()
{
	return 0;
}