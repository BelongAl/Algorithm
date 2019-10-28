#include<iostream>
#include<vector>
#include<stack>

using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
	  TreeNode(){}
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 public:
	 TreeNode* Buy(int x)
	 {
		 TreeNode *t = new TreeNode;
		 t->left = nullptr;
		 t->right = nullptr;
		 t->val = x;
		 return t;
	 }
 };
 
 class Solution {
 public:
	 vector<int> inorderTraversal(TreeNode* root)
	 {
		 vector<int> ans;
		 TreeNode* p = root;
		 stack<TreeNode*> st;
		 while (p || !st.empty())
		 {
			 while (p)
			 {
				 st.push(p);
				 p = p->left;
			 }
			 p = st.top();
			 st.pop();
			 ans.push_back(p->val);
			 p = p->right;
		 }
		 return ans;
	 }
 };

 
int main()
{
	TreeNode *t1 = new TreeNode;
	t1->left = nullptr;
	t1->val = 1;
	t1->right = t1->Buy(2);
	t1->right->left = t1->Buy(3);
	Solution s;
	s.inorderTraversal(t1);
	return 0;
}