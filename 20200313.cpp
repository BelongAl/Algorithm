#include<iostream>
#include<vector>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right)
{
	if (left.size() == 0)
	{
		return right;
	}
	if (right.size() == 0)
	{
		return left;
	}

	int lsize = left.size()-1;
	int rsize = right.size()-1;
	left.resize(left.size() + right.size());
	int i = left.size() - 1;
	while(rsize >= 0 && lsize >= 0)
	{
		if (right[rsize] > left[lsize])
		{
			left[i] = right[rsize];
			rsize--;
		}
		else
		{
			left[i] = left[lsize];
			lsize--;
		}
		i--;
	}

	while (rsize >= 0)
	{
		left[i] = right[rsize];
		rsize--;
		i--;
	}
	while (lsize >= 0)
	{
		left[i] = left[lsize];
		lsize--;
		i--;
	}

	return left;
}




int main()
{
	vector<int> left{ 1,3,5,7,9 };
	vector<int> right{ 0,2,4,6,8 };

	vector<int> res = merge(left, right);

	system("pause");
	return 0;
}