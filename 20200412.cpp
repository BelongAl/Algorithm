#include<iostream>
#include<vector>

using namespace std;

//method 1: violent solution  
//Time complexity: O(n*n)
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> res;
		for (int i = 0; i < A.size(); i++)
		{
			int left = 1;
			int right = 1;
			//Çóleft
			for (int j = 0; j < i; j++)
			{
				left *= A[j];
			}
			//Çóright
			for (int j = i + 1; j < A.size(); j++)
			{
				right *= A[j];
			}
			res.push_back(left * right);
		}
		return res;
	}
};


//method 2:  optimization of method 1
//Time complexity: O(n)
class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> B(A.size());
		if (A.size() == 0)
		{
			return B;
		}
		B[0] = 1;
		for (int i = 1; i < B.size(); i++)
		{
			B[i] = B[i - 1] * A[i - 1];
		}
		int tmp = 1;
		for (int i = B.size() - 2; i >= 0; i--)
		{
			tmp *= A[i + 1];
			B[i] *= tmp;
		}
		return B;
	}
};

int main()
{
	return 0;
}