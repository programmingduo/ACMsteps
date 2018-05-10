#include<iostream>
#include<stdio.h>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;
vector<int>ar[240010];
int mark[240010],ma,s,st[240010],last,fa[240010];
void bfs (int a)
{
	int i,b;
	queue<int>q;
	mark[a]=1;
	fa[a]=a;
	q.push(a);
	while (!q.empty())
	{
		a=q.front();
		q.pop();
		for (i=0;i<ar[a].size();i++)
		{
			b=ar[a][i];
			if (!mark[b])
			{
				q.push(b);
				fa[b]=a;
				mark[b]=1;
			}
		}
	}
	s=a;
}
int main ()
{
	int t,n,i,a;
	bool flag;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			ar[i].clear();
		for (i=2;i<=n;i++)
		{
			scanf("%d",&a);
			ar[i].push_back(a);
			ar[a].push_back(i);
		}
		memset(mark,0,sizeof(mark));
		bfs(1);
		last=0;
		memset(mark,0,sizeof(mark));
		bfs(s);
		for (i=s;fa[i]!=i;i=fa[i])
			st[last++]=i;
		st[last++]=i;
		if (last%2==0)
			printf("%d %d\n",min(st[last/2],st[last/2-1]),max(st[last/2],st[last/2-1]));
		else
			printf("%d\n",st[last/2]);
	}
	return 0;
}