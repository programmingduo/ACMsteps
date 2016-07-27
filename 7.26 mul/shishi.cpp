#include<cstdio>

int dp[40][2];

int main ()
{
    int n, m, k;
    while(~scanf("%d,%d,%d", &n, &m, &k) && n != -1)
    {
        dp[0][0] = dp[0][1] = 0;
        dp[1][0] = dp[1][1] = 1;
        for(int i = 2; i < 7; i ++)
        {
            dp[i][1] = 1;
            dp[i][0] = 0;
        }
        for(int i = 7; i <= k; i ++)
        {
            dp[i][0] = 0;
            if(dp[i-1][1] <= 100)
            {
                dp[i][0] += dp[i - 6][0];
                if(i >= 8)
                    dp[i][0] += dp[i-7][0];
                for(int j = 1; j <= m; j ++)
                {
                    if(i < 8+j)
                        break;
                    dp[i][0] += dp[i - 7 - j][0] * 2;
                }
            }
            dp[i][1] = dp[i-1][1] - dp[i - n][0] + dp[i][0];
        }

        for(int i = 1; i <= k; i ++)
        {
            printf("%d %d %d\n", i, dp[i][0], dp[i][1]);
        }
        printf("%d,%d,%d: %d\n", n, m, k, dp[k][1]);
    }
}
