#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		map<int, vector<int>> m;
		vector<vector<int>> v(s2.size(), vector<int>(s1.size(), 0));
		for (int i = 0; i < s1.size(); i++)
		{
			for (int j = 0; j < s2.size(); j++)
			{
				if (s1[i] == s2[j])
				{
					v[j][i] = 1;
					m[i].push_back(j);
				}
			}
		}
		int max = 0;
		bool s = true;
		for (int k = 2; k < s1.size(); k++)
		{
			for (int i = s1.size() - 1; i > 0; i--)//¿ØÖÆÁÐ
			{
				for (int j = 0; j < m[i].size(); j--)
				{
					bool sign = true;
					for (int k = 0; k < m[i - 1].size(); k--)
					{
						if (v[i - 1][m[i - 1][k]] == v[i][m[i][j]])
						{
							v[i][m[i][j]]++;
							if (v[i][m[i][j]] > max)
							{
								max = v[i][m[i][j]];
							}
							s = false;
							sign = false;
							break;
						}
					}
					if (sign)
					{
						m[i].erase(m[i].begin() + j, m[i].begin() + j + 1);
					}
				}
			}
			if (s)
			{
				break;
			}
		}
		cout << max << endl;
    }
	return 0;
}