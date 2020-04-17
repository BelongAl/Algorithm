#include<iostream>
#include<queue>
#include<algorithm>

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
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> res;
		if (pRoot == nullptr)
		{
			return res;
		}
		queue<TreeNode*> q;
		q.push(pRoot);
		bool sign = true;
		int size = 1;
		while (!q.empty())
		{
			vector<int> tmp;
			while (size--)
			{
				TreeNode *cur = q.front();
				q.pop();
				if (cur->left != nullptr)
				{
					q.push(cur->left);
				}
				if (cur->right != nullptr)
				{
					q.push(cur->right);
				}
				tmp.push_back(cur->val);
			}

			if (!sign)
			{
				reverse(tmp.begin(), tmp.end());
			}
			res.push_back(tmp);
			size = q.size();
			sign = !sign;
		}
		return res;
	}

};