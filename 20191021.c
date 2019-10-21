#define	_CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef int TreeType;

typedef struct ForkTre
{
	TreeType val;
	struct ForkTree *left;
	struct ForkTree *right;
}TreeNode;

TreeNode *BuyTreeNode(int data)
{
	TreeNode *root = (struct TreeNode*)malloc(sizeof(TreeNode));
	root->val = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

void _build(int *preorder, int preorderSize, int *inorder, int left, int right, int *count, TreeNode**root)
{
	if (left < right && (*count) < preorderSize)
	{
		(*root) = BuyTreeNode(preorder[*count]);
		int i = 0;
		while (preorder[*count] != inorder[i])
		{
			i++;
		}
		(*count)++;
		_build(preorder, preorderSize, inorder, left, i, count, &(*root)->left);
		_build(preorder, preorderSize, inorder, i + 1, right, count, &(*root)->right);
	}
}

TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	int i = 0;
	int j = 0;
	int count = 0;
	TreeNode*root = NULL;
	_build(preorder, preorderSize, inorder, 0, inorderSize, &count, &root);
	return root;
}

int main()
{
	TreeNode* ft;
	int preorder[] = { 3,9,20,15,7 };
	int inorder[] = { 9,3,15,20,7 };
	ft = buildTree(preorder, sizeof(preorder) / sizeof(preorder[0]),inorder, sizeof(inorder) / sizeof(inorder[0]));
	system("pause");
	return 0;
}