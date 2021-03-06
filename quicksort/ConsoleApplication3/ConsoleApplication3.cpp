// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<algorithm>
#include<stack>
using namespace std;
class s_e
{
public:
	s_e(int s, int e)
	{
		this->s = s;
		this->e = e;
	}
	int s, e;
};
stack<s_e*> st;
template<class T>
int check(T *arr, int s, int e)
{
	int x1 = s - 1;
	for (int i = s; i < e; i++)
	{
		if (arr[i] < arr[e])
		{
			x1++;
			swap(arr[i], arr[x1]);
		}
	}
	x1++;
	swap(arr[x1], arr[e]);
	return x1;
}
template<class T>
void quicksort(T *arr)
{
	while (!st.empty())
	{
		s_e* temp = st.top();
		st.pop();
		int s = temp->s;
		int e = temp->e;
		if (s < e)
		{
			int mid = check(arr,s,e);
			st.push(new s_e(s, mid - 1));
			st.push(new s_e(mid + 1, e));
		}
	}
	
}

int main()
{
	int a[101];
	for (int i = 0; i < 101; i++)
	{
		a[i] = rand();
	}
	st.push(new s_e(0, 100));
	quicksort(a);
	cout << endl;
}

