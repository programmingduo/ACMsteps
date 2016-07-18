#include<cstdio>
#include<string.h>

#define mod 1000000007

long long dp[2][100010], a[10005];

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        long long t = n * 4, temp, ans = 1, last = 0, now = 1;
        for(int i = 1; i <= n; i ++)
            scanf("%lld", &a[i]);
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j <= 20010; j ++)
            {
                temp = j ^ a[i + 1];
                dp[now][j] = dp[last][j] + dp[last][temp] + dp[last][temp];
                dp[now][j] %= mod;
            }
            now ^= 1;
            last ^= 1;
        }
        printf("%lld\n", dp[last][0]);
    }
}
