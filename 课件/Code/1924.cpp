/*
最小生成树经典题目，理解好题目后直接套用模板就好
设置好边的权值信息，之后直接调用函数，numv参数为图中结点最大标号+1
dist[i]表示添加i结点增加的权值,所有的dist之和就是最小生成树的权值
void Prim(int numv)
{
	int i,j,k,dmin;
	int flag[maxn];	
	memset(flag,0,sizeof(flag));
	memset(dist,0x3f,sizeof(dist));
	dist[0] = 0;
	for(i=0;i<numv;i++)
	{
		dmin = 0x3f3f3f3f;
		k = -1;
		for(j=0;j<numv;j++)
		{
			if(flag[j]==0&&dmin > dist[j])
			{
				dmin = dist[j];
				k = j;
			}
		}
		if(k == -1)
			break;
		flag[k] = 1;
		for(j=0;j<numv;j++)
		{
			if(flag[j]==0&&dist[j]>mp[k][j])
				dist[j] = mp[k][j];
		}
	}
	return;
} 
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define maxn 30
using namespace std;
int mp[maxn][maxn];
int n,kk,l;
int dist[maxn];
void Prim(int numv)
{
	int i,j,k,dmin;
	int flag[maxn];	
	memset(flag,0,sizeof(flag));
	memset(dist,0x3f,sizeof(dist));
	dist[0] = 0;
	for(i=0;i<numv;i++)
	{
		dmin = 0x3f3f3f3f;
		k = -1;
		for(j=0;j<numv;j++)
		{
			if(flag[j]==0&&dmin > dist[j])
			{
				dmin = dist[j];
				k = j;
			}
		}
		if(k == -1)
			break;
		flag[k] = 1;
		for(j=0;j<numv;j++)
		{
			if(flag[j]==0&&dist[j]>mp[k][j])
				dist[j] = mp[k][j];
		}
	}
	return;
}
int main()
{
	char ch;
	int u,v,i,ans;
	while(scanf("%d",&n)&&n)
	{
		scanf("%c",&ch);//读掉换行符 
		memset(mp,0x3f,sizeof(mp));
		for(i=0;i<n-1;i++)
		{
			scanf("%c",&ch);
			u = ch - 'A';
			scanf("%d",&kk);
			for(int j=0;j<kk;j++)
			{
				scanf("%c%c",&ch,&ch);
				scanf("%d",&l);
				v = ch - 'A';
				mp[u][v] = mp[v][u] = l; 
			}
			scanf("%c",&ch);//读掉换行符 
		}
		//边权设置好 
		Prim(n);
		ans = 0;
		for(i=0;i<n;i++)
		{
			ans += dist[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
