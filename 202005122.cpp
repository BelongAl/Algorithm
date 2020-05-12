#include<list>
#include<iostream>
#include<unordered_map>

using namespace std;

struct List
{
	int m_val;
	int m_key;
	List *m_left;
	List *m_right;

	List(int val = 0, int key = 0)
		:m_val(val),
		m_key(key),
		m_left(nullptr),
		m_right(nullptr)
	{}
};

class LRUCache {
	int m_capacity;
	list<int> m_l;
	unordered_map<int, List*> m_mp;
	List *m_head;
	List *m_end;
	int m_size;

	void updata(int key)
	{
		if (m_size == 2)
		{
			List *tmp = m_head;
			m_head = m_end;
			m_end = tmp;
			return;
		}
		if (m_mp[key] == m_end)
		{
			m_end = m_end->m_right;
		}
		List *tmp = m_mp[key];
		List *pre = tmp->m_left;
		pre->m_right = tmp->m_right;
		tmp->m_right->m_left = pre;
		tmp->m_right = m_head;
		tmp->m_left = m_head->m_left;
		m_head->m_left = tmp;
		tmp->m_left->m_right = tmp;
		m_head = tmp;
	}

public:
	LRUCache(int capacity) :
		m_capacity(capacity),
		m_size(0),
		m_head(nullptr),
		m_end(nullptr)
	{}

	int get(int key) 
	{
		if (m_mp[key])
		{
			updata(key);
			return m_head->m_val;
		}
		else
		{
			return -1;
		}
	}

	void put(int key, int value) 
	{
		if (m_capacity == 0)
		{
			return;
		}
		if (m_mp[key])
		{
			m_mp[key]->m_val = value;
			updata(key);
			return;
		}
		if (m_size == m_capacity)
		{
			List *tmp = m_end->m_left;
			tmp->m_right = m_end->m_right;
			m_end->m_right->m_left = tmp;
			int k = m_end->m_key;
			delete m_end;
			m_mp[k] = nullptr;
			m_end = tmp;
			m_size--;
		}
		List *newnode = new List(value, key);
		if (m_size == 0)
		{
			m_head = newnode;
			m_end = newnode;
			m_head->m_left = m_head;
			m_head->m_right = m_head;
		}
		else
		{
			List *tmp = m_head->m_left;
			tmp->m_right = newnode;
			newnode->m_right = m_head;
			m_head->m_left = newnode;
			newnode->m_left = tmp;
		}
		m_head = newnode;
		m_mp[key] = newnode;
		m_size++;
	}
};

int main()
{
	LRUCache lru(2);
	lru.put(2, 1);
	lru.put(3, 2);
	cout << lru.get(3) << endl;
	cout << lru.get(2) << endl;
	lru.put(4, 3);
	cout << lru.get(2) << endl;
	cout << lru.get(3) << endl;
	cout << lru.get(4) << endl;


	return 0;
}