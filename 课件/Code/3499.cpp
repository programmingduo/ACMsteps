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
		    //�ϲ��� 
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
			//��ѯ���������ڲ���һ�������� 
			if(u ==  v)
			    printf("YES\n");
			else
				printf("NO\n");
		}
	}	
	return 0;	
}
