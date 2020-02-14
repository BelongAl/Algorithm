/***************************************************************************************************
名称：Huffman Tree
基本概念：给定n权值作为n个叶子节点，构造一棵二叉树，若这棵二叉树的带权路径长度达到最小，则称这样的
		  二叉树为最优二叉树，也称为Huffman树。

性质：  1：不唯一性（具有相同带权节点）；左右子树可以互换
		2：带权值的节点都是叶子节点
		3：huffman tree中只有叶子节点和度为2的节点，没有度为1的节点
		4：一棵有n个叶子节点的Huffman tree共有2n−1个节点，需要n−1次合并。

实现方法：1：假设有n个节点，他们的权值分别为W1.....Wn;将所有节点的合集看成一个森林，
		  2：每次在所有的森林中取出根节点最小的两个节点作为左右节点合并（小左大右），且合并后的根节点的权值是左
			 右节点之和
		  3：把合并好的节点再次加入森林中
		  4：一直重复2，3步就可以得到Huffman tree了

意义：压缩数据
****************************************************************************************************/
#pragma once

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<class T>
class HuffmanTreeNode
{
	T m_val;
	HuffmanTreeNode *m_left;
	HuffmanTreeNode *m_right;
	HuffmanTreeNode *m_parent;


	template<class T>
	friend class HuffmanTree;

public:

	HuffmanTreeNode(T val = T()) ://构造函数
		m_val(val),
		m_right(nullptr),
		m_parent(nullptr),
		m_left(nullptr)
	{
	}

};

template<class T>
class HuffmanTree
{
	HuffmanTreeNode<T> *m_root;
public:
	HuffmanTree():
		m_root(nullptr)
	{}
	
	HuffmanTree(vector<T> v)
	{
		m_root = getHuffManTree(v);
	}

private:

	HuffmanTreeNode<T>* getHuffManTree(vector<int> v)
	{
		vector<HuffmanTreeNode<T>*> phf(v.size());
		for (int i = 0; i < v.size(); i++)
		{
			phf[i] = new HuffmanTreeNode<T>(v[i]);
			AdjustUp(phf, i);
		}
		
		int index = phf.size() - 1;
		int count = 2;

		while (index)
		{
			swap(phf[0], phf[index--]);//左
			AdjustDown(phf, index);
			swap(phf[0], phf[index--]);//右
			AdjustDown(phf, index);

			T add = phf[index + 1]->m_val + phf[index + 2]->m_val;
			phf.push_back(new HuffmanTreeNode<T>(add));
			index++;
			swap(phf[index], phf[index + count]);

			phf[index]->m_left = phf[index + 1];
			phf[index]->m_right = phf[index + count];
			AdjustUp(phf, index);

			count += 2;
		}
		return phf[0];
	}

	void AdjustUp(vector<HuffmanTreeNode<T>*> &v, int child)//向上调整，获得小堆
	{
		int parent = (child - 1) / 2;
		while (child)
		{
			if (v[child]->m_val < v[parent]->m_val)
			{
				swap(v[child], v[parent]);
			}
			child = parent;
			parent = (child - 1) / 2;
		}
	}

	void AdjustDown(vector<HuffmanTreeNode<T>*> &v, int index, int parent = 0)//向下调整
	{
		int child = parent * 2 + 1;
		while (child <= index)
		{
			if (child + 1 <= index && v[child + 1]->m_val < v[child]->m_val)
			{
				child++;
			}
			if (v[child]->m_val < v[parent]->m_val)
			{
				swap(v[child], v[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
};

