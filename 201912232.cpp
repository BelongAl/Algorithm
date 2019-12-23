#include<iostream>
#include<vector>

using namespace std;

class Solution {
	bool judge(int left, int right, vector<int>sequence)
	{
		if (left >= right)
		{
			return true;
		}
		int cut = left;
		while (cut <= right && sequence[cut] < sequence[right])
		{
			cut++;
		}
		for (int i = cut; i < right; i++)
		{
			if (sequence[i] < sequence[right])
			{
				return false;
			}
		}
		return judge(left, cut - 1, sequence) && judge(cut, right - 1, sequence);
	}
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() == 0)
		{
			return false;
		}
		int left = 0;
		int right = sequence.size()-1;
		return judge(left, right, sequence);
	}
};

int main()
{
	Solution s;
	int arr[] = { 4,15,6,12,16,14,10 };
	vector<int> v(arr, arr + 7);
	cout << s.VerifySquenceOfBST(v) << endl;
	system("pause");
	return 0;
}