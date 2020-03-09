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

		//若左子树或右子树为空，直接删除接上另一个
		if (cur->m_left == nullptr)
		{
			cur = cur->m_right;
			return true;
		}
		else if (cur->m_right == nullptr)
		{
			cur = cur->m_left;
			return true;
		}
		//否则寻找前驱节点或后继节点补上去，我们在这里找后继节点
		AVLtreeNode<T> *back = cur->m_right;
		while (back)//寻找后继节点
		{
			pre = back;
			back = back->m_left;
		}
		//保留交换节点的左子树
		AVLtreeNode<T> *tmp = pre->m_parent;
		tmp->m_left = pre->m_right;
		//交换
		cur->m_val = pre->m_val;
		//删除
		delete pre;
		pre = nullptr;
		//平衡因子调整调整.右边删除一个相当于左边添加了一个
		if (tmp->m_right)
		{
			AdjustBlance(tmp->m_right, tmp);
		}
		else
		{
			AVLtreeNode<T> *tmpadd = new AVLtreeNode<T>(0);
			tmp->m_right = tmpadd;
			AdjustBlance(tmpadd, tmp);
		}
		return true;
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