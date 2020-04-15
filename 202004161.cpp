#include<iostream>
#include<string>
#include<map>
#include<queue>

using namespace std;

struct err
{
	string m_filename;
	int m_line;
	err(string s, int line):
		m_filename(s),
		m_line(line)
	{}

	bool operator<(const err &e)const
	{
		if (m_filename < e.m_filename)
		{
			return true;
		}
		else if (m_filename == e.m_filename)
		{
			if (m_line < e.m_line)
			{
				return true;
			}
			return false;
		}
		return false;
	}

	bool operator==(const err &e)const
	{
		if (e.m_filename == m_filename && e.m_line == m_line)
		{
			return true;
		}
		return false;
	}

};

int main()
{
	string s;
	map<err, int> me;
	queue<err> q;
	while (cin >> s)
	{
		string filename;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] == '\\')
			{
				break;
			}
			filename.push_back(s[i]);
			if (filename.size() == 16)
			{
				break;
			}
		}
		for (int i = 0, j = filename.size() - 1; j > i; j--, i++)
		{
			swap(filename[i], filename[j]);
		}
		int line;
		cin >> line;
		err tmpe(filename, line);
		if (me.find(tmpe) != me.end())
		{
			me[tmpe]++;
		}
		else if (me.size() < 8)
		{
			q.push(tmpe);
			me[tmpe]++;
		}
		else
		{
			//删除最早的一个
			err tmp = q.front();
			q.pop();
			me.erase(tmp);
			q.push(tmpe);
			me[tmpe]++;
		}
	}

	bool b = true;
	while (!q.empty())
	{
		if (!b)
		{
			cout << " ";
		}
		err tmp = q.front();
		q.pop();
		map<err, int>::iterator it = me.find(tmp);
		cout << it->first.m_filename << " " << it->first.m_line << " " << it->second;
		b = false;
	}

	return 0;
}

