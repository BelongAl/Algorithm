#include<iostream>
#include<vector>
using namespace std;

class Solution {
	void AdjustUp(vector<int>& input, int child)
	{
		int parent = (child - 1) / 2;
		while (parent >= 0)
		{
			if (input[parent] > input[child])
			{
				std::swap(input[parent], input[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
	void AdjustDown(vector<int>& input, int &size)
	{
		if (size == 0)
		{
			return;
		}
		swap(input[0], input[size]);
		size--;
		int parent = 0;
		int child = parent * 2 + 1;
		while (child <= size)
		{
			if (child + 1 <= size && input[child] > input[child + 1])
			{
				child++;
			}
			if (input[child] < input[parent])
			{
				swap(input[child], input[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}

	}
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		//构建一个最小栈
		for (int i = 1; i < input.size(); i++)
		{
			AdjustUp(input, i);
		}
		int size = input.size() - 1;
		for (int i = 0; i < k; i++)
		{
			AdjustDown(input, size);
		}

		int i = input.size() - 1;
		size = (input.size() - 1 - k);
		for (i ; i > size; i--)
		{
			res.push_back(input[i]);
		}
		return res;
	}
};

int main()
{
	vector<int> t{ 3,7,1,9,2 };
	Solution s;
	vector<int> res = s.GetLeastNumbers_Solution(t, 5);
	return 0;
}