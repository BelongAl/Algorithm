#include<string>
#include<iostream>
#include<vector>

using namespace std;

//����һ������
/*
	��*�����������
	1��0�γ��� -> d*bc��bc ����ֻ��Ҫɾ��p��ǰ����Ԫ�� ��  isMatch(s, p.substr(2))
	2������1�λ��� -> b*bc bbbc ����ֻ��Ҫ���ɾ��s�е���Ԫ��Ȼ���ٵ��õ�һ�����
		b*bc bbbc
		b*bc bbc
		b*bc bc
		bc   bc
*/

class Solution1 {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
		{
			return s.empty();
		}

		bool ismath = !s.empty() && (s[0] == p[0] || p[0] == '.');
		
		if (p.size() > 1 && p[1] == '*')
		{
			return isMatch(s, p.substr(2)) || (ismath && isMatch(s.substr(1), p));
		}
		else
		{
			return ismath && isMatch(s.substr(1), p.substr(1));
		}
	}
};

class Solution {
public:
	bool isMatch(string s, string p) {
		s = " " + s;
		p = " " + p;
		int m = s.size();
		int n = p.size();

		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (s[i - 1] == p[j - 1] || p[j - 1] == '.')//����ȣ���ֱ���ж��ϴ��Ƿ�Ϊtrue 
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*')//��Ϊ*
				{
					if (s[i - 1] != p[j - 2] && p[j - 2] != '.')//������ȣ�ֱ���ж�����ǰ�����Ƿ�ƥ�䣬������0��  d*bc��bc
					{
						dp[i][j] = dp[i][j - 2];
					}
					else//���ֶ��  acb* acbbt
					{
						dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];//��ʾ����һ�� ��ʾ����0�� ��ʾ����n��
					}
				}
			}
	}
};

int main()
{

	return 0;
}