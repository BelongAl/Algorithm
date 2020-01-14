/*Given a triangle, find the minimum path sum from top to bottom. 
   Each step you may move to adjacent numbers on the row below.
   For example, given the following triangle                    */
#include<iostream>
#include<vector>
#include<algorithm>

class Solution1{
public:
	int minimumTotal(std::vector<std::vector<int>> &triangle) {

		int row = triangle.size();

		for (int i = 1; i < row; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				if (j == 0)
				{
					triangle[i][j] += triangle[i - 1][j];
				}
				else if (j == i)
				{
					triangle[i][j] += triangle[i - 1][j - 1];
				}
				else
				{
					triangle[i][j] += std::min(triangle[i - 1][j], triangle[i - 1][j - 1]);
				}
			}
		}

		int ret = triangle[row-1][0];

		for (int i = 0; i < row; i++)
		{
			if (triangle[row - 1][i] < ret)
			{
				ret = triangle[row - 1][i];
			}
		}

		return ret;
	}
};

//method 2:
class Solution2 {
public:
	int minimumTotal(std::vector<std::vector<int> > &triangle) {
		int row = triangle.size();
		for (int i = row - 2; i >= 0; i--)
		{
			for (int j = 0; j < i + 1; j++)
			{
				triangle[i][j] += std::min(triangle[i+1][j], triangle[i+1][j+1]);
			}
		}
		return triangle[0][0];
	}
};

int main()
{

}
