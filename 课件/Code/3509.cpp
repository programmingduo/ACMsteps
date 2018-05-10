/*
题目要求能够组合出任意1到N的数字
篮子要满足1,2,4,8,..2^n这样才能满足要求（这个可以当做结论记住） 
如果m个篮子如此存放苹果的总和等于N，说明只有一种
如果m个篮子如此存放苹果的总和大于N，说明只有不止一种
解释如下：
取若干个篮子要求满足1,2,4,8,..2^n，这样必然会剩下空的篮子或者小于2^n的篮子
其实我们只要之前的满足要求的篮子就可以了。剩下的篮子我们可以随意存放苹果。
这样就是many了
如果m个篮子如此存放苹果的总和小于N，那么一定不会存在满足题目要求的存放方式
ps：
(1)这里的要注意的地方
2^n 当n很大的时候，值的范围超过int了（int的范围-2^31——2^31-1） 
但是我们只考虑最后的sum值和N（N的范围很小）的关系，我们没有必要计算2^n（当n很大的时候） 
只要计算出知道大于，等于，小于的关系就好
(2)位运算
1<<i 表示 1*2^(i-1) 
1>>i 表示 1/(2^(i-1))
这样写起来比较方便  
*/
#include <iostream>
using namespace std;
int n,m;
int main()
{
	int i,sum,flag;
	while(scanf("%d%d",&n,&m))
	{
		sum = 0;
		flag = 0;
		if(m == 0 && n == 0)
			break;
		for(i=0;i<m;i++)
		{
			sum += (1<<i);
			if(sum > n)
			{
				flag = 1;
				break;
			}
			else if(sum == n)
			{
				if(i==m-1)
					flag = 2;
				else
					flag = 1;
				break;
			}
		}
		if(flag == 1)
		{
			printf("Yes,many.\n");
		}
		else if(flag == 2)
		{
			printf("Yes,only one.\n");
		}
		else
		{
			if(sum == n)
				printf("Yes,only one.\n");
			else if(sum > n)
				printf("Yes,many.\n");
			else
				printf("No.\n");
		}
	}
	return 0;
}
