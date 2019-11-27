#include<iostream>
#include<vector>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

using namespace std;
class Solution {
	TreeNode* extablish(vector<int> pre, vector<int> vin, int left, int right, int &k)
	{
		if (right <= left)
		{
			return nullptr;
		}
		TreeNode *root = new TreeNode(pre[k++]);
		int i;
		for (i = left; i < right; i++)
		{
			if (root->val == vin[i])
			{
				break;
			}
		}
		root->left = extablish(pre, vin, left, i, k);
		root->right = extablish(pre, vin, i + 1, right, k);
		return root;
	}
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0)
		{
			return nullptr;
		}
		else
		{
			int k = 0;
			TreeNode *root = new TreeNode(pre[k++]);
			unsigned long j = 0;
			for (j = 0; j < vin.size(); j++)
			{
				if (pre[0] == vin[j])
				{
					break;
				}
			}
			root->left = extablish(pre, vin, 0, j, k);
			root->right = extablish(pre, vin, j + 1, vin.size(), k);
			return root;
		}
	}
};

