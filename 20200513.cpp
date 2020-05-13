#include<list>
#include<iostream>
#include<unordered_map>

using namespace std;

struct listNode
{
	int m_key;
	int m_val;
	listNode *m_left;
	listNode *m_right;

	listNode(int val = 0, int key = 0)
		:m_key(key),
		m_val(val),
		m_left(nullptr),
		m_right(nullptr)
	{}

	~listNode()
	{

	}
};

class LRUCache {

	void updata(int key)//更新
	{
		listNode *newhead = m_hash[key];
		if (newhead == m_end)
		{
			m_end = m_end->m_left;
		}
		//吧newhead单独拿出来
		listNode *tmp = newhead->m_left;
		tmp->m_right = newhead->m_right;
		newhead->m_right->m_left = tmp;
		int k = newhead->m_key;
		int val = newhead->m_val;
		delete newhead;
		newhead = nullptr;
		m_hash[k] = nullptr;
		m_size--;
		put(k, val);
	}

	void erase()//删除最久未使用
	{
		if (m_end == nullptr)
		{
			return;
		}
		listNode *tmp = m_end;
		m_end = m_end->m_left;
		int key = tmp->m_key;
		m_hash[key] = nullptr;//删除哈希表中的节点
		//delete tmp;
		tmp = nullptr;
		m_size--;
	}

public:
	LRUCache(int capacity) :
		m_capacity(capacity),
		m_size(0),
		m_head(nullptr),
		m_end(nullptr)
	{}

	int get(int key) {
		if (m_hash[key] == nullptr)
		{
			return -1;
		}
		if (m_hash[key] != m_head)
		{
			updata(key);//更新
		}
		return m_hash[key]->m_val;
	}

	void put(int key, int value) {
		if (m_hash[key] != nullptr)
		{
			m_hash[key]->m_val = value;
			if (m_hash[key] == m_head)
			{
				return;
			}
			updata(key);
			return;
		}
		//判断容量
		if (m_size == m_capacity)
		{
			erase();//删除
		}
		listNode *newnode = new listNode(value, key);
		m_hash[key] = newnode;
		if (m_head == nullptr || m_end == nullptr)
		{
			m_head = newnode;
			m_end = newnode;
			m_head->m_left = m_end;
			m_head->m_right = m_end;
		}
		else
		{
			listNode *tmp = m_head->m_left;
			tmp->m_right = newnode;
			newnode->m_right = m_head;
			newnode->m_left = tmp;
			m_head->m_left = newnode;
			m_head = newnode;
		}
		m_size++;
	}

private:
	listNode *m_head;
	listNode *m_end;
	int m_size;
	int m_capacity;
	unordered_map<int, listNode*> m_hash;
};

int main()
{

	//["LRUCache", "put", "put", "put", "put", "get", "get", "get", "get", "put", "get", "get", "get", "get", "get"]
	//[[3], [1, 1], [2, 2], [3, 3], [4, 4], [4], [3], [2], [1], [5, 5], [1], [2], [3], [4], [5]]
	LRUCache lru(3);
	lru.put(1, 1);
	lru.put(2, 2);
	lru.put(3, 3);
	lru.put(4, 4);
	cout << lru.get(4) << endl;
	cout << lru.get(3) << endl;
	cout << lru.get(2) << endl;
	cout << lru.get(1) << endl;
	lru.put(5, 5);
	cout << lru.get(1) << endl;
	lru.put(4, 6);
	lru.put(4, 7);
	cout << lru.get(2) << endl;
	cout << lru.get(3) << endl;
	cout << lru.get(4) << endl;
	cout << lru.get(5) << endl;
	return 0;
}