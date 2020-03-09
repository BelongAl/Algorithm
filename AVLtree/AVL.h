#pragma once

template<class T>
class AVLtreeNode
{
	T m_val;
	AVLtreeNode *m_left;
	AVLtreeNode *m_right;
	AVLtreeNode *m_parent;
	int m_balance;
	
	AVLtreeNode(T val = T()):
		m_val(val),
		m_left(nullptr),
		m_right(nullptr),
		m_parent(nullptr),
		m_balance(0)
	{}

	template<class T>
	friend class AVLtree;

};

template<class T>
class AVLtree
{
	AVLtreeNode<T> *m_head;

public:

	AVLtree(T val = T()):
		m_head(new AVLtreeNode<T>(val))
	{}

	~AVLtree()
	{


	}

	//插入函数
	bool insert(T val)
	{
		AVLtreeNode<T> *cur = m_head;
		AVLtreeNode<T> *pre = m_head;

		while (cur)//找到插入的点
		{
			pre = cur;
			if (val > cur->m_val)
			{
				cur = cur->m_right;
			}
			else if (val < cur->m_val)
			{
				cur = cur->m_left;
			}
			else
			{
				return false;
			}
		}
		cur = new AVLtreeNode<T>(val);

		//插入
		if (val > pre->m_val)
		{
			pre->m_right = cur;
		}
		else
		{
			pre->m_left = cur;
		}
		cur->m_parent = pre;

		//调整平衡因子
		AdjustBlance(cur, pre);

	}

	bool erase(T val)
	{
		AVLtreeNode<T> *cur = m_head;
		AVLtreeNode<T> *pre = m_head;

		while (cur)//找到插入的点
		{
			pre = cur;
			if (val > cur->m_val)
			{
				cur = cur->m_right;
			}
			else if (val < cur->m_val)
			{
				cur = cur->m_left;
			}
			else
			{
				//找到了删除的位置
				break;
			}
		}
		if (cur == nullptr)
		{
			return false;//没有找到
		}

		//平衡点调整

	}

private:

	void AdjustBlance(AVLtreeNode<T> *cur, AVLtreeNode<T> *pre)//pre:爷爷 cur：父亲 sun： 儿子
	{
		AVLtreeNode<T> *sun = nullptr;
		while (cur != m_head)
		{
			if (cur == pre->m_left)
			{
				pre->m_balance--;
			}
			else
			{
				pre->m_balance++;
			}

			//如果不平衡就调节，调节之后不需要增加
			if (pre->m_balance == 2)//左旋后平衡直接退出
			{
				if (sun == cur->m_left)
				{
					Rrotate(cur, sun);//右旋
					Lrotate(pre, sun);//左旋
				}
				else
				{
					Lrotate(pre, cur);//左旋
				}
				break;
			}
			else if(pre->m_balance == -2)//右旋后平衡，直接退出
			{
				if (sun == cur->m_right)
				{
					Lrotate(cur, sun);//左旋
					Rrotate(pre, sun);//右旋
				}
				else
				{
					Rrotate(pre, cur);//右旋
				}
				break;
			}
			else if (pre->m_balance == 0)//已经平衡直接退出
			{
				break;
			}
		
			//如果是1/-1则需要往上遍历，寻找平衡点
			sun = cur;
			cur = pre;
			pre = pre->m_parent;
		}
	}

	void Rrotate(AVLtreeNode<T> *father, AVLtreeNode<T> *son)
	{
		AVLtreeNode<T> *grand = nullptr;
		bool sign = false;
		if (father == m_head)
		{
			sign = true;
		}
		else
		{
			grand = father->m_parent;
		}

		if (sign)
		{
			father->m_left = son->m_right;
			if (son->m_right)
			{
				son->m_right->m_parent = father;
			}

			son->m_right = father;
			father->m_parent = son;
			m_head = son;
		}
		else
		{
			if (grand->m_left == father)
			{
				grand->m_left = son;
			}
			else
			{
				grand->m_right = son;
			}
			son->m_parent = grand;

			father->m_left = son->m_right;
			if (son->m_right)
			{
				son->m_right->m_parent = father;
			}

			son->m_right = father;
			father->m_parent = son;

		}
		son->m_balance++;
		father->m_balance = 0;
	}

	void Lrotate(AVLtreeNode<T> *father, AVLtreeNode<T> *son)
	{
		AVLtreeNode<T> *grand = nullptr;
		bool sign = false;
		if (father == m_head)
		{
			sign = true;
		}
		else
		{
			grand = father->m_parent;
		}

		if (sign)
		{
			father->m_right = son->m_left;
			if (son->m_left)
			{
				son->m_left->m_parent = father;
			}

			son->m_left = father;
			father->m_parent = son;
			m_head = son;
		}
		else
		{
			if (grand->m_left == father)
			{
				grand->m_left = son;
			}
			else
			{
				grand->m_right = son;
			}
			son->m_parent = grand;

			father->m_right = son->m_left;
			if (son->m_left)
			{
				son->m_left->m_parent = father;
			}

			son->m_left = father;
			father->m_parent = son;

		}
		son->m_balance--;
		father->m_balance = 0;
	}

};