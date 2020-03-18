#include<iostream>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
	int Dfs(TreeNode *root, int val)
	{
		if (root == nullptr)
		{
			return 0;
		}

		val = root->val;

		int leftval = Dfs(root->left, 0);
		int rightval = Dfs(root->right, 0);

		if (leftval < 0)
		{
			leftval = 0;
		}
		if (rightval < 0)
		{
			rightval = 0;
		}

		if (val + leftval + rightval > m_maxval)
		{
			m_maxval = val + leftval + rightval;
		}

		return val + (leftval < rightval ? rightval : leftval);

	}

	int m_maxval;
public:
	int maxPathSum(TreeNode* root) {
		if (root == nullptr)
		{
			return INT_MIN;
		}
		m_maxval = root->val;
		Dfs(root, 0);
		return m_maxval;
	}
};

int main()
{
	TreeNode *t1 = new TreeNode(-3);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);

	t1->left = t2;
	t1->right = t3;

	Solution s;
	s.maxPathSum(t1);

	return 0;
}