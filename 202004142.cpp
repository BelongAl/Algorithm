#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	string res;
	int i = s.size() - 1;
	while (i >= 0 &&  !(65 <= s[i] && s[i] <= 90) && !(97 <= s[i] && s[i] <= 122))
	{
		i--;
	}
	int k = 0;
	while (k < s.size() && !(65 <= s[k] && s[k] <= 90) && !(97 <= s[k] && s[k] <= 122))
	{
		k++;
	}
	int j = i + 1;
	for (; i >= k; i--)
	{
		if (!(65 <= s[i] && s[i] <= 90) && !(97 <= s[i] && s[i] <= 122))
		{
			int tmp = i + 1;
			while (tmp < j)
			{
				res.push_back(s[tmp]);
				tmp++;
			}
			res.push_back(' ');
			while (i - 1 >= 0 && !(65 <= s[i -1] && s[i - 1] <= 90) && !(97 <= s[i - 1] && s[i -1] <= 122))
			{
				i--;
			}
			j = i;
		}
	}
	i++;
	while (i < j)
	{
		res.push_back(s[i]);
		i++;
	}
	cout << res << endl;
	return 0;
}