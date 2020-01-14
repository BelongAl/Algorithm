#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int backPack(int m, vector<int> &A, vector<int> &V)
{
	int num = A.size();
	vector<int> max_value(m + 1, 0);//存储价值
	for (int i = 1; i <= num; i++)//控制物品个数
	{
		for (int j = m; j > 0; j--)//控制背包大小
		{
			if (A[i - 1] <= j)
			{
				max_value[j] = max(max_value[j], max_value[j - A[i - 1]] + V[i - 1]);
			}
		}
	}
	return max_value[m];
}

int main()
{
	int N = 5, V = 10;

	vector<int> size;
	vector<int> value;

	size.push_back(6);
	size.push_back(4);
	size.push_back(2);
	size.push_back(4);
	size.push_back(3);

	value.push_back(8);
	value.push_back(10);
	value.push_back(4);
	value.push_back(5);
	value.push_back(5);

	cout << backPack(V, size, value) << endl;;

	system("pause");

	return 0;
}