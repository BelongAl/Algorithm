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

	//�����ÿ���ڵ�Ľṹ
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
		RBTreeNode<T>* m_head;//ͷ�ڵ�

	public:
		RBTree() :
			m_head(new RBTreeNode<T>(1, BLACK))
		{}

		//���뺯��
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

			//�������ұ��
			updataBegin();
			updataEnd();

			return true;
		}

		//ɾ������
		bool erase(T val)
		{
			std::pair<bool, iterator<T>>it = find(val).second;//�ҵ�ɾ����Ԫ��λ��
			if (!it.first)
			{
				return false;
			}
			RBTreeNode<T> *grand = nullptr;
			RBTreeNode<T> *uncle = nullptr;
			RBTreeNode<T> *dad = it.second->m_data;
			getgu(dad, uncle, grand);//�������ڵ��үү�ڵ㣨ɾ���Ľڵ��ǰְ֣�



			//ɾ������
			if (dad->m_colour == BLACK)
			{
				if (dad->m_left == nullptr || dad->m_right == nullptr)
				{
					RBTreeNode<T> *path = dad->m_parent;
					LockBlackNode(path);//ȱ�ڵ���
				}
				//��Ҫ�ҵ�����ĵ�
				else
				{
					//�����������ҵ�����Ľڵ�
					++it.second;
					RBTreeNode<T> *areplace = it.second->m_data;//��̽ڵ�
					--it.second;
					--it.second;
					RBTreeNode<T> *preplace = it.second->m_data;//ǰ���ڵ�

					if (areplace->m_colour == RED || preplace->m_colour == RED)//�����������Ǻ�ɫ�ģ�ֱ���滻
					{
						if (areplace->m_colour == RED)
						{
							dad->m_val = areplace->m_val;
							if (areplace == dad->m_left)//�����̲��Ǳ�ɾ���ڵ������������ô��һ����ĳ���ڵ��������
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
							if (preplace == dad->m_left)//���ǰ���ڵ㲻�Ǳ�ɾ���ڵ������������ô��һ����ĳ���ڵ��������
							{
								dad->m_right = nullptr;
							}
							else
							{
								preplace->m_parent->m_right = nullptr;
							}
						}
					}
					//���ǰ���ڵ�ͺ�̽ڵ㶼�Ǻ�ɫ������к�ɫ����
					else
					{
						//�滻
						dad->m_val = areplace->m_val;
						RBTreeNode<T>*parent = areplace->m_parent;//��¼���滻�ڵ��·��
						if (areplace == dad->m_left)//�����̲��Ǳ�ɾ���ڵ������������ô��һ����ĳ���ڵ��������
						{
							dad->m_left = nullptr;
						}
						else
						{
							areplace->m_parent->m_left = nullptr;
						}
						//ȱ�ڵ���
						LockBlackNode(parent);
					}
			
				}

			}
			else
			{
				//�����ɾ���ڵ�����ҽڵ���1/2���ӽڵ�Ϊnullptr��ֱ��ɾ��
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
				//��Ҫ�ҵ��滻�Ľڵ�
				else
				{
					//�����������ҵ�����Ľڵ�
					++it.second;
					RBTreeNode<T> *areplace = it.second->m_data;//��̽ڵ�
					--it.second;
					--it.second;
					RBTreeNode<T> *preplace = it.second->m_data;//ǰ���ڵ�

					if (areplace->m_colour == RED || preplace->m_colour == RED)//�����������Ǻ�ɫ�ģ�ֱ���滻
					{
						if (areplace->m_colour == RED)
						{
							dad->m_val = areplace->m_val;
							if (areplace == dad->m_left)//�����̲��Ǳ�ɾ���ڵ������������ô��һ����ĳ���ڵ��������
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
							if (preplace == dad->m_left)//���ǰ���ڵ㲻�Ǳ�ɾ���ڵ������������ô��һ����ĳ���ڵ��������
							{
								dad->m_right = nullptr;
							}
							else
							{
								preplace->m_parent->m_right = nullptr;
							}
						}
					}
					//���ǰ���ڵ�ͺ�̽ڵ㶼�Ǻ�ɫ������к�ɫ����
					else
					{
						//�滻
						dad->m_val = areplace->m_val;
						RBTreeNode<T>*parent = areplace->m_parent;//��¼���滻�ڵ��·��
						if (areplace == dad->m_left)//�����̲��Ǳ�ɾ���ڵ������������ô��һ����ĳ���ڵ��������
						{
							dad->m_left = nullptr;
						}
						else
						{
							areplace->m_parent->m_left = nullptr;
						}
						//ȱ�ڵ���
						LockBlackNode(parent);
					}
				}
			}
			return true;
		}

		//ȱ�ڵ���
		void LockBlackNode(RBTreeNode<T> *path)
		{
			RBTreeNode<T>* cur = path;
			RBTreeNode<T>* pre = nullptr;

			//��Ϊ����·��ȱ����һ����ɫ�ڵ㣬������Ҫ������·����ȱ��һ���ڵ�
			//����������Ѱ��������·���ϵ���������������Щ������һ����ɫ�ڵ�Ⱦ�ɺ�ɫ��
			while (1)
			{
				if (cur->m_left && cur->m_left != pre)//�������·��������������������������һ����ɫ�ڵ���
				{
					//Ѱ�����������ĺ�ɫ�ڵ㣬��������
					ChangeColor(cur->m_left);
				}
				else if(cur->m_right && cur->m_right != pre)//�������·��������������������������һ����ɫ�ڵ���
				{
					//Ѱ�����������ĺ�ɫ�ڵ㣬��������
					ChangeColor(cur->m_right);
				}
				pre = cur;
				cur = cur->m_parent;
			}
			m_head->m_parent->m_colour = BLACK;
		}

		//Ѱ�Һ�ɫ�ڵ㣬Ȼ����õ�������
		void ChangeColor(RBTreeNode<T> *cur)
		{
			if (cur->m_colour == BLACK)
			{
				//�ҵ��˺�ɫ�ڵ㣬���е���
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
			//�ҵ������ҽڵ����ɫ
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
			
			//����ָ�����飬��������ִ���ʽ
			void((*adjust)[6])(RBTreeNode<T> *) = { Bbb,Brr,Brb,Rbb,Rrr,Rrb };

			//������׽ڵ�Ϊ��ɫ
			if (cur->m_parent->m_left == BLACK)
			{
				if (leftcolor == BLACK && rightcolor == BLACK)
				{
					//����һ
					adjust[0](cur);
				}
				else if (leftcolor == RED && rightcolor == RED)
				{
					//������
					adjust[1](cur);
				}
				else
				{
					adjust[2](cur);//������
				}
			}
			else
			{
				if (leftcolor == BLACK && rightcolor == BLACK)
				{
					adjust[4](cur);//������
				}
				else if (leftcolor == RED && rightcolor == RED)
				{
					adjust[5](cur);//������
				}
				else
				{
					adjust[6](cur);//������
				}
			}
		}

		//���ִ�����
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
		void Rbb(RBTreeNode<T> *cur)//��ִ����֮һ������ֱ���˳�
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

		//�����ǵ�����ģ�飬ʹ���ڲ���ʵ�ֵ�����
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

			iterator(const iterator&it)://��������
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

			iterator<T> operator++()//ʹ�������С����Ľ��۽���++��ÿ�μ�¼�����������ֵ
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
		
		//����
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

		//�������ڵ��үү�ڵ�
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

		//��������
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

		//��������
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

		//����
		void swap(wr::RBTreeNode<T> *&left, wr::RBTreeNode<T> *&right)
		{
			RBTreeNode<T> *tmp = left;
			left = right;
			right = tmp;
		}

		//��ȡͷͷ�ڵ�
		RBTreeNode<T>* getRoot()
		{
			return m_head->m_parent;
		}

		//����begin
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

		//����end
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
