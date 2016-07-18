/*
这个题目的要求就是对于每个点ki，就出其到所有点中的最长距离Li 
最后选取最小的Li，输出ki和Li
题目注意如果这个没有办法连接到所有节点，输出 disjoint
题目叙述中此题图中为单向边
分析题目可以知道我们要知道每个点到所有点的最短距离
所以Dijkstra就不太适用了，选择floyd算法，能够计算出
每个点到所有点的最小距离，结点个数小于100个 1s内能计算完
所以设置好dist[i][j]（表示结点i到j的距离）
调用floyd()后，dist[i][j] 就表示结点i到j的最短距离
int dist[maxn][maxn];
void floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	return;
} 
*/ 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define maxn 102
int n;
//////////////////模板部分///////////////////////////////// 
int dist[maxn][maxn];
void floyd()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	return;
}
//////////////////模板部分/////////////////////////////////
int main()
{
	int m,u,len;
	while(scanf("%d",&n)&&n)
	{
		int i,j;
		memset(dist,0x3f,sizeof(dist));
		//根据题目要求设置图中边的信息 
		for(i=1;i<=n;i++)
		{
			dist[i][i] = 0;
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d%d",&u,&len);
				dist[i][u] = len; 
			}
		}
	    floyd();
	    int ans,sum,tmp,flag;
	    sum = 0x7f7f7f7f;
	    ans = -1;
	    for(i=1;i<=n;i++)
		{
			flag = 0;
			tmp = -1;
			for(j=1;j<=n;j++)
			{
				if(dist[i][j]==0x3f3f3f3f)
				{
					flag = -1;
					break;
				}
				else
					tmp = max(dist[i][j],tmp);
			}
			if(flag==0)
			{
				if(tmp<sum)
				{
				    ans = i;
				    sum = tmp;
				}
			}
		}
		if(ans == -1)
			printf("disjoint\n");
		else
			printf("%d %d\n",ans,sum); 
	}
	return 0;
}
