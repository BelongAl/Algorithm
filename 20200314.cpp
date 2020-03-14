#include<iostream>
#include<vector>
#include<stack>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 class Solution1 {
	 int FindIndex(vector<int> v, int val)
	 {
		 for (int i = 0; i < v.size(); i++)
		 {
			 if (v[i] == val)
			 {
				 return i;
			 }
		 }
	 }


 public:
	 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		 if (inorder.size() == 0)
		 {
			 return nullptr;
		 }
		 if (inorder.size() != postorder.size())
		 {
			 return nullptr;
		 }

		 vector<TreeNode*> vNode;
		 for (int i = 0; i < inorder.size(); i++)
		 {
			 vNode.push_back(new TreeNode(inorder[i]));
		 }

		 vector<int> m_index(postorder.size(), 0);//记录已经插过的点

		 stack<int> s;//存放插入的位置
		 //找到头节点
		 int val = postorder[postorder.size() - 1];
		 int rootindex = FindIndex(inorder, val);
		 m_index[rootindex] = 1;

		 s.push(rootindex);//存储插入位置

		 for (int i = postorder.size() - 2; i >= 0; i--)
		 {
			 int curIndex = s.top();
			 int insertIndex = FindIndex(inorder, postorder[i]);
			 if (curIndex < insertIndex)//如果在右边直接插入
			 {
				 vNode[curIndex]->right = vNode[insertIndex];
				 m_index[insertIndex] = 1;
				 s.push(insertIndex);
			 }
			 else//寻找其最近节点，插入在左边
			 {
				 int i = 0;
				 for (i = insertIndex; i < inorder.size(); i++)
				 {
					 if (m_index[i] == 1)
					 {
						 break;
					 }
				 }
				 vNode[i]->left = vNode[insertIndex];
				 m_index[insertIndex] = 1;
				 while (s.top() != i)
				 {
					 s.pop();
				 }
				 s.push(insertIndex);
			 }
		 }

		 return vNode[rootindex];
	 }
 };

 class Solution {
 public:
	 TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		 int pos = inorder.size() - 1;
		 return buildTree(postorder, pos, inorder, 0, inorder.size() - 1);
	 }

	 TreeNode* buildTree(vector<int>& postorder, int& pos, vector<int>& inorder, int left, int right) {
		 if (pos < 0 || left > right) return 0;
		 int p = left;
		 while (p <= right && postorder[pos] != inorder[p])
		 {
			 p++;
		 }
		 TreeNode* node = new TreeNode(postorder[pos]);
		 if (p + 1 <= right)
		 {
			 node->right = buildTree(postorder, --pos, inorder, p + 1, right);
		 }
		 if (left <= p - 1)
		 {
			 node->left = buildTree(postorder, --pos, inorder, left, p - 1);
		 }
		 return node;
	 }
 };
int main()
{
	TreeNode *t1 = new TreeNode(10);
	TreeNode *t2 = new TreeNode(5);
	TreeNode *t3 = new TreeNode(15);
	TreeNode *t4 = new TreeNode(6);
	TreeNode *t5 = new TreeNode(20);
	t1->left = t2;
	t1->right = t3;
	t3->left = t4;
	t3->right = t5;


	vector<int> a{ 9,3,15,20,7 };
	vector<int> b{ 9,15,7,20,3};

	Solution s;
	s.buildTree(a,b);
	
}
