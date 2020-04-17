#include<iostream>
#include<vector>

using namespace std;

class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		// write code here
		int left = 0;
		int right = m - 1;
		int up = 0;
		int down = n - 1;
		int direction[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
		int k = 0;
		int i = 0, j = 0;
		vector<int> v;
		while (left <= right || up <= down)
		{
			while (i >= up && i <= down && j >= left && j <= right)
			{
				v.push_back(mat[i][j]);
				i += direction[k][0];
				j += direction[k][1];
			}
			if (k == 3) 
			{
 				i = up; 
				j++;
				left++;
			}
			else if (k == 1) 
			{
				i = down;
				j--;
				right--;
			}
			else if (k == 0) 
			{
				j = right;
				i++;
				up++;
			}
			else 
			{
				j = left;
				i--;
				down--;
			}
			k++;
			if (k == 4)
			{
				k = 0;
			}
		}
		return v;
	}
};

int main()
{
	vector<vector<int>> v{ {1,2,3},{4,5,6},{7,8,9} };
	Printer p;
	p.clockwisePrint(v, 3, 3);
	return 0;
}