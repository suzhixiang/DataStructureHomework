/*================================================================
作者：	苏志翔
问题：	两个杯子倒出指定升水
输入：	两个杯子a,b体积V1，V2，目标升数aim
思路：	通过扩展欧几里得，得到V1x+V2y=aim的解（为方便讨论，我们设x正，y负）
		因为两个杯子中水的总数是固定的，我们只需倒入x次，倒出y次。
		此时情况分为三种：
			1.	a满，倒出，x-1
			2.	b空，倒入，y+1
			3.	其他情况，将b倒入a
		可以证明，在任何情况下必有至少一个杯子是满的或者空的，所以的解
注意：	若aim>V1+V2或者aim<0或者aim%gcd(V1,V2) != 0，则无解。
======================================================================*/
//#include "pch.h"
#include <iostream>
#include<algorithm>
using namespace std;
int V1, V2, aim;
int exgcd(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int q = exgcd(b, a%b, y, x);
	y -= a / b * x;
	return q;
}
int main()
{
	cin >> V1 >> V2 >> aim;
	int x, y;
	int L1 = 0, L2 = 0;
	int d = exgcd(V1, V2, x, y);
	if (aim > V1 + V2 || aim%d != 0||aim<0)
	{
		cout << "NO SOLUTION" << endl;
		
	}
	else
	{
		x = x * aim / d;
		y = y * aim / d;
		while (x != 0 || y != 0)
		{
			cout << L1<< "\t" << L2 
				//<<"\t"<<x<<"\t"<<y
				<< endl;
			if (x > 0 && L1 == 0)
			{
				x--;
				L1 = V1;
			}
			else if (x < 0 && L1 == V1)
			{
				x++;
				L1 = 0;
			}
			else if (y > 0 && L2 == 0)
			{
				y--;
				L2 = V2;
			}
			else if (y < 0 && L2 == V2)
			{
				y++;
				L2 = 0;
			}
			else
			{
				if (x>0||y<0)
				{
					int L2t = min(L1 + L2, V2);
					int L1t = max(0, L1 + L2 - V2);
					L1 = L1t;
					L2 = L2t;
				}
				else
				{
					int L1t = min(L1 + L2, V1);
					int L2t = max(0, L1 + L2 - V1);
					L1 = L1t;
					L2 = L2t;
				}
			}
		}
		cout << L1 << "\t" << L2 
			//<< "\t" << x << "\t" << y 
			<< endl;
	}
}

