#pragma once
#include<iostream>
#include<stack>
#include<utility>


namespace wr
{
	enum COLOR
	{
		BLACK,
		RED,
		EMPTY,
	};

	//红黑树每个节点的结构
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

		bool operator==(RBTreeNode *right)
		{
			if (m_colour == right->m_colour &&
				m_val == right->m_val)
			{
				return true;
			}
			return false;
		}

		template<class T>
		friend class RBTree;

	};

	template<class T>
	class RBTree
	{
		RBTreeNode<T>* m_head;//头节点

	public:
		RBTree() :
			m_head(new RBTreeNode<T>(1, BLACK))
		{}

		//插入函数
		bool insert(T val)
		{
			RBTreeNode<T> *root = getRoot();

			if (root)
			{
				RBTreeNode<T>* pre = root;//记录当前节点的父节点
				RBTreeNode<T>* cur = root;//记录当前节点

				bool sign = true;//标记应该插在左子树还是右子树
				while (cur)//寻找插入的点
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

				cur = new RBTreeNode<T>(val);//插入
				if (sign)
				{
					pre->m_left = cur;
				}
				else
				{
					pre->m_right = cur;
				}
				cur->m_parent = pre;

				//以下为红黑树调整算法
				if (pre->m_colour == RED)
				{
					RBTreeNode<T> *grand = nullptr;
					RBTreeNode<T> *uncle = nullptr;
					getgu(pre, uncle, grand);//获得叔叔和爷爷节点

					while (pre != m_head && uncle && uncle->m_colour == RED)//如果叔叔是红色的
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
								Rrotate(grand);
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

			//更新左右标记
			updataBegin();
			updataEnd();

			return true;
		}

		//删除函数
		bool erase(T val)
		{
			std::pair<bool, iterator<T>>it = find(val).second;//找到删除的元素位置
			if (!it.first)
			{
				return false;
			}
			RBTreeNode<T> *grand = nullptr;
			RBTreeNode<T> *uncle = nullptr;
			RBTreeNode<T> *dad = it.second->m_data;
			getgu(dad, uncle, grand);//获得叔叔节点和爷爷节点（删除的节点是爸爸）



			//删除操作
			if (dad->m_colour == BLACK)
			{
				if (dad->m_left == nullptr || dad->m_right == nullptr)
				{
					RBTreeNode<T> *path = dad->m_parent;
					LockBlackNode(path);//缺黑调整
				}
				//需要找到代替的点
				else
				{
					//首先我们需找到代替的节点
					++it.second;
					RBTreeNode<T> *areplace = it.second->m_data;//后继节点
					--it.second;
					--it.second;
					RBTreeNode<T> *preplace = it.second->m_data;//前驱节点

					if (areplace->m_colour == RED || preplace->m_colour == RED)//如果被替代的是红色的，直接替换
					{
						if (areplace->m_colour == RED)
						{
							dad->m_val = areplace->m_val;
							if (areplace == dad->m_left)//如果后继不是被删除节点的左子树，那么它一定是某个节点的左子树
							{
								dad->m_left = nullptr;
							}
							else
							{
								areplace->m_parent->m_left = nullptr;
							}
						}
						else
						{
							dad->m_val = preplace->m_val;
							if (preplace == dad->m_left)//如果前驱节点不是被删除节点的右子树，那么它一定是某个节点的右子树
							{
								dad->m_right = nullptr;
							}
							else
							{
								preplace->m_parent->m_right = nullptr;
							}
						}
					}
					//如果前驱节点和后继节点都是黑色，则进行黑色调整
					else
					{
						//替换
						dad->m_val = areplace->m_val;
						RBTreeNode<T>*parent = areplace->m_parent;//记录被替换节点的路径
						if (areplace == dad->m_left)//如果后继不是被删除节点的左子树，那么它一定是某个节点的左子树
						{
							dad->m_left = nullptr;
						}
						else
						{
							areplace->m_parent->m_left = nullptr;
						}
						//缺黑调整
						LockBlackNode(parent);
					}
			
				}

			}
			else
			{
				//如果被删除节点的左右节点有1/2个子节点为nullptr，直接删除
				if (dad->m_left == nullptr || dad->m_right == nullptr)
				{
					if (grand->m_left == dad)
					{
						if (dad->m_left == nullptr)
						{
							grand->m_left = dad->m_right;
						}
						else
						{
							grand->m_left = dad->m_left;
						}
					}
					else
					{
						if (dad->m_left == nullptr)
						{
							grand->m_right = dad->m_right;
						}
						else
						{
							grand->m_right = dad->m_left;
						}
					}
				}
				//需要找到替换的节点
				else
				{
					//首先我们需找到代替的节点
					++it.second;
					RBTreeNode<T> *areplace = it.second->m_data;//后继节点
					--it.second;
					--it.second;
					RBTreeNode<T> *preplace = it.second->m_data;//前驱节点

					if (areplace->m_colour == RED || preplace->m_colour == RED)//如果被替代的是红色的，直接替换
					{
						if (areplace->m_colour == RED)
						{
							dad->m_val = areplace->m_val;
							if (areplace == dad->m_left)//如果后继不是被删除节点的左子树，那么它一定是某个节点的左子树
							{
								dad->m_left = nullptr;
							}
							else
							{
								areplace->m_parent->m_left = nullptr;
							}
						}
						else
						{
							dad->m_val = preplace->m_val;
							if (preplace == dad->m_left)//如果前驱节点不是被删除节点的右子树，那么它一定是某个节点的右子树
							{
								dad->m_right = nullptr;
							}
							else
							{
								preplace->m_parent->m_right = nullptr;
							}
						}
					}
					//如果前驱节点和后继节点都是黑色，则进行黑色调整
					else
					{
						//替换
						dad->m_val = areplace->m_val;
						RBTreeNode<T>*parent = areplace->m_parent;//记录被替换节点的路径
						if (areplace == dad->m_left)//如果后继不是被删除节点的左子树，那么它一定是某个节点的左子树
						{
							dad->m_left = nullptr;
						}
						else
						{
							areplace->m_parent->m_left = nullptr;
						}
						//缺黑调整
						LockBlackNode(parent);
					}
				}
			}
			return true;
		}

		//缺黑调整
		void LockBlackNode(RBTreeNode<T> *path)
		{
			RBTreeNode<T>* cur = path;
			RBTreeNode<T>* pre = nullptr;

			//因为这条路径缺少了一个黑色节点，所以需要将其他路径均缺少一个节点
			//我们在这里寻找他这条路径上的所有子树，将这些子树的一个黑色节点染成红色。
			while (1)
			{
				if (cur->m_left && cur->m_left != pre)//如果这条路径存在左子树，则将其左子树的一个黑色节点变红
				{
					//寻找其左子树的黑色节点，并将其变红
					ChangeColor(cur->m_left);
				}
				else if(cur->m_right && cur->m_right != pre)//如果这条路径存在右子树，则将其右子树的一个黑色节点变红
				{
					//寻找其右子树的黑色节点，并将其变红
					ChangeColor(cur->m_right);
				}
				pre = cur;
				cur = cur->m_parent;
			}
			m_head->m_parent->m_colour = BLACK;
		}

		//寻找黑色节点，然后调用调整函数
		void ChangeColor(RBTreeNode<T> *cur)
		{
			if (cur->m_colour == BLACK)
			{
				//找到了黑色节点，进行调整
				cur->m_colour = RED;
				AdjustColor(cur);
				return;
			}
			else
			{
				if (cur->m_left)
				{
					ChangeColor(cur->m_left);
				}
				if (cur->m_right)
				{
					ChangeColor(cur->m_right);
				}
			}
		}

		void AdjustColor(RBTreeNode<T> *cur)
		{
			//找到其左右节点的颜色
			COLOR leftcolor = BLACK;
			COLOR rightcolor = BLACK;
			if (cur->m_left->m_colour == RED)
			{
				leftcolor = RED;
			}
			if (cur->m_right->m_colour == RED)
			{
				rightcolor = RED;
			}
			
			//函数指针数组，存放这六种处理方式
			void((*adjust)[6])(RBTreeNode<T> *) = { Bbb,Brr,Brb,Rbb,Rrr,Rrb };

			//如果父亲节点为黑色
			if (cur->m_parent->m_left == BLACK)
			{
				if (leftcolor == BLACK && rightcolor == BLACK)
				{
					//方法一
					adjust[0](cur);
				}
				else if (leftcolor == RED && rightcolor == RED)
				{
					//方法二
					adjust[1](cur);
				}
				else
				{
					adjust[2](cur);//方法三
				}
			}
			else
			{
				if (leftcolor == BLACK && rightcolor == BLACK)
				{
					adjust[4](cur);//方法四
				}
				else if (leftcolor == RED && rightcolor == RED)
				{
					adjust[5](cur);//方法五
				}
				else
				{
					adjust[6](cur);//方法六
				}
			}
		}

		//六种处理函数
		void Bbb(RBTreeNode<T> *cur)
		{}
		void Brr(RBTreeNode<T> *cur)
		{
			if (cur->m_parent->m_left = cur)
			{
				Lrotate(cur);
				cur = cur->m_parent;
				Rrotate(cur->m_parent);
				cur->m_left->m_colour = BLACK;
			}
			else
			{
				Rrotate(cur);
				cur = cur->m_parent;
				Lrotate(cur->m_parent);
				cur->m_right->m_colour= BLACK;
			}
			if (cur->m_parent != m_head && cur->m_parent->m_colour == RED)
			{
				Rbb(cur);
			}
		}
		void Brb(RBTreeNode<T> *cur)
		{
			if (cur->m_parent->m_left = cur)
			{
				Lrotate(cur);
				cur = cur->m_parent;
				Rrotate(cur->m_parent);
				cur->m_left->m_colour = BLACK;
			}
			else
			{
				Rrotate(cur);
				cur = cur->m_parent;
				Lrotate(cur->m_parent);
				cur->m_right->m_colour = BLACK;
			}
			if (cur->m_parent != m_head && cur->m_parent->m_colour == RED)
			{
				Rbb(cur);
			}
		}
		void Rbb(RBTreeNode<T> *cur)//若执行了之一步可以直接退出
		{
			cur->m_parent = BLACK;
		}
		void Rrr(RBTreeNode<T> *cur)
		{
			cur->m_parent = BLACK;
			Brr(cur);
		}
		void Rrb(RBTreeNode<T> *cur)
		{
			if (cur = cur->m_parent->m_left)
			{
				Lrotate(cur);
				cur = cur->m_parent;
				Rrotate(cur->m_parent);
				Brr(cur);
			}
			else
			{
				Rrotate(cur);
				cur = cur->m_parent;
				Lrotate(cur->m_parent);
				Brr(cur);
			}
		}

		//以下是迭代器模块，使用内部类实现迭代器
		template<class T>
		class iterator
		{
		public:

			RBTreeNode<T> *m_data;
			RBTreeNode<T> *m_ithead;
			T m_max;

			iterator(RBTreeNode<T> *data, RBTreeNode<T> *ithead):
				m_data(data),
				m_max(data->m_val),
				m_ithead(ithead)
			{}

			iterator(const iterator&it)://拷贝构造
				m_data(it.m_data),
				m_ithead(it.m_ithead),
				m_max(it.m_max)
			{}

			T& operator*()
			{
				return m_data->m_val;
			}

			T* operator->()
			{
				return &m_data->m_val;
			}

			iterator<T> operator++()//使用中序从小到大的结论进行++，每次记录遍历过的最大值
			{

				if (m_data == m_ithead->m_right)
				{
					m_data = m_ithead;
					return *this;
				}
				if (m_data->m_right && m_data->m_right->m_val > m_max)
				{
					m_data = m_data->m_right;
					while (m_data->m_left)
					{
						m_data = m_data->m_left;
					}
					m_max = m_data->m_val;
					return *this;
				}
				while(m_data->m_parent != m_ithead && m_data->m_val <= m_max)
				{
					m_data = m_data->m_parent;
				}
				m_max = m_data->m_val;
				return *this;
			}

			iterator<T> operator++(int)
			{
				iterator<T> tmp(*this);
				++(*this);
				return tmp;
			}

			iterator<T> operator--()
			{

				if (m_data == m_ithead->m_left)
				{
					std::cout << "cross boundary" << std::endl;
					return *this;
				}
				if (m_data->m_left && m_data->m_left->m_val < m_max)
				{
					m_data = m_data->m_left;
					while (m_data->m_right)
					{
						m_data = m_data->m_right;
					}
					m_max = m_data->m_val;
					return *this;
				}
				while (m_data->m_parent != m_ithead && m_data->m_val >= m_max)
				{
					m_data = m_data->m_parent;
				}
				m_max = m_data->m_val;
				return *this;
			}

			iterator<T> operator--(int)
			{
				iterator<T> tmp(*this);
				--(*this);
				return tmp;
			}

			bool operator==(iterator<T> &right)
			{
				return m_data->m_val == right.m_data->m_val;
			}

			bool operator!=(iterator<T> &right)
			{
				return !(*this == right);
			}

			bool operator<(iterator<T> &right)
			{
				return m_data->m_val < right.m_data->m_val;
			}

			bool operator>(iterator<T> &right)
			{
				return m_data->m_val > right->m_data->m_val;
			}

			T getval()
			{
				return m_data->m_val;
			}

		};
		
		//查找
		std::pair<bool,iterator<T>> find(T val)
		{
			iterator<T> it(m_head->m_left, m_head);
			while (it.m_data != m_head->m_right)
			{
				if (it.getval() == val)
				{
					return std::make_pair(true, it);
				}
				++it;
			}
			return std::make_pair(false, it);
		}

		iterator<T> begin()
		{
			return iterator<T>(m_head->m_left, m_head);
		}

		iterator<T> end()
		{
			return iterator<T>(m_head, m_head);
		}

	private:

		//获得叔叔节点和爷爷节点
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

		//右旋函数
		void Rrotate(RBTreeNode<T> *root)
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

		//左旋函数
		void Lrotate(wr::RBTreeNode<T> *root)
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

		//交换
		void swap(wr::RBTreeNode<T> *&left, wr::RBTreeNode<T> *&right)
		{
			RBTreeNode<T> *tmp = left;
			left = right;
			right = tmp;
		}

		//获取头头节点
		RBTreeNode<T>* getRoot()
		{
			return m_head->m_parent;
		}

		//更新begin
		void updataBegin()
		{
			RBTreeNode<T> *tmp = m_head->m_left;
			if (nullptr == m_head->m_left)
			{
				tmp = m_head->m_parent;
				while (tmp)
				{
					m_head->m_left = tmp;
					tmp = tmp->m_left;
				}
			}
			else
			{
				while (tmp->m_left)
				{
					tmp = tmp->m_left;
				}
				m_head->m_left = tmp;
			}
		}

		//更新end
		void updataEnd()
		{
			RBTreeNode<T> *tmp = m_head->m_right;
			if (nullptr == m_head->m_right)
			{
				tmp = m_head->m_parent;
				while (tmp)
				{
					m_head->m_right = tmp;
					tmp = tmp->m_right;
				}
			}
			else
			{
				while (tmp->m_right)
				{
					tmp = tmp->m_right; 
				}
				m_head->m_right = tmp;
			}
		}

	};

}
