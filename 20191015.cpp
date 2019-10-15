#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int count = 0;
		int tmp = 0;
		tmp = numbers[0];
		for (auto &i : numbers)
		{
			if (i == tmp)
			{
				count++;
			}
			else
			{
				count--;
				if (count == 0)
				{
					tmp = i;
					count++;
				}
			}
		}
		count = 0;
		for (auto &i : numbers)
		{
			if (tmp == i)
			{
				count++;
			}
		}
		if (count > numbers.size() / 2)
		{
			return tmp;
		}
		return 0;
	}
};

int main()
{
	Solution s;
	int arr[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	vector<int> v;
	for (auto &i : arr)
	{
		v.push_back(i);
	}
	cout << s.MoreThanHalfNum_Solution(v) << endl;
	system("pause");
	return 0;
}