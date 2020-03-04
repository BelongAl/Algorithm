#pragma once

namespace wr
{
	enum COLOR
	{
		BLACK,
		RED,
	};

	template<class T>
	class RBTreeNode
	{
		COLOR m_colour;
		T m_val;
		RBTreeNode<T> *m_left;
		RBTreeNode<T> *m_right;
		RBTreeNode<T> *m_parent;

	public:

		RBTreeNode(T val = T(), COLOR color = RED) :
			m_left(nullptr),
			m_right(nullptr),
			m_parent(nullptr),
			m_colour(color),
			m_val(val)
		{}


		template<class T>
		friend class RBTree;

	};

	template<class T>
	class RBTree
	{
		RBTreeNode<T>* m_head;
	public:

		bool insert(T val)
		{
			RBTreeNode<T> *root = getRoot();

			if (root)
			{
				RBTreeNode<T>* pre = root;//��¼��ǰ�ڵ�ĸ��ڵ�
				RBTreeNode<T>* cur = root;//��¼��ǰ�ڵ�

				bool sign = true;//���Ӧ�ò�������������������
				while (cur)//Ѱ�Ҳ���ĵ�
				{
					pre = cur;
					if (cur->m_val > val)
					{
						cur = cur->m_left;
						sign = true;
					}
					else if (cur->m_val < val)
					{
						cur = cur->m_right;
						sign = false;
					}
					else
					{
						return false;
					}
				}

				cur = new RBTreeNode<T>(val);//����
				if (sign)
				{
					pre->m_left = cur;
				}
				else
				{
					pre->m_right = cur;
				}
				cur->m_parent = pre;

				//����Ϊ����������㷨
				if (pre->m_colour == RED)
				{
					RBTreeNode<T> *grand = nullptr;
					RBTreeNode<T> *uncle = nullptr;
					getgu(pre, uncle, grand);//��������үү�ڵ�

					while (pre != m_head && uncle && uncle->m_colour == RED)//��������Ǻ�ɫ��
					{
						pre->m_colour = BLACK;
						uncle->m_colour = BLACK;
						grand->m_colour = RED;

						cur = grand;
						pre = cur->m_parent;
						if (pre->m_colour == BLACK)
						{
							break;
						}
						getgu(pre, uncle, grand);
					}

					if (pre->m_colour == RED)
					{
						if (pre == grand->m_left)
						{
							if (cur == pre->m_left)
							{
								Lrotate(grand);
							}
							else
							{
								Lrotate(pre);
								swap(pre, cur);
								Rrotate(grand);
							}
						}
						else
						{
							if (cur == pre->m_right)
							{
								Lrotate(grand);
							}
							else
							{
								Rrotate(pre);
								swap(pre, cur);
								Lrotate(grand);
							}
						}
						pre->m_colour = BLACK;
						grand->m_colour = RED;
					}

				}

			}
			else
			{
				root = new RBTreeNode<T>(val, wr::BLACK);
				m_head->m_parent = root;
				root->m_parent = m_head;
			}
			m_head->m_parent->m_parent = m_head;
			m_head->m_parent->m_colour = BLACK;
			return true;
		}

		RBTree():
			m_head(new RBTreeNode<T>(1,BLACK))
		{}

	private:

		void getgu(wr::RBTreeNode<T> *pre, wr::RBTreeNode<T> *&uncle, wr::RBTreeNode<T> *&grand)
		{
			grand = pre->m_parent;
			if (pre == grand->m_left)
			{
				uncle = grand->m_right;
			}
			else
			{
				uncle = grand->m_left;
			}
		}


		void Rrotate(RBTreeNode<T> *root)//��������
		{
			RBTreeNode<T> *grand = root->m_parent;
			RBTreeNode<T> *sun = root->m_left;
			if (grand != m_head)
			{
				if (grand->m_left == root)
				{
					grand->m_left = sun;
				}
				else
				{
					grand->m_right = sun;
				}
			}
			else
			{
				grand->m_parent = sun;
			}
			sun->m_parent = grand;
			if (sun->m_right)
			{
				root->m_left = sun->m_right;
				sun->m_right->m_parent = root;
			}
			else
			{
				root->m_left = nullptr;
			}
			sun->m_right = root;
			root->m_parent = sun;
		}

		void Lrotate(wr::RBTreeNode<T> *root)//��������
		{
			RBTreeNode<T> *grand = root->m_parent;
			RBTreeNode<T> *sun = root->m_right;
			if (grand != m_head)
			{
				if (grand->m_left == root)
				{
					grand->m_left = sun;
				}
				else
				{
					grand->m_right = sun;
				}
			}
			else
			{
				grand->m_parent = sun;
			}
			sun->m_parent = grand;
			if (sun->m_left)
			{
				root->m_right = sun->m_left;
				sun->m_left->m_parent = root;
			}
			else
			{
				root->m_right = nullptr;
			}
			sun->m_left = root;
			root->m_parent = sun;
		}


		void swap(wr::RBTreeNode<T> *&left, wr::RBTreeNode<T> *&right)
		{
			RBTreeNode<T> *tmp = left;
			left = right;
			right = tmp;
		}


		RBTreeNode<T>* getRoot()
		{
			return m_head->m_parent;
		}

	};


}