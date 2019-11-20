#pragma once

namespace wr
{

	template <class T>
	class TreeNode
	{
		T m_data;
		TreeNode<T> *m_left;
		TreeNode<T> *m_right;
	public:
		TreeNode(const T& val = T()) :
			m_data(val),
			m_left(nullptr),
			m_right(nullptr)
		{}

		template<class T>//给模板类设置友元
		friend class BinarySortTree;
	};

	template <class T>
	class BinarySortTree
	{
		TreeNode<T> *m_root;
	public:
		BinarySortTree() :
			m_root(nullptr)
		{}

		bool insert(const T &val)
		{
			if (m_root == nullptr)
			{
				m_root = new TreeNode<T>(val);
				return true;
			}

			TreeNode<T> *cur = m_root;
			TreeNode<T> *pre = nullptr;

			while (cur)
			{
				if (val < cur->m_data)
				{
					pre = cur;
					cur = cur->m_left;
				}
				else if (val > cur->m_data)
				{
					pre = cur;
					cur = cur->m_right;
				}
				else
				{
					return false;
				}
			}

			cur = new TreeNode<T>(val);
			if (val < pre->m_data)
			{
				pre->m_left = cur;
			}
			else
			{
				pre->m_right = cur;
			}

			return true;
		}

		bool erase(const T &val)
		{
			if (m_root == nullptr)
			{
				return false;
			}

			TreeNode<T> *cur = m_root;//标记需要删除的元素
			TreeNode<T> *pre = nullptr;//标记需要删除元素的父亲

			while (cur)//查找需要删除的元素
			{
				if (val < cur->m_data)
				{
					pre = cur;
					cur = cur->m_left;
				}
				else if (val > cur->m_data)
				{
					pre = cur;
					cur = cur->m_right;
				}
				else
				{
					break;
				}
			}

			if (cur == nullptr)//若不存在
			{
				return false;
			}

			if (cur->m_left && cur->m_right)//需要删除的元素其左右子树都有元素
			{
				TreeNode<T> *cur2 = cur->m_left;//找到进位的元素
				TreeNode<T> *pre2 = cur;//标记需要进位的元素上一个元素
				while (cur2->m_right)
				{
					pre2 = cur2;
					cur2 = cur2->m_right;
				}
				if (cur->m_left == cur2)//需要进位的元素就是删除元素的直接左子树
				{
					if (pre->m_data > val)
					{
						pre->m_left = cur2;
					}
					else
					{
						pre->m_right = cur2;
					}
				}
				else//需要进位的元素是需要删除元素的左子树中的最大值
				{
					pre2->m_right = cur2->m_left;
					if (pre->m_data > val)
					{
						pre->m_left = cur2;
					}
					else
					{
						pre->m_right = cur2;
					}
					cur2->m_left = cur->m_left;
					cur2->m_right = cur->m_right;
				}
			}
			else if (cur->m_left)//需要删除的元素只有左子树上有元素
			{
				if (pre->m_data > val)
				{
					pre->m_left = cur->m_left;
				}
				else
				{
					pre->m_right = cur->m_left;
				}
			}
			else//需要删除的元素只有在右子树上有元素或两个子树均没有元素
			{
				if (pre->m_data > val)
				{
					pre->m_left = cur->m_right;
				}
				else
				{
					pre->m_right = cur->m_right;
				}
			}
			delete cur;
			cur = nullptr;
			return true;
		}
	};

}