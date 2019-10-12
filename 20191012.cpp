#include<vector>
#include<iostream>

using namespace std;

/*
//Method 1£ºOne-dimensional array
void printArray(const vector<int> &v,int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
}

void printGenerate(int n)
{
	vector<int> v(n, 0);
	v[0] = 1;
	printArray(v, 1);
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i; j >= 1; j--)
		{
			v[j] += v[j - 1];
		}
		printArray(v, i + 1);
	}
}

int main()
{
	printGenerate(10);
	system("pause");
	return 0;
}
*/

//Method 2£ºTwo-dimensional array

void printArray(const vector<int> &v, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << ' ';
	}
	cout << endl;
}

vector<vector<int>> generate(int numRows)
{
	vector<vector<int>> data(numRows);
	if (0 == numRows)
	{
		return data;
	}
	int i, j;
	data[0].push_back(1);
	for (i = 1; i < numRows; i++)
	{
		data[i] = data[i - 1];
		for (j = i-1; j > 0; j--)
		{
			data[i][j] += data[i][j - 1];
		}
		data[i].push_back(1);
	}
	return data;
}

int main()
{
	vector<vector<int>> data = generate(10);
	for (auto &i : data)
	{
		for (auto &j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}