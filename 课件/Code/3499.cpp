#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 10010
int n,m,k;
int a,b;
int fa[maxn];
int find(int k)
{
	if(fa[k]==k)
		return k;
	else
		return fa[k] = find(fa[k]);
}
int main()
{
	int u,v;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		for(int i=0;i<n;i++)
		    fa[i] = i;
		while(m--)
		{
		    scanf("%d%d",&a,&b);
		    //合并集 
			u = find(a);
			v = find(b);
			if(u != v)
			    fa[u] = v;
		}
		while(k--)
		{
			scanf("%d%d",&a,&b);
			u = find(a);
			v = find(b);
			//查询两个集合在不在一个集合里 
			if(u ==  v)
			    printf("YES\n");
			else
				printf("NO\n");
		}
	}	
	return 0;	
}
