#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {
		if (chars.size() == 0)
		{
			return 0;
		}
		char tmp = chars[0];
		char t;
		int j = 0;
		for (int i = 0; i < chars.size(); )
		{
			int count = 0;
			while (i < chars.size() && chars[i] == tmp)
			{
				count++;
				i++;
				if (i == chars.size() || chars[i] != tmp)
				{
					if (i == chars.size())
					{
						t = tmp;
					}
					else
					{
						t = tmp;
						tmp = chars[i];
					}
					break;
				}
			}
			if (count == 1)
			{
				chars[j++] = t;
			}
			else
			{
				chars[j++] = t;
				string s;
				while (count)
				{
					s.push_back(count % 10 + '0');
					count /= 10;
				}
				for (int i = s.size()-1; i >= 0; i--)
				{
					chars[j++] = s[i];
				}
			}
		}
		return j;
	}
};

int main()
{
	vector<char> v;
	v.push_back('a');
	v.push_back('b');
	v.push_back('b');
	v.push_back('b');
	v.push_back('b');
	v.push_back('b');
	v.push_back('b');
	v.push_back('b');
	v.push_back('b');
	v.push_back('b');
	v.push_back('b');

	Solution s;
	s.compress(v);

	system("pause");
	return 0;
}