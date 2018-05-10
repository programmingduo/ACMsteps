#include <iostream>
#include <cstring>
using namespace std;
#define maxn 1002
int mp[maxn][maxn];
int t;
int n,m;
//***********************模板部分****************************
int dist[maxn];
void Dijkstra(int s,int numv)
{
	int i,j,k,dmin;
	int flag[maxn];	
	memset(flag,0,sizeof(flag));
	memset(dist,0x3f,sizeof(dist));
	dist[s] = 0;
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
			if(flag[j]==0&&dist[j]>mp[k][j]+dist[k])
				dist[j] = mp[k][j] + dist[k];
		}
	}
	return;
}
//***************************************************************
int main()
{
	int a,b,c,i,u,v;
	
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			memset(mp,0x3f,sizeof(mp));
			scanf("%d%d",&n,&m);
			scanf("%d%d",&u,&v);
			for(i=0;i<m;i++)
			{
				scanf("%d%d%d",&a,&b,&c);
				mp[a][b] = mp[b][a] = min(mp[a][b],c);
			}
			Dijkstra(u,n+1);
			if(dist[v]>=0x3f3f3f3f)//这个情况下是说明没有最短路的 
				printf("-1\n");
			else
				printf("%d\n",dist[v]);
		}
	}
	return 0;
}
