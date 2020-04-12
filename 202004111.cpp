#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;
		vector<unordered_map<int, bool>> vm(N + 1);//集合
		unordered_map<int, int> mp;//表示在那个集合
		for (int i = 1; i <= N; i++)
		{
			vm[i][i] = true;
			mp[i] = i;
		}

		unordered_map<int, bool>::iterator it;
		while (M--)
		{
			int op;
			cin >> op;
			if (op == 1)
			{
				int a, b;
				cin >> a >> b;
				if (mp[a] == mp[b])
				{
					continue;
				}
				else
				{
					for (it = vm[mp[b]].begin(); it != vm[mp[b]].end(); )
					{
						if ((*it).second)
						{
							vm[mp[a]][(*it).first] = true;
							vm[mp[b]].erase(it++);
						}
						else
						{
							it++;
						}
					}
					mp[b] = mp[a];//全部合并到a里面
				}
			}
			else if (op == 2)
			{
				int a;
				cin >> a;
				if (vm[mp[a]][a] == true)
				{
					if (vm[mp[a]].size() == 1)
					{
						continue;
					}
					else
					{
						vm[mp[a]].erase(a);
						unordered_map<int, bool> tmp;
						tmp[a] = true;
						vm.push_back(tmp);
						mp[a] = vm.size() - 1;
					}
				}
			}
			else
			{
				int a;
				cin >> a;
				cout << vm[mp[a]].size() << endl;;
			}
		}
	}

	return 0;
}