#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
	int getdepth(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return max(getdepth(root->left), getdepth(root->right)) + 1;
	}

	void looktree(TreeNode *root, int depth, int &maxdepth)
	{
		if (root == nullptr)
		{
			return;
		}
		depth++;
		if (depth > maxdepth)
		{
			maxdepth++;
			m_res.push_back(root->val);
			if (maxdepth >= m_maxdepth)
			{
				return;
			}
		}
		if (root->right)
		{
			looktree(root->right, depth, maxdepth);
		}
		if (root->left)
		{
			looktree(root->left, depth, maxdepth);
		}
	}

	vector<int> m_res;
	int m_maxdepth;

public:

	vector<int> rightSideView(TreeNode* root) {
		if (nullptr == root)
		{
			return m_res;
		}

		int leftdepth = 1;
		int rightdepth = 1;
		m_maxdepth = getdepth(root);

		int maxdepth = 0;
		looktree(root, 0, maxdepth);

		return m_res;

	}
};

int main()
{
	TreeNode *p1 = new TreeNode(1);
	TreeNode *p2 = new TreeNode(2);
	TreeNode *p3 = new TreeNode(3);
	TreeNode *p4 = new TreeNode(4);
	TreeNode *p5 = new TreeNode(5);

	p1->left = p2;
	p1->right = p3;
	p2->right = p5;
	p3->right = p4;

	Solution s;
	s.rightSideView(p1);

	return 0;
}