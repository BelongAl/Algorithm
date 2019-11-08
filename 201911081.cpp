#include<iostream>
#include<string>

using namespace std;

string DeleteRepeat(string d, string r)
{
	int hashtable[256] = { 0 };//using hash ideas 
	string res;
	for (int i = 0; i < r.size(); i++)
	{
		hashtable[r[i]] = 1;
	}
	for (int i = 0; i < d.size(); i++)
	{
		if (hashtable[d[i]] == 0)
		{
			res.push_back(d[i]);
		}
	}
	return res;
}

int main()
{
	string s;
	getline(cin, s);
	string d;
	getline(cin, d);
	cout << DeleteRepeat(s, d);
	return 0;
}