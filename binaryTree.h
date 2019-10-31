#pragma once
#include<iostream>

using namespace std;

namespace wr
{

	template <class T>
	class TreeNode
	{
		T m_val;
		TreeNode *m_left;
		TreeNode *m_right;
	public:
		TreeNode(const T &val) :
			m_val(val)
		{}

		template <class T>
		friend class Tree;
	};

	template <class T>
	class Tree
	{
		TreeNode<T> * m_root;
		static TreeNode<T>*maketree(TreeNode<T>*root, const T*val, const T& end, int & i)
		{
			if (val[i] == end)
			{
				i++;
				return nullptr;
			}
			root= new TreeNode<T>(val[i]);
			i++;
			root->m_left = maketree(root->m_left, val, end, i);
			root->m_right = maketree(root->m_right, val, end, i);
			return root;
		}
	public:
		Tree():
			m_root(nullptr)
		{}

		Tree(const T*val, const T & end)
		{
			int i = 0;
			m_root = maketree(m_root, val, end, i);
		}
	};
}