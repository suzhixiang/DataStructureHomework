// ConsoleApplication3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include<iostream>
using namespace std;
int a[10000];
int dsort(int i, int n)
{
	int min = i;
	int l = i * 2 + 1, r = i * 2 + 2;
	if (l<n&&a[l] < a[min])
	{
		min = l;
	}
	if (r<n&&a[r] < a[min])
	{
		min = r;
	}
	if (min != i)
	{
		swap(a[i], a[min]);
		dsort(min, n);
	}
	return 0;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = n ; i >= 0; i--)
	{
		dsort(i, n);
	}
	int sum = 0;
	while (n > 1)
	{
		swap(a[0], a[n - 1]);
		dsort(0, n - 1);
		a[0] += a[n - 1];
		sum += a[0];
		dsort(0, n - 1);
		n--;
	}
	cout << sum<<endl;
	return 0;
}