#pragma once
#include<vector>
#include<stack>

using namespace std;

namespace wr
{
	template<class T>
	class TreeNode
	{
		T m_val;
		TreeNode *m_left;
		TreeNode *m_right;
	public:
		TreeNode(T val) :
			m_val(val),
			m_left(nullptr),
			m_right(nullptr)
		{}

		template<class T>
		friend class binSortTree;
	};

	template<class T>
	class binSortTree
	{
		TreeNode<T> *m_root;
	public:
		binSortTree() :
			m_root(nullptr)
		{}

		bool insert(T val)
		{
			if (m_root == nullptr)//If m_root is equal to null
			{
				m_root = new TreeNode<T>(val);
				return true;
			}
			TreeNode<T> *pre = m_root;
			TreeNode<T> *cur = m_root;
			while (cur)//Find the point to insert
			{
				if (cur->m_val > val)//Vale is smaller
				{
					pre = cur;
					cur = cur->m_left;
				}
				else if (cur->m_val < val)//Vale is biger
				{
					pre = cur;
					cur = cur->m_right;
				}
				else//If the point to be iserted aleardy exit 
				{
					return false;
				}
			}
			cur = new TreeNode<T>(val);//insert
			if (val < pre->m_val)
			{
				pre->m_left = cur;
			}
			else
			{
				pre->m_right = cur;
			}
			return true;
		}

		bool erase(T val)
		{
			//Find this vale
			TreeNode<T> *pre = m_root;//Mark the previous
			TreeNode<T> *cur = m_root;//Mark vale to delte
			while (cur)
			{
				if (cur->m_val > val)
				{
					pre = cur;
					cur = cur->m_left;
				}
				else if (cur->m_val < val)
				{
					pre = cur;
					cur = cur->m_right;
				}
				else
				{
					break;
				}
			}
			if (cur == nullptr)//the value does not exist
			{
				return false;
			}

			if (cur->m_left && cur->m_right)//if left and right nodes exist
			{
				TreeNode<T> *pre2 = cur;//previous value
				TreeNode<T> *cur2 = cur->m_left;//replace value
				if (cur2->m_right)
				{
					while (cur2->m_right)//find the replace value
					{
						pre2 = cur2;
						cur2 = cur2->m_right;
					}
					pre2->m_right = cur2->m_left;
					cur2->m_left = cur->m_left;
				}
				cur2->m_right = cur->m_right;
				if (pre == cur)
				{
					m_root = cur2;
				}
				else
				{
					if (pre->m_val > val)
					{
						pre->m_left = cur2;
					}
					else
					{
						pre->m_right = cur2;
					}
				}
			}
			else if (cur->m_left)//Only the left nodes exit
			{
				if (cur == pre)
				{
					m_root = m_root->m_left;
				}
				else
				{
					if (pre->m_val > val)
					{
						pre->m_left = cur->m_left;
					}
					else
					{
						pre->m_right = cur->m_left;
					}
				}
			}
			else//Only the right nodes exit or left and right nodes do oot esist
			{
				if (pre == cur)
				{
					m_root = m_root->m_right;
				}
				else
				{
					if (pre->m_val > val)
					{
						pre->m_left = cur->m_right;
					}
					else
					{
						pre->m_right = cur->m_right;
					}
				}
			}
			delete cur;
		}

		vector<T> inorder()
		{
			vector<T> v;
			stack<TreeNode<T>*> s;
			TreeNode<T>* cur = m_root;
			while (cur || !s.empty())
			{
				while (cur)
				{
					s.push(cur);
					cur = cur->m_left;
				}
				TreeNode<T> *tmp = s.top();
				s.pop();
				if (tmp)
				{
					v.push_back(tmp->m_val);
					cur = tmp->m_right;
				}
			}
			return v;
		}

	};

}