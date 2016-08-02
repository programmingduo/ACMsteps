#include<cstdio>
#include<cstring>

int main ()
{
    long long dp[10005];
    int T;
    scanf("%d", &T);
    while(T --)
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        int n, w, v[30];

        scanf("%d%d", &n, &w);
        for(int i = 0; i < n; i ++)
            scanf("%d", &v[i]);

        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j + v[i] <= w; j ++)
                dp[j + v[i]] += dp[j];
        }
        printf("%lld\n", dp[w]);                       //注意数据类型
    }
    return 0;
}
