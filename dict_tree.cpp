#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define MAXN 1001
#define MAXC 26

class DictTree {
public:
	//插入 
	bool insert(std::string word) {
		int p = 0;//序号
		for (int i = 0; i < word.size(); i++) {
			int c = word[i] - 'a';
			if (m_tree[p][c] == 0) {
				m_tree[p][c] = m_k;//标记这个字符存在,并存储它的下标
				m_k++;
			}
			p = m_tree[p][c];//接着往下找
		}
		m_color[p] = true;//标记该字符为结尾字符
		return true;
	}

	//查找
	bool search(std::string word) {
		int p = 0;
		for (int i = 0; i < word.size(); i++) {
			int c = word[i] - 'a';
			if (m_tree[p][c] == 0) {
				return false;
			}
			p = m_tree[p][c];
		}
		return m_color[p];
	}

private:

	bool m_color[MAXN] = {false};//标识是否为结束节点
	int m_tree[MAXN][MAXC] = { 0 };//初始化
	int m_k = 1;//表示下一个点的序号,数组的下标
};

int min(){
	DictTree dt;
	dt.insert("hello");
	dt.insert("world");
	dt.insert("belongal");
	if (dt.search("hello")){
		cout << "hello" << endl;
	}
	if (dt.search("hell")) {
		cout << "hell" << endl;
	}
	if (dt.search("belongal")) {
		cout << "belongal" << endl;
	}
	if (dt.search("hehe")) {
		cout << "hehe" << endl;
	}
	return 0;
}