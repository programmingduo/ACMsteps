#include<cstdio>
#include<string.h>

const int mod = 1000000007;
int a[1005], b[1005];
long long dp[1005][1005];

int main ()
{
    int n, m;
    while(~scanf("%d %d", &n, &m))
    {
        for(int i = 1; i <= n;i  ++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d", &b[i]);
        }

        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i ++)
        {
            for(int j = 1; j <= m; j ++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
                if(a[i] == b[j])
                    dp[i][j] += dp[i - 1][j - 1] + 1;
                dp[i][j] = (dp[i][j] + mod) % mod;
            }
        }
//        for(int i = 1; i <= n; i ++)
//        {
//            for(int j = 1; j <= m; j ++)
//            {
//                printf("%d ", dp[i][j]);
//            }
//            printf("\n");
//        }
        printf("%I64d\n", dp[n][m]);
    }
    return 0;
}
