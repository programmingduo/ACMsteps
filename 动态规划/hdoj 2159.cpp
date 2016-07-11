#include<cstdio>
#include<string.h>

inline int max(int a, int b)
{
    return a > b? a: b;
}

int p[105], w[105], dp[105][105];

int main ()
{
    int n, m, k, s, ans, flag, t;
    while(~scanf("%d%d%d%d", &n, &m, &k, &s))
    {
        flag = 0;
        ans = 0;
        for(int i = 0; i < k; i ++)
        {
            scanf("%d%d", &p[i], &w[i]);
        }
        memset(dp, 0, sizeof(dp));

        for(int i = m; i > 0; i --)
        {
            for(int j = 1; j <= s; j ++)
            {
                for(int l = 0; l < k; l ++)
                {
                    if(i < w[l])
                        continue;
                    t = dp[i - w[l]][j - 1] = max(dp[i - w[l]][j - 1], dp[i][j] + p[l]);
                    if(t >= n)
                    {
                        ans = max(ans, i - w[l]);
                        flag = 1;
                    }
                }
            }
        }
        if(flag)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
    return 0;
}
