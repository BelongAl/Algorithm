#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.size() == 0)
		{
			return;
		}
		vector<int> tmp(array.size(),0);
		int i = 0;
		int j = array.size() - 1;
		int a = 0;
		int b = array.size() - 1;
		while (i < array.size() && j >= 0)
		{
			if (array[i] % 2 == 1)
			{
				tmp[a] = array[i];
				a++;
			}
			if (array[j] % 2 == 0)
			{
				tmp[b] = array[j];
				b--;
			}
			i++;
			j--;
		}
		array = tmp;
	}
};

int main()
{
	Solution s;
	int arr[] = { 3,5,6,1,8,4,9,7 };
	vector<int> v(arr+0,arr+8);
	s.reOrderArray(v);
	system("pause");
	return 0;
}