// L-D-R.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;
template<class T>
class Node
{
public:
	Node<T>* l = nullptr;
	Node<T>* r = nullptr;
	T data;
};
template <class T>
void LRD(Node<T>* root)
{
	if (root != nullptr)
	{
		LRD<T>(root->l);
		LRD<T>(root->r);
		cout << root->data;
	}
}
int n;
char LDR[1000], DLR[1000];
int num = 0;
template<class T>
void getRoot(Node<T>* node,int s,int e)
{
	node->data = DLR[num];
	int index=-1;
	int now = num;
	for (int j = s; j < e; j++)
	{
		if (LDR[j] == DLR[num])
		{
			index = j;
			break;
		}
	}
	if (index == -1)
		return;
	if (index != s)
	{
		++num;
		node->l = new Node<T>;
		getRoot<T>(node->l,s, index);
	}
	if (index != e - 1)
	{
		++num;
		node->r = new Node<T>;
		getRoot<T>(node->r,index + 1, e);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> DLR[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> LDR[i];
	}
	Node<char>* root = new Node<char>;
	getRoot<char>(root,0, n);
	LRD<char>(root);
}
