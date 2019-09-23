#include"BinTree.h"

void TestBinTree()
{
	char *str = "ABD###CE##F##";
	BTNode *pRoot = CreateBinTree(str, strlen(str),'#');
	printf("前序遍历结果: ");
	PreOrder(pRoot);
	printf("\n");
	printf("中序遍历结果: ");
	InOrder(pRoot);
	printf("\n");
	printf("后序遍历结果: ");
	PostOrder(pRoot);
	printf("\n");
	LeveIOrder(pRoot);//层序遍历结果
	printf("二叉树有%d个叶子节点\n", GetLeafCount(pRoot));//获取叶子节点个数
	BTNode *p = NULL;
	//CopyBinTree(&pRoot,&p);//把pRoot拷贝到p
	printf("二叉树有%d个节点\n", GetBinTreeSize(pRoot));//求二叉树中节点的个数
	printf("二叉树的深度为%d\n", GetBinTreeHeight(pRoot));//获取树的深度
	printf("二叉树第3层的节点数为%d\n", GetKLeveNodeCount1(pRoot, 3));
	printf("二叉树第3层的节点数为%d\n", GetKLeveNodeCount2(pRoot, 3));
	BTNode * Find = BinaryTreeFind(pRoot,'B');//寻找为B的节点
	printf("找到了值域为：%c\n", Find->data);
	Mirror(pRoot);//镜像1 层序遍历
	LeveIOrder(pRoot);//层序遍历结果
	MirrorNor(pRoot);//镜像二 前序遍历
	LeveIOrder(pRoot);//层序遍历结果
	DestroyBinTree(pRoot);//销毁
}

int main()
{
	TestBinTree();
	system("pause");
	return;
}