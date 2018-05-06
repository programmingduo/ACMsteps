#include <cstdio>
#include <string.h>

int dp[100005], a[104], b[104], vis[105];

int main ()
{
    int n1, n2, m;
    while(~scanf("%d %d %d", &n1, &n2, &m))
    {
        memset(dp, 0, sizeof(0));
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n1; i ++)
            scanf("%d", &a[i]);
        for(int i = 0; i < n2; i ++)
            scanf("%d", &b[i]);

        dp[0] = 1;
        for(int i = 0; i < n2; i ++)
        {
            for(int j = m - b[i]; j >= 0; j --)
            {
                dp[j + b[i]] += dp[j];
                dp[j + b[i]] %= 1000000007;
            }
        }


        for(int j = 0; j < n1; j ++)
        {
            for(int i = 0; i < m; i ++)
            {
                if(i + a[j] <= m)
                {
                    dp[a[j] + i] += dp[i];
                    dp[a[j] + i] %= 1000000007;
                }
                else
                    break;
            }
        }
        printf("%d\n", dp[m]);
    }

}
