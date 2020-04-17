#include<iostream>
#include<queue>

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
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
		{
			return true;
		}
		queue<TreeNode*> q;
		q.push(pRoot);
		int i = 1;
		while (!q.empty())
		{
			vector<TreeNode*> tmp;
			while (!q.empty())
			{
				tmp.push_back(q.front());
				q.pop();
			}
			if (tmp.size() % 2 == 1 && tmp.size() != 1)
			{
				return false;
			}
			int border = tmp.size() / 2;
			for (int i = 0, j = tmp.size() - 1; i < border, j >= border; i++, j--)
			{
				if (tmp[i]->left == nullptr || tmp[j]->right == nullptr)
				{
					if (tmp[i]->left == nullptr && tmp[j]->right == nullptr)
					{}
					else
					{
						return false;
					}
				}
				else if(tmp[i]->left->val != tmp[j]->right->val)
				{
					return false;
				}
				if (tmp[i]->right == nullptr || tmp[j]->left == nullptr)
				{
					if (tmp[i]->right == nullptr && tmp[j]->left == nullptr)
					{}
					else
					{
						return false;
					}
				}
				else if (tmp[i]->right->val != tmp[j]->left->val)
				{
					return false;
				}
			}
			for (int i = 0; i < tmp.size(); i++)
			{
				if (tmp[i]->left)
				{
					q.push(tmp[i]->left);
				}
				if (tmp[i]->right)
				{
					q.push(tmp[i]->right);
				}
			}
		}
		return true;
	}

};