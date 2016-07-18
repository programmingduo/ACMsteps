/*
题目要求：brent遍历所有的城市，并且找到汽车必须的最小花费
遍历所有城市：树的结构连接了所有的结点，而且没有重复的边，这里我们只要考虑树的边
权值越小越好，所以就是最小生成树，但是我们要求达到所有的城市，所以我们要满足树中
的最长边即可，也就是克鲁斯卡尔算法中加入的最后一条边 
最小生成树
解法:克鲁斯卡尔 + 并查集
注意:题目中说明每两个结点之间最多只有一条边
		如果没有说明要每次更新边的获得两点之间最小值
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 202
#define maxm 20005
int caseT,N,m;
struct Edge
{
	int u,v,w;
}edge[maxm];
bool cmp(Edge e1,Edge e2)
{
	return e1.w < e2.w;
}
//********************************
//并查集部分 
int fa[maxn];
int find(int k)
{
	if(fa[k] == k)
		return k;
	else
		return fa[k] = find(fa[k]);
}
//********************************
int main()
{
	int i,cnt,ans;
	int father1,father2;
	while(scanf("%d",&caseT)!=EOF)
	{
		while(caseT--)
		{
			scanf("%d%d",&N,&m);
			for(i=0;i<m;i++)
			{
				scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
			}
			//并查集初始化祖先
			for(i=1;i<=N;i++)
				fa[i] = i;
			cnt  = 0;
			sort(edge,edge+m,cmp);
			for(i=0;i<m;i++)
			{
				//看加入的两个结点是不是在一个集合里 
				father1 = find(edge[i].u);
				father2 = find(edge[i].v);
				if(father1!=father2)
				{
					fa[father1] = father2;
					cnt++;
				}
				if(cnt == N - 1)
				{
					ans = edge[i].w;
					break;
				}
			}
			if(cnt!=N-1)
				printf("-1\n");
			else if(ans%10!=0)
				printf("%d\n",ans/10+1);
			else
				printf("%d\n",ans/10);
		}
	}
	return 0;
}
