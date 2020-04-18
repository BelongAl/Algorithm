#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:

	static int getnumber(char *&str)
	{
		char *tmp = str+1;
		while (*tmp != '!')
		{
			tmp++;
		}
		string s(str, tmp);
		str = tmp;
		return atoi(s.c_str());
	}

	char* Serialize(TreeNode *root) {
		//利用前序进行序列化
		if (nullptr == root)
		{
			return nullptr;
		}
		stack<TreeNode*> s;
		s.push(root);
		string res;
		while (!s.empty())
		{
			TreeNode *top = s.top();
			if (nullptr == top)
			{
				res.push_back('#');
				s.pop();
				continue;
			}
			res += to_string(top->val);
			res.push_back('!');
			s.pop();
			s.push(top->right);
			s.push(top->left);
		}
		res.push_back('\0');
		char *rs = new char[res.size()+1];
		int i = 0;
		for (i = 0; i < res.size(); i++)
		{
			rs[i] = res[i];
		}
		rs[i] = '\0';
		return rs;
	}
	TreeNode* Deserialize(char *str) {
		TreeNode *root = nullptr;
		if (nullptr == str)
		{
			return root;
		}
		stack<pair<TreeNode*, int>> s;
		root = new TreeNode(getnumber(str));
		s.push(make_pair(root, 2));
		str++;
		while (*str != '\0' && !s.empty())
		{
			if (s.top().second == 2)
			{
				while (*str != '\0' && *str != '#')
				{
					TreeNode *newNode = new TreeNode(getnumber(str));
					s.top().first->left = newNode;
					s.top().second--;
					s.push(make_pair(newNode, 2));
					str++;
				}
				if (*str == '\0')
				{
					break;
				}
				s.top().second--;
			}
			else
			{
				if (*str != '#')
				{
					TreeNode *newNode = new TreeNode(getnumber(str));
					s.top().first->right = newNode;
					s.pop();
					s.push(make_pair(newNode, 2));
				}
				else
				{
					s.pop();
				}
			}
			str++;
		}
		return root;
	}
};

int main()
{
	Solution s;
	const char *str = "1!2!4!##5!8!#10!###3!6!#9!##7!##";
	TreeNode *root = s.Deserialize(const_cast<char*>(str));
	char *res = s.Serialize(root);
	return 0;
}

