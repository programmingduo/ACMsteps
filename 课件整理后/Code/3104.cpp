/*
结点'a'-'z','A'-'Z',将'A'-'Z'映射到0-25，'a'-'z'映射到26-51，所以最多52个点，
'Z'是原点，最后求得原点到'A'-'Y'结点的最短距离最小值，注意下多重边的问题，
每次更新最小值
当边的信息设置好以后，就可以调用 Dijkstra(int s,int numv) 其中s是原点，
numv是结点个数（结点标号最大值+1） 
*/
#include <iostream>
#include <cstring>
using namespace std;
#define maxn 60
int n;
char u,v;
int w,a,b;
int ans1;
int mp[maxn][maxn];
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
int main()
{
	int i,dmin;
	while(scanf("%d",&n)!=EOF)
	{
		memset(mp,0x3f,sizeof(mp));
		for(i=0;i<n;i++)
		{
			cin>>u>>v>>w;
			if(u>='A'&&u<='Z')
				a = u - 'A';
			if(u>='a'&&u<='z')
				a = u - 'a' + 26;
			if(v>='A'&&v<='Z')
				b = v - 'A';
			if(v>='a'&&v<='z')
				b = v - 'a' + 26;
			mp[a][b] = mp[b][a] = min(mp[a][b],w);
		}
		Dijkstra('Z'-'A',52);
		dmin = 0x7f7f7f7f;
		for(i=0;i<25;i++)
		{
			if(dmin > dist[i])
			{
				ans1 = i;
				dmin = dist[i];
			}
		}
		printf("%c %d\n",ans1+'A',dmin);
	}
	return 0;
}
