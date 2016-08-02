#include<cstdio>
#include<string.h>
#include<algorithm>

long long dp[505][505], a[505];

long long inline min (long long a, long long b)
{
    return a > b? b: a;
}

int main ()
{
    int T, n, d;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &n, &d);
        for(int i = 1; i <= n; i ++)
            scanf("%lld", &a[i]);
        std::sort(a + 1, a + 1 + n);

        for(int i = 0; i <= d; i ++)
            for(int j = 0; j <= n; j ++)
            dp[i][j] = 1000000000009;
        dp[0][0] = 0;
//            printf("%lld ", dp[d][n]);
        for(int i = 1; i <= d; i ++)
        {
            for(int j = 1; j <= n; j ++)
            {
                for(int k = 0; k < j; k ++)
                {
                    dp[i][j] = min(dp[i - 1][k] + (a[j] - a[k + 1]) * (a[j] - a[k + 1]), dp[i][j]);
                }
            }
        }
        printf("%lld\n", dp[d][n]);
    }
    return 0;
}
