#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main()
{
	string A;
	string B;
	while (cin >> A >> B)
	{
		unordered_map<char, int> umA;
		unordered_map<char, int> umB;
		for (int i = 0; i < A.size(); i++)
		{
			umA[A[i]]++;
		}
		for (int i = 0; i < B.size(); i++)
		{
			umB[B[i]]++;
			if (umA[B[i]] < umB[B[i]])
			{
				cout << "No" << endl;
			}
		}
		cout << "Yes" << endl;
	}
	return 0;
}