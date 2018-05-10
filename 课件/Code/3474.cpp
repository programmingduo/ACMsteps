/*
太好的想法没想到
思路还是dfs+记忆化搜索
solve(u,v)表示u到v区间的处理结果
ans[i][j]存储区间i,j的结果 
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
