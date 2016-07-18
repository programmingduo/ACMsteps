/*
简单的动态规划
也可以说是递推
dp[i][j]表示计算到第i行第j个元素的最优sum值 
可以观察dp[i][j]的结果只和之前一层dp[i-1][j-1],dp[i-1][j]有关
或者是从dp[i-1][j-1]传递过来，或者从dp[i-1][j]传递过来
所以我们只要一层一层算就好
最后统一最后一层dp[r-1][j]的最大值，就是答案 
*/
#include <iostream>
using namespace std;
#define maxn 30
int a[maxn][maxn];
int dp[maxn][maxn];
int R,sum;
int main()
{
	int i,j,sum;
	while(scanf("%d",&R)!=EOF)
	{
		for(i = 0; i < R ; i++)
		{
			for(j = 0; j <= i; j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		sum = -1;
		memset(dp,0,sizeof(dp));
		dp[0][0] = a[0][0];
		for(i = 1; i < R; i++)
		{
			for(j = 0; j <= i; j++)
			{
				if(j != i)
					dp[i][j] = max(dp[i][j],dp[i-1][j]+a[i][j]);
				if(j != 0)
					dp[i][j] = max(dp[i][j],dp[i-1][j-1]+a[i][j]);
			}
		}
		for(i=0;i<R;i++)
		{
			sum = max(sum,dp[R-1][i]);
		}
		printf("%d\n",sum);
	}
	return 0;
}
