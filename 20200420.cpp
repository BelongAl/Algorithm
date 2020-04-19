#include<iostream>
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
public:
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (nullptr == pRoot)
		{
			return nullptr;
		}
		stack<TreeNode*> s;
		s.push(pRoot);
		int i = 0;
		bool sign = true;
		while (!s.empty())
		{
			TreeNode *top = s.top();
			while (sign && nullptr != top->left)
			{
				top = top->left;
				s.push(top);
			}

			if (nullptr != top->right)
			{
				s.pop();
				i++;
				s.push(top->right);
				sign = true;
			}
			else
			{
				s.pop();
				i++;
				sign = false;				
			}
			if (i == k)
			{
				return top;
			}
		}
		return nullptr;
	}
};

int main()
{
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	TreeNode *t4 = new TreeNode(4);
	TreeNode *t5 = new TreeNode(5);
	TreeNode *t6 = new TreeNode(6);
	TreeNode *t7 = new TreeNode(7);
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t2->right = t5;
	t3->left = t6;
	t3->right = t7;

	Solution s;
	cout << s.KthNode(t1, 3)->val << endl;

	return 0;
}