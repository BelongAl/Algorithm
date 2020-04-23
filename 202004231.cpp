//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<map>
//
//using namespace std;
//
//struct work
//{
//	int m_salary;
//	int m_difficulty;
//
//	work(int salary, int difficulty) :
//		m_difficulty(difficulty),
//		m_salary(salary)
//	{}
//
//	work(){}
//
//	bool operator<(work w)
//	{
//		if (m_salary < w.m_salary)
//		{
//			return true;
//		}
//		return false;
//	}
//
//};
//
//int main()
//{
//	int N, M;
//	cin >> N >> M;
//	vector<work> v(N);
//	for (int i = 0; i < N; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		v[i] = work(b, a);
//	}
//	sort(v.begin(), v.end());
//	map<int, int> Ai;
//	for (int i = 0; i < M; i++)
//	{
//		int tmp;
//		cin >> tmp;
//		Ai[tmp] = i;
//	}
//
//	int max = N - 1;
//	vector<int> ret(N);
//	for (auto it = --Ai.end(); it != --Ai.begin(); it--)
//	{
//		bool sign = true;
//		for (int j = max; j >= 0; j--)
//		{
//			if (it->first >= v[j].m_difficulty)
//			{
//				ret[it->second] = v[j].m_salary;
//				max = j;
//				sign = false;
//				break;
//			}
//		}
//		if (sign)
//		{
//			ret.push_back(0);
//		}
//	}
//
//	for (int i = 0 ; i < M; i++)
//	{
//		cout << ret[i] << endl;
//	}
//
//	return 0;
//}

#include<stdio.h>
#include<vector>
#include<iostream>
#include<map>
#include<math.h>
using namespace std;
int main() {
	int m, n;
	scanf("%d%d", &n, &m);
	map<int, int> mp;
	for (int i = 0; i < n; i++) 
	{
		int diff, money;
		scanf("%d %d", &diff, &money);
		if (mp[diff] < money) mp[diff] = money;//若有相同困难程度的只记录最高薪水
	}
	vector<int> peopability(m);
	for (int i = 0; i < m; i++) 
	{
		scanf("%d", &peopability[i]);
		mp.insert(make_pair(peopability[i], 0));//将这些同学的能力值插入到map中
	}
	auto pre = mp.begin();
	auto cur = mp.begin();
	cur++;
	while (cur != mp.end()) //利用慢指针法
	{
		if (cur->second < pre->second) {
			cur->second = pre->second;
		}
		cur++;
		pre++;
	}
	for (int i = 0; i < m; i++) {
		cout << mp[peopability[i]] << endl;
	}
}