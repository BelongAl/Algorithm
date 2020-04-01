#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	int fei[1000001];
	fei[0] = 0;
	fei[1] = 1;
	fei[2] = 2;
	for (int i = 3; i < 100001; i++)
	{
		fei[i] = fei[i - 1] + fei[i - 2];
		if (fei[i] > 1000000)
		{
			fei[i] %= 1000000;
		}
	}

	int n = 0;
	while (cin >> n)
	{
		cout << fei[n] << endl;
	}
	return 0;
}