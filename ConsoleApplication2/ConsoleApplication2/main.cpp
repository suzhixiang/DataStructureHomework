/*=========================================
作者：苏志翔
内容：	DoubleLinkedList<T>
		Stack<T>
		Queue<T>
IDE：	VS2017
未解决的问题：include"*.h"会引起外部错误
===========================================*/
#include "pch.h"
#include <iostream>
#include"DoubleLinkedList.cpp"
#include"stack.cpp"
#include"Queue.cpp"
using namespace std;
int main()
{
	//双向链表测试
	DoubleLinkedList<double> list;
	list.add(1, true);
	list.add(1, true);
	list.add(2, true);
	list.add(3, true);
	list.delet(list.search(2));
	list.delet(list.search(3));
	list.delet(list.search(1));
	list.delet(list.search(1));
	cout << endl;
	//Stack测试
	Stack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.pop();
	cout << stack.size() << endl;
	stack.push(3);
	cout << endl;
	//Queue测试;
	Queue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.pop();
	cout << queue.size() << endl;
	queue.push(3);
	cout << endl;
}
