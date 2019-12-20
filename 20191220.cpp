#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
	bool subest(vector<int> A, vector<int> B)
	{
		for (int i = 0; i < A.size(); i++)
		{
			int j = 0;
			int k = i;
			while (A[k] == B[j])
			{
				j++;
				k++;
				if (j == B.size())
				{
					return true;
				}
			}
		}
		return false;
	}
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr || pRoot2 == nullptr)
		{
			return false;
		}
		vector<int> B;
		vector<int> A;
		stack<TreeNode*> Bs;
		stack<TreeNode*> As;
		Bs.push(pRoot2);
		As.push(pRoot1);
		 while(!Bs.empty())
		 {
			 TreeNode *top = Bs.top();
			 Bs.pop();
			 B.push_back(top->val);
			 if(top->right)
			 {
				 Bs.push(top->right);
			 }
			 if(top->left)
			 {
				 Bs.push(top->left);
			 }
		 }
		 while(!As.empty())
		 {
			 TreeNode *top = As.top();
			 As.pop();
			 A.push_back(top->val);
			 if(top->right)
			 {
				 As.push(top->right);
			 }
			 if(top->left)
			 {
				 As.push(top->left);
			 }
		 }
		return subest(A, B);
	}
};

int main()
{
	TreeNode *pa1 = new TreeNode(1);
	TreeNode *pa2 = new TreeNode(2);
	TreeNode *pa3 = new TreeNode(3);
	TreeNode *pa4 = new TreeNode(4);
	TreeNode *pa5 = new TreeNode(5);
	TreeNode *pa6 = new TreeNode(6);

	pa1->left = pa2;
	pa1->right = pa3;
	pa2->left = pa4;
	pa2->right = pa5;
	pa3->left = pa6;

	TreeNode *pb1 = new TreeNode(2);
	TreeNode *pb2 = new TreeNode(4);
	TreeNode *pb3 = new TreeNode(5);

	pb1->left = pb2;
	pb1->right = pb3;

	Solution s;
	cout << s.HasSubtree(pa1, pa2) << endl;
	system("pause");
	return 0;
}