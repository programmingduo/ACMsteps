#include <iostream>
#include <cstring>
using namespace std;
#define maxn 102
int mp[maxn][maxn];
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
	int a,b,c,i;
	while(scanf("%d%d",&n,&m))
	{
		if(m==0&&n==0)
			break;
//		边的始初化 
		memset(mp,0x3f,sizeof(mp));
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			mp[a][b] = mp[b][a] = min(c,mp[a][b]);
		}
		Dijkstra(1,n+1);
		printf("%d\n",dist[n]);
	}
	return 0;
}
