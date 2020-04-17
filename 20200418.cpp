#include<iostream>

using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode == nullptr)
		{
			return nullptr;
		}
		if (pNode->right != NULL)
		{
			TreeLinkNode *pre = pNode->right;
			pNode = pNode->right;
			while (pNode != NULL)
			{
				pre = pNode;
				pNode = pNode->left;
			}
			return pre;
		}
		else
		{
			if (pNode->next == nullptr)
			{
				return nullptr;
			}
			else
			{
				while (pNode->next)
				{
					if (pNode == pNode->next->left)
					{
						return pNode->next;
					}
					else
					{
						pNode = pNode->next;
					}
				}
				return nullptr;
			}
		}
	}
};