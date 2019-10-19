#pragma once
#include<iostream>
using namespace std;

namespace wr
{
	template<typename T>
	class Vector
	{
		T* m_start;//开始
		T* m_finish;//有效末端
		T* m_endOfStorage;//容量末端
	public:
		typedef T* iterator;
		typedef const T * const_iterator;
		//构造函数
		Vector():
			m_start(nullptr),
			m_finish(nullptr),
			m_endOfStorage(nullptr)
		{}

		Vector(int n, const T &val = T())://缺省,调用默认构造
			m_start(nullptr),
			m_finish(nullptr),
			m_endOfStorage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				m_start[i] = val;
			}
			m_finish = m_start + n;
		}

		Vector(T * start, T * end):
			m_start(nullptr),
			m_finish(nullptr),
			m_endOfStorage(nullptr)
		{
			size_t size = end - start;
			reserve(size);
			for (int i = 0; i < size; i++)
			{
				m_start[i] = start[i];
			}
			m_finish = m_start + size;
		}

		size_t size()
		{
			return m_finish - m_start;
		}

		size_t capacity()
		{
			return m_endOfStorage - m_start;
		}


		void reserve(size_t _size)//给容量
		{
			size_t _capacity = capacity();
			if (_capacity < _size)
			{
				if (_capacity == 0)
				{
					_capacity = 1;
				}
				while (_capacity < _size)
				{
					_capacity *= 2;
				}
			}
			T *tmp = new T[_capacity];
			int oldsize = size();
			m_finish = tmp + oldsize;
			m_endOfStorage = tmp + _capacity;
			if (m_start != nullptr)
			{
				for (int i = 0; i < oldsize; i++)
				{
					tmp[i] = m_start[i];
				}
				delete[] m_start;
			}
			m_start = tmp;
		}

		T & operator[](int i)
		{
			return m_start[i];
		}
		const T & operator[](int i) const
		{
			return m_start[i];
		}

		iterator begin()
		{
			return m_start;
		}

		iterator end()
		{
			return m_finish;
		}
		
		void resize(size_t _size, const T &val = T())
		{
			reserve(_size);
			for (int i = size(); i < _size; i++)
			{
				m_start[i] = val;
			}
			m_finish = m_start + _size;
		}

		iterator insert(iterator pos,const T &val)
		{
			int tmp = pos - m_start;
			reserve(size() + 1);
			pos = m_start + tmp;
			for (int i = size(); i > pos - m_start; i--)
			{
				m_start[i] = m_start[i - 1];
			}
			*pos = val;
			m_finish++;
			return pos;
		}
		iterator insert(iterator pos, int n, const T &val)
		{
			int tmp = pos - m_start;
			reserve(size() + n);
			pos = m_start + tmp;
			for (int i = size() - 1; i >= pos - m_start; i--)
			{
				m_start[i + n] = m_start[i];
			}
			for (int i = 0; i < n; i++)
			{
				pos[i] = val;
			}
			m_finish += n;
			return pos;
		}

		iterator insert(iterator pos, const T *start,const T *end)
		{
			int tmp = pos - m_start;
			int extsize = end - start;
			reserve(size() + extsize);
			pos = m_start + tmp;
			for (int i = size() - 1; i >= pos - m_start; i--)
			{
				m_start[i + extsize] = m_start[i];
			}
			for (int i = 0; i < extsize; i++)
			{
				pos[i] = start[i];
			}
			m_finish += extsize;
			return pos;
		}

		iterator erase(iterator pos)
		{
			for (int i = pos - m_start; i < size()-1; i++)
			{
				m_start[i] = m_start[i + 1];
			}
			m_finish--;
			return pos;
		}

		iterator erase(iterator start, iterator end)
		{
			int extsize = end - start;
			for (int i = start - m_start; i < size() - extsize; i++)
			{
				m_start[i] = m_start[i + extsize];
			}
			m_finish -= extsize;
			return start;
		}

		void push_back(const T&val)
		{
			reserve(size() + 1);
			*m_finish = val;
			m_finish++;
		}

		void pop_back(const T&val)
		{
			m_finish--;
		}
	};
}
