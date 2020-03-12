#include<iostream>
#include<vector>

using namespace std;

bool FindNumber(vector<vector<int>> v, int number)
{
	if (v.size() == 0)
	{
		return false;
	}
	int col = v[0].size() - 1;
	int row = 0;
	while (col >= 0 && row < v.size())
	{
		if (v[row][col] > number)
		{
			col--;
		}
		else if (v[row][col] < number)
		{
			row++;
		}
		else
		{
			cout << v[row][col] << endl;
			return true;
		}
	}
	return false;
}

int main()
{
	vector<vector<int>> v{ vector<int>{1,2,8,9}, 
						   vector<int>{2,4,9,12}, 
						   vector<int>{4,7,10,13}, 
						   vector<int>{6,8,11,15}
						 };
	FindNumber(v, 1);
	FindNumber(v, 10);
	FindNumber(v, 15);
	FindNumber(v, 0);
	FindNumber(v, 90);
	vector<vector<int>> tmp;
	FindNumber(tmp, 90);
	system("pause");
	return 0;
}