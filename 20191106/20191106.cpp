#include"binaryTree.h"

#include<stack>

using namespace wr;

class Solution {
public:
	TreeNode<int>* lowestCommonAncestor(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {
		if (root == nullptr)
		{
			return nullptr;
		}
		stack<TreeNode<int>*> st;
		TreeNode<int>* cur = root;
		TreeNode<int>* sign = nullptr;
		stack<TreeNode<int>*> sp;
		stack<TreeNode<int>*> sq;
		while (cur || !st.empty())
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->m_left;
			}
			TreeNode<int>* tmp = st.top();
			if (tmp == p)
			{
				sp = st;
			}
			if (tmp == q)
			{
				sq = st;
			}
			if (tmp->m_right == nullptr || tmp->m_right == sign)
			{
				st.pop();
				sign = tmp;
			}
			else
			{
				cur = tmp->m_right;
			}
		}
		if (sp.size() < sq.size())
		{
			stack<TreeNode<int>*> d = sp;
			sp = sq;
			sq = d;
		}
		int i = sp.size() - sq.size();
		while (i--)
		{
			sp.pop();
		}
		while (!sp.empty())
		{
			if (sp.top() == sq.top())
			{
				return sp.top();
			}
			sp.pop();
			sq.pop();
		}
		return nullptr;
	}
};



int main()
{
	int arr[] = { 3,5,6,-1,-1,2,7,-1,-1,4,-1,-1,1,0,-1,- 1,8,-1,-1 };
	Tree<int> t(arr,-1);
	Solution s;
	TreeNode<int> *tr = t.Get();
	s.lowestCommonAncestor(tr,tr->m_left,tr->m_right);
	system("pause");
	return 0;
}