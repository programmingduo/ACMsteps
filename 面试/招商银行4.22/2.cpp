#include <cstdio>

int max(int a, int b)
{
    return a> b? a: b;
}

int x[1004];
int dp[1005][2];

int main ()
{
    int T, n, ans1, ans0;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &x[i]);
        }

        //1 no
        dp[0][0] = dp[0][1] = 0;
        for(int i = 1; i < n; i ++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + x[i];
        }
        ans0 = max(dp[n - 1][0], dp[n - 1][1]);

        dp[0][0] = 0;
        dp[0][1] = x[0];
        for(int i = 1; i < n; i ++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + x[i];
        }
        ans1 = dp[n - 1][0];

        printf("%d\n", max(ans1, ans0));
    }
    return 0;
}
