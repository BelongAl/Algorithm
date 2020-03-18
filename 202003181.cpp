#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
	int GetTreeDepth(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return 1 + max(GetTreeDepth(root->left), GetTreeDepth(root->right));
	}

public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res(GetTreeDepth(root), vector<int>());
		if (root == nullptr)
		{
			return res;
		}

		queue<TreeNode*> qt;
		bool sign = false;//true代表从左往右，false代表从右往
		int i = 1;//用来记录当前层的数量
		int j = 0;//用来表示应该放在哪里
		qt.push(root);

		while (!qt.empty())
		{
			TreeNode *toproot = qt.front();
			qt.pop();
			res[j].push_back(toproot->val);
			if (toproot->left)
			{
				qt.push(toproot->left);
			}
			if (toproot->right)
			{
				qt.push(toproot->right);
			}
			i--;
			if (i == 0)
			{
				i = qt.size();
				if (sign)
				{
					reverse(res[j].begin(), res[j].end());
				}
				sign = !sign;
				j++;
			}
		}

		return res;
	}
};

int main()
{
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	TreeNode *t4 = new TreeNode(4);
	TreeNode *t5 = new TreeNode(5);

	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t3->right = t5;

	Solution s;
	s.zigzagLevelOrder(t1);

	return 0;
}