/*
此题为并查集的基本应用
对于成为朋友的两个人，要查找他们所在集合的祖先
即： father1 = find(a);
	 father2 = find(b);
如果father1 == father2说明在一个集合里，不用进行操作
如果father1 ！= father2 说明不再一个集合里，要进行合并操作
fa[father1] = father2 此操作将两个集合进行合并
在处理完m次关系后，我们要查询有多少个不同的集合，就等价于查找所有元素有多少个不
同的祖先 
所以 
memset(ans,0,sizeof(ans));
for(i=1;i<=n;i++)
{
	father1 = find(i);
	if(ans[father1]==0)
	{
		sum++;
		ans[father1] = 1;
	}
}
*/ 
#include <iostream>
using namespace std;
#define maxn 102
int caseT;
int fa[maxn];
int ans[maxn];
int sum;
//查找祖先的函数 
int find(int k)
{
	//集合中祖先结点一定是其本身 
	if(fa[k] == k)
		return k;
	else
		return fa[k] = find(fa[k]); 
}
int n,m,a,b;
int main()
{
	int i,father1,father2;
	while(scanf("%d",&caseT)!=EOF)
	{
		while(caseT--)
		{
			scanf("%d%d",&n,&m);
		//初始化每个结点最开始的父亲结点是其本身 
			for(i=1;i<=n;i++)
				fa[i] = i;
			for(i=0;i<m;i++)
			{
				scanf("%d%d",&a,&b);
				father1 = find(a);
				father2 = find(b);
				if(father1 != father2)
				{
					fa[father1] = father2;
				}
			}
			sum = 0;
			memset(ans,0,sizeof(ans));
			for(i=1;i<=n;i++)
			{
				father1 = find(i);
				if(ans[father1]==0)
				{
					sum++;
					ans[father1] = 1;
				}
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
