#include"BinTree.h"

void TestBinTree()
{
	char *str = "ABD###CE##F##";
	BTNode *pRoot = CreateBinTree(str, strlen(str),'#');
	printf("ǰ��������: ");
	PreOrder(pRoot);
	printf("\n");
	printf("����������: ");
	InOrder(pRoot);
	printf("\n");
	printf("����������: ");
	PostOrder(pRoot);
	printf("\n");
	LeveIOrder(pRoot);//����������
	printf("��������%d��Ҷ�ӽڵ�\n", GetLeafCount(pRoot));//��ȡҶ�ӽڵ����
	BTNode *p = NULL;
	//CopyBinTree(&pRoot,&p);//��pRoot������p
	printf("��������%d���ڵ�\n", GetBinTreeSize(pRoot));//��������нڵ�ĸ���
	printf("�����������Ϊ%d\n", GetBinTreeHeight(pRoot));//��ȡ�������
	printf("��������3��Ľڵ���Ϊ%d\n", GetKLeveNodeCount1(pRoot, 3));
	printf("��������3��Ľڵ���Ϊ%d\n", GetKLeveNodeCount2(pRoot, 3));
	BTNode * Find = BinaryTreeFind(pRoot,'B');//Ѱ��ΪB�Ľڵ�
	printf("�ҵ���ֵ��Ϊ��%c\n", Find->data);
	Mirror(pRoot);//����1 �������
	LeveIOrder(pRoot);//����������
	MirrorNor(pRoot);//����� ǰ�����
	LeveIOrder(pRoot);//����������
	DestroyBinTree(pRoot);//����
}

int main()
{
	TestBinTree();
	system("pause");
	return;
}