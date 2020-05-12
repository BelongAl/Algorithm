#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while (cin >> n)
	{
		unordered_map<int, bool> mp;
		priority_queue<int, vector<int>, greater<int>> q;
		while (n--)
		{
			int val;
			cin >> val;
			if (mp[val] == false)
			{
				q.push(val);
				mp[val] = true;
			}
		}
		int k;
		cin >> k;
		while (k > 1)
		{
			k--;
			q.pop();
		}
		cout << q.top() << endl;
	}
	return 0;
}
