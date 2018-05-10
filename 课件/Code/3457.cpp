/*
�򵥵Ķ�̬�滮
Ҳ����˵�ǵ���
dp[i][j]��ʾ���㵽��i�е�j��Ԫ�ص�����sumֵ 
���Թ۲�dp[i][j]�Ľ��ֻ��֮ǰһ��dp[i-1][j-1],dp[i-1][j]�й�
�����Ǵ�dp[i-1][j-1]���ݹ��������ߴ�dp[i-1][j]���ݹ���
��������ֻҪһ��һ����ͺ�
���ͳһ���һ��dp[r-1][j]�����ֵ�����Ǵ� 
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
