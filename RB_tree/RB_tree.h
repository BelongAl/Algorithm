#pragma once

namespace wr
{
	enum Clour
	{
		RED,
		BLACK
	};

	template<class T>
	class rbTreeNode
	{
		T m_data;
		rbTreeNode<T> * m_left;
		rbTreeNode<T> * m_right;
		rbTreeNode<T> * m_parent;
		Clour m_clour;
	public:
		rbTreeNode(const T val = T(), Clour clour = RED) :
			m_data(val),
			m_left(nullptr),
			m_right(nullptr),
			m_parent(nullptr),
			m_clour(clour)
		{

		}

		template <class T>
		friend class RBTree;

	};

	template<class T>
	class RBTree
	{
		rbTreeNode<T> *m_head;

		rbTreeNode<T> *getroot()
		{
			return m_head->m_parent;
		}

		void rrotate(rbTreeNode<T>* cur)//右旋
		{
			rbTreeNode<T> *pre = cur->m_left;
			rbTreeNode<T> *parent = cur->m_parent;
			if (parent->m_left == cur)
			{
				parent->m_left = pre;
			}
			else
			{
				parent->m_right = pre;
			}
			pre->m_parent = parent;
			cur->m_left = pre->m_right;
			if (cur->m_left)
			{
				cur->m_left->m_parent = cur;
			}
			pre->m_right = cur;
			cur->m_parent = pre;
		}

		void lrotate(rbTreeNode<T>* cur)//左旋
		{
			rbTreeNode<T> *pre = cur->m_right;
			rbTreeNode<T> *parent = cur->m_parent;
			if (parent != m_head)
			{
				if (parent->m_left == cur)
				{
					parent->m_left = pre;
				}
				else
				{
					parent->m_right = pre;
				}
			}
			else
			{
				parent->m_parent = pre;
			}
			pre->m_parent = parent;
			cur->m_right = pre->m_left;
			if (cur->m_right)
			{
				cur->m_right->m_parent = cur;
			}
			pre->m_left = cur;
			cur->m_parent = pre;
		}

	public:
		
		RBTree()
		{
			m_head = new rbTreeNode<T>;
		}

		bool insert(T val)
		{
			rbTreeNode<T> *root = getroot();
			if(root)//若根节点存在
			{
				rbTreeNode<T> *pre = root;
				rbTreeNode<T> *cur = root;
				while (pre)//寻找插入的点
				{
					cur = pre;
					if (val > pre->m_data)
					{
						pre = pre->m_right;
					}
					else if(val < pre->m_data)
					{
						pre = pre->m_left;
					}
					else
					{
						return false;
					}
				}
				pre = new rbTreeNode<T>(val, RED);
				if (val < cur->m_data)
				{
					cur->m_left = pre;
				}
				else
				{
					cur->m_right = pre;
				}

				pre->m_parent = cur;

				//插入完毕，下面位红黑树调整

				if(cur->m_clour == RED)
				{

					rbTreeNode<T> *ground = cur->m_parent;
					rbTreeNode<T> *uncle;

					if (cur == ground->m_left)
					{
						while (cur != m_head && cur->m_clour == RED)
						{
							ground = cur->m_parent;
							uncle = ground->m_right;

							if (uncle && uncle->m_clour == RED)
							{
								cur->m_clour = BLACK;
								uncle->m_clour = BLACK;
								ground->m_clour = RED;

								pre = ground;
								cur = pre->m_parent;
							}
							else
							{
								if (pre == cur->m_right)
								{
									lrotate(cur);
									rbTreeNode<T> *ptmp = cur;
									cur = pre;
									pre = ptmp;
								}
								rrotate(ground);
								pre->m_clour = BLACK;
								ground->m_clour = RED;
								break;
							}
						}
					}
					else
					{
						while (cur != m_head && cur->m_clour == RED)
						{
							ground = cur->m_parent;
							uncle = ground->m_left;

							if (uncle && uncle->m_clour == RED)
							{
								cur->m_clour = BLACK;
								uncle->m_clour = BLACK;
								ground->m_clour = RED;

								pre = ground;
								cur = pre->m_parent;
							}
							else
							{
								if (pre == cur->m_left)
								{
									rrotate(cur);
									rbTreeNode<T> *ptmp = cur;
									cur = pre;
									pre = ptmp;
								}
								lrotate(ground);
								cur->m_clour = BLACK;
								ground->m_clour = RED;
								break;
							}
						}
					}
				}
			}
			else//根节点不存在，直接创建
			{
				root = new rbTreeNode<T>(val, BLACK);
				root->m_parent = m_head;
				m_head->m_parent = root;
			}

			m_head->m_parent->m_clour = BLACK;
			return true;

		}

	};

}