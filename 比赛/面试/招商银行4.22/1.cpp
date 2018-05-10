#include <cstdio>
#include <string.h>

int v[200];
int dp[10005];

int main ()
{
    int T, n, k;
    scanf("%d", &T);
    while(T --)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &v[i]);
        }

        dp[0] = 1;
        for(int j = 0; j < n; j ++)

        {
            for(int i = 0; i <= k; i ++)
            {
                if(i + v[j] <= k)
                {
                    dp[i + v[j]] += dp[i];
                    dp[i + v[j]] %= 100000007;
                }
            }
        }

        printf("%d\n", dp[k]);
    }
    return 0;
}
