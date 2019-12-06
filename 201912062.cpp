#include<iostream>

using namespace std;

class Solution {
public:
	int rectCover(int number) {
		if (number < 2)
		{
			return number;
		}
		int f1 = 1;
		int f2 = 1;
		int f3 = 1;
		while (number - 1 > 0)
		{
			f1 = f2;
			f2 = f3;
			f3 = f1 + f2;
			number--;
		}
		return f3;
	}
};

int main()
{
	Solution s;
	cout << s.rectCover(5) << endl;
	system("pause");
	return 0;
}