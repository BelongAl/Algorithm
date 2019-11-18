#include<iostream>
#include<queue>
#include"binaryTree.h"

using namespace wr;
using namespace std;

class Solution {
	TreeNode<int> *p(TreeNode<int> **root)
	{
		if (nullptr == *root)
		{
			return *root;
		}
		p(&((*root)->m_left));
		p(&((*root)->m_right));
		if ((*root)->m_val == 0 && (*root)->m_left == nullptr && (*root)->m_right == nullptr)
		{
			*root = nullptr;
		}
		return *root;
	}

public:
	TreeNode<int>* pruneTree(TreeNode<int>* root) {
		p(&root);
		return root;
	}
};

int main()
{
	int arr[] = { 1,-1,0,0,-1,-1,1,-1,-1 };
	Tree<int> t(arr, -1);
	Solution s;
	TreeNode<int> *ret = s.pruneTree(t.Get());
	system("pause");
	return 0;
}