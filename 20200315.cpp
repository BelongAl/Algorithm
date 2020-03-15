#include<iostream>
#include<stack>
#include<vector>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
	void recoverTree(TreeNode* root) {

		if (root == nullptr)
		{
			return;
		}

		stack<TreeNode*> s;
		s.push(root);
		vector<TreeNode*> val;
		bool sign = true;

		while (!s.empty())
		{
			TreeNode *cur = s.top();
			while (sign && cur->left)
			{
				cur = cur->left;
				s.push(cur);
			}

			val.push_back(cur);
			s.pop();

			if (cur->right)
			{
				s.push(cur->right);
				sign = true;
			}
			else
			{
				sign = false;
			}
		}

		for (int i = 0; i < val.size(); i++)
		{
			for (int j = val.size() - 1; j > i; j--)
			{
				if (val[j]->val < val[i]->val)
				{
					swap(val[j]->val, val[i]->val);
					return;
				}
			}
		}

	}
};


int main()
{
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(3);
	TreeNode *t3 = new TreeNode(2);

	t1->left = t2;
	t2->right = t3;

	Solution s;
	s.recoverTree(t1);

	return 0;
}