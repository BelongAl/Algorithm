#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		if (tokens.size() <= 1)
		{
			return atoi(tokens[0].c_str());
		}
		stack<int> s;
		int i = 0;
		int tmp = 0;
		while (i < tokens.size())
		{
			if ('0' <= tokens[i][0] && tokens[i][0] <= '9' || tokens[i].size() > 1)// push digital
			{
				s.push(atoi(tokens[i].c_str()));//atoi function is string convert to number
			}
			else//
			{
				int right = s.top();
				s.pop();
				int left = s.top();
				s.pop();
				switch (tokens[i][0])
				{
				case '+':
					tmp = left + right;
					break;
				case '-':
					tmp = left - right;
					break;
				case '*':
					tmp = left * right;
					break;
				case '/':
					tmp = left / right;
					break;
				}
				s.push(tmp);
			}
			i++;
		}
		return tmp;
	}
};

int main()
{

	vector<string> vs;// "2", "1", "+", "3", "*" );
	vs.push_back("2");
	vs.push_back("1");
	vs.push_back("+");
	vs.push_back("3");
	vs.push_back("*");
	Solution s;
	cout << s.evalRPN(vs) << endl;
	system("pause");
	return 0;
}