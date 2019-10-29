#pragma once

#include<iostream>

using namespace std;

namespace wr

{
	template<class T>
	class listNode
	{
	public:
		T m_val;
		listNode *m_left;
		listNode *m_right;
		listNode(const T &x = T()) :
			m_val(x),
			m_left(nullptr),
			m_right(nullptr)
		{}
	};

	template<class T>
	class list
	{
		listNode<T> *m_head;
		void CreatHead()
		{
			m_head = new listNode<T>;
			m_head->m_left = m_head;
			m_head->m_right = m_head;
			m_head->m_val = 0;
		}
	public:
		class iterator//迭代器类
		{
		public:
			listNode<T> *m_pos;
			iterator(listNode<T> *p = nullptr) :
				m_pos(p)
			{}

			T& operator*()const//解引用
			{
				return m_pos->m_val;
			}

			T* operator->()const//返回地址
			{
				return &m_pos->m_val;
			}

			iterator operator++()
			{
				m_pos = m_pos->m_left;
				return *this;
			}

			iterator operator++(int k)
			{
				iterator tmp = *this;
				m_pos = m_pos->m_left;
				return tmp;
			}

			iterator operator--()
			{
				m_pos = m_pos->m_right;
				return *this;
			}

			iterator operator--(int k)
			{
				iterator tmp = *this;
				m_pos = m_pos->m_right;
				return tmp;
			}

			bool operator==(const iterator& ci)const
			{
				return m_pos == ci.m_pos;
			}

			bool operator!=(const iterator& ci)const
			{
				return m_pos != ci.m_pos;
			}
		};

		list()
		{
			CreatHead();
		}

		list(int n, const T &val = T())
		{
			CreatHead();
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		list(iterator start, iterator finish)
		{
			CreatHead();
			insert(end(), start, finish);
		}

		list(list<T> &l)
		{
			CreatHead();
			insert(end(), l.begin(), l.end());
		}

		void push_front(const T &val)
		{
			insert(begin(), val);
		}

		void push_back(const T &val)
		{
			insert(end(), val);
		}

		iterator insert(iterator pos, const T &val)
		{
			listNode<T> *cur = new listNode<T>;
			listNode<T> *npos = pos.m_pos;
			cur->m_val = val;
			cur->m_left = npos->m_left;
			cur->m_left->m_right = cur;
			cur->m_right = npos;
			npos->m_left = cur;
			return cur;
		}

		iterator insert(iterator pos, T *start, T *finish)
		{
			iterator tmpit = --pos;
			pos++;
			for (T *tmp = start; tmp != finish; tmp++)
			{
				insert(pos, *tmp);
			}
			return ++tmpit;
		}

		iterator insert(iterator pos, iterator start, iterator end)
		{
			iterator tmp;
			iterator tmpit = --pos;
			pos++;
			for (tmp = start; tmp != end; tmp++)
			{
				insert(pos, *tmp);
			}
			return ++tmpit;
		}

		iterator erase(iterator pos)
		{
			listNode<T> * npos = pos.m_pos;
			listNode<T> * res = npos->m_next;
			npos->m_next->m_prev = npos->m_prev;
			npos->m_prev->m_next = npos->m_next;
			delete npos;
			return res;
		}

		iterator erase(iterator start, iterator finish)
		{
			iterator i;
			for (i = start; i != finish; i++)
			{
				erase(i);
			}
			return finish;
		}

		iterator begin()
		{
			return m_head->m_left;
		}

		iterator end()
		{
			return m_head;
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}
	};

}
