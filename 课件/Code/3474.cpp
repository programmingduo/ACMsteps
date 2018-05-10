/*
̫�õ��뷨û�뵽
˼·����dfs+���仯����
solve(u,v)��ʾu��v����Ĵ�����
ans[i][j]�洢����i,j�Ľ�� 
*/
#include <iostream>
using namespace std;
#define maxn 2210
int n;
int ans[maxn][maxn];
int solve(int u,int v)
{
	//printf("%d----%d\n",u,v);
	if(ans[u][v]!=-1)
		return ans[u][v];
	int mid;
	if(v - u == 0)
	{
		ans[u][v] = 0;
		return 0;
	}
	else if(v - u == 1)
	{
		ans[u][v] = v*u;
		return v*u;
	}
	else
	{
		mid = (u+v)>>1;
		ans[u][v] = solve(u,mid)+solve(mid+1,v);
		return ans[u][v];
	}
}
int main()
{
	memset(ans,-1,sizeof(ans));
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",solve(1,n));
	}
	return 0;
}
