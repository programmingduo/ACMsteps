#include<cstdio>
#include<string.h>

int num[105][105], dp[105][105];
int max(int a, int b)
{
    return a > b? a: b;
}

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= i; j ++)
        scanf("%d", &num[i][j]);
        memset(dp, 0, sizeof(dp));
        dp[1][1] = num[1][1];
        for(int i = 1; i < n; i ++)
        {
            for(int j = 1; j <= i; j ++)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + num[i + 1][j]);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + num[i + 1][j + 1]);
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++)
            ans = max(dp[n][i], ans);
        printf("%d\n", ans);
    }
}
