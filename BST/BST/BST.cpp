// BST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
template<class T>
class Node
{
public:
	T data;
	Node<T>* left = nullptr, *right = nullptr;
};
template<class T>
class BST
{
public:
	Node<T>* root=nullptr;
	void insert(Node<T>* n)
	{
		if (root == nullptr)
		{
			root = n;
			return;
		}
		Node<T>* temp = root;
		while (true)
		{
			if (temp->data > n->data)
			{
				if (temp->left == nullptr)
				{
					temp->left = n;
					return;
				}
				else
				{
					temp = temp->left;
				}
			}
			else
			{
				if (temp->right == nullptr)
				{
					temp->right = n;
					return;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	}
};
int main()
{
	BST<int> tree;
	Node<int> temp[11];
	for (int i = 0; i <= 10; i++)
	{
		temp[i].data = rand();
		tree.insert(&temp[i]);
	}
}
