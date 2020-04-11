#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
	int StrToInt(string str) {
		const int length = str.length();
		int isNegtive = 1;//标记正负
		int overValue = 0;//标记超出
		int digit = 0, value = 0;

		if (length == 0) return 0;
		else {
			int idx = 0;//标记开始的位置
			if (str[0] == '-') { isNegtive = -1; idx = 1; }
			else if (str[0] == '+') { idx = 1; }

			for (; idx < length; idx++) {
				digit = str[idx] - '0';//本位的数字
				// overValue表示本轮循环是否会越界
				overValue = isNegtive * value - INT_MAX / 10
					+ (((isNegtive + 1) / 2 + digit > 8) ? 1 : 0);

				if (digit < 0 || digit>9)
				{
					return 0;
				}
				else if (overValue > 0)
				{
					return 0;
				}

				value = value * 10 + isNegtive * digit;//反回值
			}
			return value;
		}
	}
};

int main()
{
	Solution s;
	s.StrToInt("-123");
	return 0;
}
