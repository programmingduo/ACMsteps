/*
根据题目描述，我们可以知道每个背包装的苹果数是一样的
当我们减去多余的苹果的时候，就是若干整袋的苹果
n-b1,m-b2的任意公约数都可以作为背包装苹果的数量，这里要求最多
自然就是最大公约数了
这个函数就是返回a,b的最大公约数 
int gcd(int a,int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b,a%b);
} 
*/
#include <iostream>
using namespace std;
int n,m,b1,b2;
int t;
int gcd(int a,int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b,a%b);
} 
int main()
{
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d%d%d%d",&n,&m,&b1,&b2);
			printf("%d\n",gcd(n-b1,m-b2));
		}
	}
	return 0;
}
