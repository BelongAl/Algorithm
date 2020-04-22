#include<iostream>
#include<algorithm>

using namespace std;

//̰���㷨
class Solution1 {
public:
	int cutRope(int number) {
		int ret = 0;//��ʾ��Ϊһ�ε�ʱ��
		int divided = 2;
		while (1)
		{
			int n = number / divided;//��ʾÿһ�λ�������
			int k = number % divided;//��ʾ�ڻ�������Ҫ���ϵ�
			int tmp;
			if (k > 0)
			{
				tmp = pow(n, (divided - k)) * pow(n + 1, k);
			}
			else
			{
				tmp = pow(n, (divided - k));
			}
			if (tmp > ret)
			{
				ret = tmp;
			}
			else
			{
				return ret;
			}
			divided++;
		}
	}
};

//��̬�滮
class Solution {
public:
	int cutRope(int number) {
		if (number == 2)
		{
			return 1;
		}
		if (number == 3)
		{
			return 2;
		}
		int x = number / 3;
		int y = number % 3;
		if (y == 0)
		{
			return pow(3, x);
		}
		else if (y == 1)
		{
			return pow(3, x - 1) * 4;
		}
		else if (y == 2)
		{
			return pow(3, x) * 2;
		}
	}
};

int main()
{
	Solution s;
	int ret = s.cutRope(5);
	return 0;
}