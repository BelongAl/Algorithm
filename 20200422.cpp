#include<string>

using namespace std;

class Solution {

	bool dfs(string matrix, int rows, int cols, int i, int j, string str, string path, int k)
	{
		if (i < 0 || j < 0 || i >= rows || j >= cols)
		{
			return false;
		}
		else if (matrix[i * cols + j] == '*' || matrix[i * cols + j] != str[k])
		{
			return false;
		}
		path.push_back(matrix[i * cols + j]);
		if (path == str)
		{
			return true;
		}
		matrix[i * cols + j] = '*';
		return dfs(matrix, rows, cols, i + 1, j, str, path, k+1) ||
			dfs(matrix, rows, cols, i - 1, j, str, path, k+1) ||
			dfs(matrix, rows, cols, i, j + 1, str, path, k+1) ||
			dfs(matrix, rows, cols, i, j - 1, str, path, k+1);
	}

public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		for (int i = 0; i < rows; i++)
		{
			string path;
			for (int j = 0; j < cols; j++)
			{
				if (dfs(matrix, rows, cols, i, j, str, path, 0) && matrix[i * cols + j] == str[0])
				{
					return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	char str[] = "abcesfcsadee";
	Solution s;
	char path[] = "bcced";
	bool res = s.hasPath(str, 3, 4, path);



	return 0;
}