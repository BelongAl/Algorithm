#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	while (cin >> N >> M) 
	{
		vector<int> steps(M + 1, INT_MAX);
		steps[N] = 0;
		for (int i = N; i <= M; i++) //控总的的循环
		{
			if (steps[i] == INT_MAX) 
			{
				continue;
			}
			for (int j = 2; (j*j) <= i; j++) //记录每个石板上可以走的步数
			{
				if (i%j == 0)
				{
					if (i + j <= M)
					{
						steps[i + j] = min(steps[i] + 1, steps[i + j]);
					}
					if (i + (i / j) <= M) 
					{
						steps[i + (i / j)] = min(steps[i] + 1, steps[i + (i / j)]);
					}

				}

			}
		}
		if (steps[M] == INT_MAX) 
		{
			steps[M] = -1;
		}
		cout << steps[M] << endl;
	}
	return 0;
}