#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		int row = matrix.size() - 1;
		int col = matrix[0].size() - 1;
		int i = 0, j = 0;
		int index = 0;
		int up = 0, down = matrix.size()-1, left = 0, right = matrix[0].size()-1;
		while(up <= down && left <= right)
		{
			if (index == 0)//向右走
			{
				i = up;
				for (j = left; j <= right; j++)
				{
					res.push_back(matrix[i][j]);
				}
				up++;
				index = 1;
			}
			else if (index == 1)//向下走
			{
				j = right;
				for (i = up; i <= down; i++)
				{
					res.push_back(matrix[i][j]);
				}
				right--;
				index = 2;
			}
			else if (index == 2)//向右走
			{
				i = down;
				for (j = right; j >= left; j--)
				{
					res.push_back(matrix[i][j]);
				}
				down--;
				index = 3;
			}
			else if (index == 3)//向上走
			{
				j = left;
				for (i = down; i >= up; i--)
				{
					res.push_back(matrix[i][j]);
				}
				left++;
				index = 0;
			}
		}
		return res;
	}
};

int main()
{
	vector<vector<int>> array(4);
	int k = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			array[i].push_back(k);
			k++;
		}
	}
	Solution s;
	vector<int> res = s.spiralOrder(array);
	system("pause");
	return 0;
}