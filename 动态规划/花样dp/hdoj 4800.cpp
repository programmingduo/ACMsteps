#include<cstdio>
#include<string.h>

double p[1000][1000], dp[10022][150];
int a[10005];

double max(double x, double b)
{
    return x>b? x: b;
}

int main ()
{
    int n, m;
    while(~scanf("%d", &n))
    {
        n = n * (n - 1) * (n - 2) / 6;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                scanf("%lf", &p[i][j]);

        scanf("%d", &m);
        for(int i = 1; i <= m; i ++)
            scanf("%d", &a[i]);

        memset(dp, 0, sizeof(dp));
        for(int i = 0; i <= n; i ++)
            dp[0][i] = 1;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++)
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] * p[j][a[i + 1]]);
                dp[i + 1][a[i + 1]] = max(dp[i + 1][a[i + 1]], dp[i][j] * p[j][a[i + 1]]);
            }
        printf("%.6lf\n", dp[m][a[m]]);
    }
    return 0;
}
