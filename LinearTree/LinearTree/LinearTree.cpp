
#include "pch.h"
#include <iostream>
template<class T>
class Node
{
public:
	Node<T>* l = nullptr;
	Node<T>* r = nullptr;
	T data;
	bool hasl = true;
	bool hasr = true;
};
int n;
int num = 0;
Node<char>* l[100];
template <class T>
void LDR(Node<T>* root,Node<T>* line[])
{
	if (root != nullptr)
	{
		LDR<T>(root->l,line);
		line[num++] = root;
		LDR<T>(root->r,line);
	}
}
template <class T>
void toLine(Node<T>* root, Node<T>* line[])
{
	if (root->l != nullptr)
	{
		toLine<T>(root->l, line);
	}
	else
	{
		root->hasl = false;
		for (int i = 0; i < n; i++)
		{
			if (line[i] == root)
			{
				if (i == 0)
				{
					root->l = nullptr;
				}
				else
				{
					root->l = line[i - 1];
				}
			}
		}
	}
	if (root->r != nullptr)
	{
		toLine<T>(root->r, line);
	}
	else
	{
		root->hasr = false;
		for (int i = 0; i < n; i++)
		{
			if (line[i] == root)
			{
				if (i == n-1)
				{
					root->r = nullptr;
				}
				else
				{
					root->r = line[i + 1];
				}
			}
		}
	}
}
int main()
{
	n = 5;
	Node<char>* A = new Node<char>;
	A->data = 'A';
	Node<char>* B = new Node<char>;
	B->data = 'B';
	Node<char>* C = new Node<char>;
	C->data = 'C';
	Node<char>* D = new Node<char>;
	D->data = 'D';
	Node<char>* E = new Node<char>;
	E->data = 'E';
	A->l = C;
	C->l = B;
	A->r = D;
	D->l = E;
	LDR(A, l);
	toLine(A, l);
}

