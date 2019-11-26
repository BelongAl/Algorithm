#pragma once

namespace wr
{
	template<class T>
	class AVL_Node
	{
		AVL_Node *m_left;
		AVL_Node *m_right;
		AVL_Node *m_parent;
		T m_val;
		int m_bav;
	public:
		AVL_Node(T val = T()) :
			m_bav(0),
			m_val(val),
			m_left(nullptr),
			m_right(nullptr),
			m_parent(nullptr)
		{}

		template<class T>
		friend class AVLtree;


	};

	template<class T>
	class AVLtree
	{
		AVL_Node<T> *m_root;

		void lrotate(AVL_Node<T> *pre)
		{
			AVL_Node<T> *parent = pre->m_parent;
			AVL_Node<T> *cur = pre->m_right;
			if(parent)
			{
				if (parent->m_left == pre)
				{
					parent->m_left = cur;
				}
				else
				{
					parent->m_right = cur;
				}
			}
			else
			{
				m_root = cur;
			}
			cur->m_parent = parent;
			pre->m_right = cur->m_left;
			if (cur->m_left)
			{
				pre->m_right->m_parent = pre;
			}
			cur->m_left = pre;
			pre->m_parent = cur;
			pre->m_bav -= 2;
			cur->m_bav -= 1;
			
		}

		void rrotate(AVL_Node<T> *pre)
		{
			AVL_Node<T> *parent = pre->m_parent;
			AVL_Node<T> *cur = pre->m_left;
			if (parent)
			{
				if (parent->m_left == pre)
				{
					parent->m_left = cur;
				}
				else
				{
					parent->m_right = cur;
				}
			}
			else
			{
				m_root = cur;
			}
			cur->m_parent = parent;
			pre->m_left = cur->m_right;
			if (cur->m_right)
			{
				pre->m_left->m_parent = pre;
			}
			cur->m_right = pre;
			pre->m_parent = cur;
			pre->m_bav += 2;
			cur->m_bav += 1;

		}

		void rlrotate(AVL_Node<T> *pre)
		{
			AVL_Node<T> *parent = pre->m_right;
			AVL_Node<T> *sun = parent->m_left;
			int tmp = sun->m_bav;
			rrotate(parent);
			lrotate(pre);
			if (tmp == 1)
			{
				pre->m_bav = -1;
			}
			else
			{
				parent->m_val = 1;
			}
		}

		void lrrotate(AVL_Node<T> *pre)
		{
			AVL_Node<T> *parent = pre->m_left;
			AVL_Node<T> *sun = parent->m_right;
			int ret = sun->m_bav;
			lrotate(parent);
			rrotate(pre);
			if (ret == 1)
			{
				parent->m_bav = -1;
			}
			else
			{
				pre->m_bav = 1;
			}
		}

	public:
		AVLtree():
			m_root(nullptr)
		{}

		bool insert(T val)
		{
			if (nullptr == m_root)
			{
				m_root = new AVL_Node<T>(val);
			}
			else
			{
				AVL_Node<T> *pre = m_root;//Before marking the insertion point
				AVL_Node<T>*cur = m_root;//mark where to insert point
				while (cur)//Find insertable point
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
						return false;
					}
				}

				cur = new AVL_Node<T>(val);//insert
				if (pre->m_val > val)
				{
					pre->m_left = cur;
					cur->m_parent = pre;
				}
				else
				{
					pre->m_right = cur;
					cur->m_parent = pre;
				}

				while (pre)
				{
					if (pre->m_left == cur)
					{
						pre->m_bav--;
					}
					else
					{
						pre->m_bav++;
					}

					if (pre->m_bav == 0)
					{
						break;
					}

					else if (pre->m_bav == 1 || pre->m_bav == -1)
					{
						cur = pre;
						pre = pre->m_parent;
					}
					else
					{
						if (pre->m_bav == 2)
						{
							if (cur->m_bav == 1)
							{
								lrotate(pre);
							}
							else
							{
								rlrotate(pre);
							}
						}
						else
						{
							if (cur->m_bav == -1)
							{
								rrotate(pre);
							}
							else
							{
								lrrotate(pre);
							}
						}
						break;
					}

				}

				return true;
			}
		}

	};
}