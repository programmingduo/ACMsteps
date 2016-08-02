#include<cstdio>

int main ()
{
    int T;
    while(T --)
    {
        scanf("%d %d", &n, &m);
        memset(dp, 0, sizeof(dp));
        memset(dpw, 0, sizeof(dpw));
        dp[0] = 1;
        dp[m - 1][m - 1] = 1;
        dp[m][m] = 1;
        for(int i = 1; i <= n; i ++)
        {
            dp[i] = dp[i - 1] + 1 - dpw[i - 1][m];
            if(i > m)
            {
                for(int j = m; j >= 1; j --)
                {
                    dpw[i][j] = dpw[i - 1][j] + 1 + dpw[i - 1][j - 1];
                }
            }
        }
    }
}
