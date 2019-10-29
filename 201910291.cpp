#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode()
	{}
};

class Solution {
	stack<TreeNode*> s;
public:
	//method 栈的反后序遍历
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		if (root == nullptr)
		{
			return res;
		}
		s.push(root);
		while (!s.empty())
		{
			TreeNode *p = s.top();
			s.pop();
			res.push_back(p->val);
			if (nullptr != p->left)
			{
				s.push(p->left);
			}
			if (nullptr != p->right)
			{
				s.push(p->right);
			}
		}
		for (int i = 0, j = res.size() - 1; i < j; i++, j--)
		{
			int tmp = res[i];
			res[i] = res[j];
			res[j] = tmp;
		}
		return res;
	}

	//method 2 递归
	vector<int> postorderTraversal2(TreeNode *root) {
		vector<int> res;
		if (root == nullptr)
		{
			return res;
		}
		postorderTraversal(root->left);//访问左子树
		postorderTraversal(root->right);//访问右子树
		res.push_back(root->val);
		return res;
	}

	//method 3 栈的后序遍历
	vector<int> postorderTraversal3(TreeNode* root) {
		stack<TreeNode *> s;
		TreeNode *cur = root;//用来标记需要入栈的节点
		TreeNode *last = NULL;//用来标记上一个出栈的节点
		vector<int>res;
		while (cur != NULL || !s.empty()) {
			while (cur != NULL) {
				s.push(cur);
				cur = cur->left;
			}
			TreeNode *top = s.top();
			if (top->right == NULL) {
				res.push_back(top->val);
				s.pop();
				last = top;
			}
			else if (top->right == last) {
				res.push_back(top->val);
				s.pop();
				last = top;
			}
			else {
				cur = top->right;
			}
		}
		return res;
	}
};


int main()
{
	TreeNode *t1 = new TreeNode;
	TreeNode *t2 = new TreeNode;
	TreeNode *t3 = new TreeNode;
	t1->val = 1;
	t1->right = t2;
	t1->left = nullptr;
	t2->val = 2;
	t2->left = t3;
	t2->right = nullptr;
	t3->val = 3;
	t3->right = nullptr;
	t3->left = nullptr;
	Solution s;
	s.postorderTraversal3(t1);
	return 0;
}
