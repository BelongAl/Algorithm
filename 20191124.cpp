#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class hand
{
public:
	vector<string> m_v1;
	vector<string> m_v2;
	map<string, int> m_m;
	int m_a;
	hand(vector<string> &a, vector<string> &b) :
		m_v1(a),
		m_v2(b),
		m_a(1)
	{
		string s[15] = {"3","4","5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER"};
		for (int i = 0; i < 15; i++)
		{
			m_m.insert(make_pair(s[i], i));
		}
	}
	vector<string> judje()
	{
		if (m_v1.size() == 2 && m_v1[0] == "joker" && m_v1[1] == "JOKER")
		{
			return m_v1;
		}
		if (m_v2.size() == 2 && m_v2[0] == "joker" && m_v2[1] == "JOKER")
		{
			return m_v1;
		}
		if (m_v1.size() == m_v2.size() &&  m_v1.size() < 5)
		{
			return m_m[m_v1[0]] > m_m[m_v2[0]] ? m_v1 : m_v2;
		}
		else if (m_v1.size() == m_v2.size())
		{
			string s1 = m_v1[0];
			string s2 = m_v2[0];
			for (auto &i : m_v1)
			{
				if (m_m[i] < m_m[s1])
				{
					s1 = i;
				}
			}
			for (auto &i : m_v1)
			{
				if (m_m[i] < m_m[s1])
				{
					s1 = i;
				}
			}
			return m_m[s1] > m_m[s2] ? m_v1 : m_v2;
		}
		else if (m_v1.size() == 4 || m_v2.size() == 4)
		{
			if (m_v1.size() == 4)
			{
				return m_v1;
			}
			return m_v2;
		}
		m_a = 0;
		return m_v1;
	}
};

int main()
{
	string s;
	getline(cin, s);
	vector<string> v1;
	vector<string> v2;
	int i = 0;
	while (i < s.size())
	{
		string tmp;
		while (1)
		{
			if (s[i] == ' ' || s[i] == '-' || i == s.size())
			{
				i++;
				break;
			}
			tmp.push_back(s[i]);
			i++;
		}
		v1.push_back(tmp);
		if (s[i - 1] == '-')
		{
			break;
		}
	}
	while (i < s.size())
	{
		string tmp;
		while (1)
		{
			if (s[i] == ' '|| i == s.size())
			{
				i++;
				break;
			}
			tmp.push_back(s[i]);
			i++;
		}
		v2.push_back(tmp);
	}

	hand my(v1, v2);
	vector<string> ret = my.judje();
	if (my.m_a == 0)
	{
		cout << "ERROR" << endl;
	}
	else
	{
		for (auto &i : ret)
		{
			cout << i << " " ;
		}
	}
	system("pause");
	return 0;
}



