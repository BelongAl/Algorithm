#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		//输入
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int k, d;
		cin >> k >> d;

		//定义空间
		vector<vector<long long>> dp_max(n, vector<long long>(k + 1, 0));//最大乘积
		vector<vector<long long>> dp_min(n, vector<long long>(k + 1, 0));//最小乘积
		for (int i = 0; i < n; i++) //选一个小孩时
		{
			dp_max[i][1] = a[i];
			dp_min[i][1] = a[i];
		}
		for (int i = 0; i < n; i++) //控制从那个小孩开始
		{
			for (int j = 2; j <= k; j++) //表示选几个小孩
			{
				for (int m = max(0, i - d); m <= i - 1; m++) //选小孩
				{
					dp_max[i][j] = max(dp_max[i][j], max(dp_max[m][j - 1] * a[i], dp_min[m][j - 1] * a[i]));
					dp_min[i][j] = min(dp_min[i][j], min(dp_min[m][j - 1] * a[i], dp_max[m][j - 1] * a[i]));
				}
			}
		}
		long long max_value = dp_max[k - 1][k];
		for (int i = k; i < n; i++) {
			max_value = max(max_value, dp_max[i][k]);
		}
		cout << max_value << endl;
	}
	return 0;
}