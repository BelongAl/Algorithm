#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
	int cost(string& s, int l, int r) //��ʾ���ַ�����ɻ��Ĵ�����Ҫ�����ٲ���

	{
		int ret = 0;
		for (int i = l, j = r; i < j; ++i, --j) 
		{
			if (s[i] != s[j]) 
			{
				++ret;
			}
		}
		return ret;
	}

	int palindromePartition(string& s, int k) 
	{
		int n = s.size();
		vector<vector<int>> f(n + 1, vector<int>(k + 1, INT_MAX));
		f[0][0] = 0;
		for (int i = 1; i <= n; ++i)//��ʾǰi���ַ�
		{
			for (int j = 1; j <= min(k, i); ++j) //��ʾ�ֽ�ɼ���
			{
				if (j == 1) //�ָ��һ��
				{
					f[i][j] = cost(s, 0, i - 1);
				}
				else //ת�Ʒ���
				{
					for (int i0 = j - 1; i0 < i; ++i0) //һһ���٣��ҳ��ָ���ٵģ�j-1��ʾ���ٷָ��j����Ҫ�������ַ�����Ȼ��һһ�о١�
					{
						f[i][j] = min(f[i][j], f[i0][j - 1] + cost(s, i0, i - 1));//f[i][j]��ʾ��s��ǰi���ַ��ָ��j�����Ĵ���Ҫ�������޸Ĳ���
					}
				}
			}
		}

		return f[n][k];
	}
};


int main()
{
	string s("daabbc");
	Solution so;
	so.palindromePartition(s, 3);
	return 0;
}