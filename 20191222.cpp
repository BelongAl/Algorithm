#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
	vector<int> printMatrix(vector<vector<int> > matrix) 
	{
		vector<int> res;

		int up = 0;
		int down = matrix.size() - 1;
		int left = 0;
		int right = matrix[0].size() - 1;

		int i = 0, j = 0;//Control coordinate
		int direction = 0;//Direction of movement £º0 - right/ 1 - down/ 2 - left /3 - up   

		int count = (down + 1)*(right + 1);

		while (count--)
		{
			res.push_back(matrix[i][j]);
			if (direction == 0){ j++;}
			else if (direction == 1){ i++;}
			else if (direction == 2){ j--;}
			else{ i--;}

			if (j > right || j < left || i > down || i < up){
				if (j > right) { j--; up++; i++; }
				if (j < left) { j++; down--; i--; }
				if (i > down) { i--; right--; j--; }
				if (i < up) { i++; left++; j++; }

				direction++;
				if (direction == 4){
					direction = 0;
				}
			}
		}

		return res;

	}
};

int main()
{
	vector<vector<int>> array;
	array.resize(5);
	for (int i = 0; i < 5; i++)
	{
		array[i].resize(5);
	}
	int k = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			array[i][j] = k;
			k++;
		}
	}

	Solution s;
	s.printMatrix(array);

	return 0;
}