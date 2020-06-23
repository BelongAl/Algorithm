#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define MAXN 1001
#define MAXC 26

class DictTree {
public:
	//���� 
	bool insert(std::string word) {
		int p = 0;//���
		for (int i = 0; i < word.size(); i++) {
			int c = word[i] - 'a';
			if (m_tree[p][c] == 0) {
				m_tree[p][c] = m_k;//�������ַ�����,���洢�����±�
				m_k++;
			}
			p = m_tree[p][c];//����������
		}
		m_color[p] = true;//��Ǹ��ַ�Ϊ��β�ַ�
		return true;
	}

	//����
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

	bool m_color[MAXN] = {false};//��ʶ�Ƿ�Ϊ�����ڵ�
	int m_tree[MAXN][MAXC] = { 0 };//��ʼ��
	int m_k = 1;//��ʾ��һ��������,������±�
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