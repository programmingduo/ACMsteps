#include<cstdio>

inline long long max(long long x, long long y)
{
    return x>y? x: y;
}

long long dp[205][5];
int a[205];

int main ()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", a + i);

    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i = 1; i <= n; i ++)
    {
        dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
        if(a[i] & 1)
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
        else
            dp[i][1] = 0;
        if(a[i] & 1<<1)
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        else
            dp[i][2] = 0;
    }

//    for(int i = 1; i <= n; i ++)
//    {
//        for(int j = 0; j < 4; j ++)
//            printf("%I64d ", dp[i][j]);
//            printf("\n");
//    }

    long long ans = n - max(max(dp[n][0], dp[n][1]), dp[n][2]);
    printf("%I64d\n", ans);
    return 0;
}
