#include<cstdio>
#include<string.h>

int a[25],b[25];
int dp[22][22][22][22];
int sum1[25], sum2[25];

int max(int x, int y)
{
    return x > y? x: y;
}
int min(int x, int y)
{
    return x< y? x: y;
}
void dfs(int l1, int r1, int l2, int r2)
{
    if(l1 > r1 && l2 == r2)
    {
        dp[l1][r1][l2][r2] = b[l2];
        return ;
    }
    if(l1 == r1 && l2 > r2)
    {
        dp[l1][r1][l2][r2] = a[l1];
        return ;
    }

    int ans = 0x3fffffff;
    if(r1 >= l1)
    {
        if(!dp[l1 + 1][r1][l2][r2])
            dfs(l1 + 1, r1, l2, r2);
        ans = min(ans, dp[l1 + 1][r1][l2][r2]);

        if(!dp[l1][r1 - 1][l2][r2])
            dfs(l1, r1 - 1, l2, r2);
        ans = min(ans, dp[l1][r1 - 1][l2][r2]);
    }

    if(r2 >= l2)
    {
        if(!dp[l1][r1][l2 + 1][r2])
            dfs(l1, r1, l2 + 1, r2);
        ans = min(ans, dp[l1][r1][l2 + 1][r2]);

        if(!dp[l1][r1][l2][r2 - 1])
            dfs(l1, r1, l2, r2 - 1);
        ans = min(ans, dp[l1][r1][l2][r2 - 1]);
    }
    int res = 0;
    if(l1 <= r1) res = sum1[r1] - sum1[l1 - 1];
    if(l2 <= r2) res += sum2[r2] - sum2[l2 - 1];
    res -= ans;

    dp[l1][r1][l2][r2] = res;
}

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &b[i]);
        }

        sum1[0] = sum2[0] = 0;
        for(int i = 1; i <= n; i ++)
        {
            sum1[i] = sum1[i - 1] + a[i];
        }
        for(int i =  1; i <= n; i ++)
        {
            sum2[i] = sum2[i - 1] + b[i];
        }

        memset(dp, 0, sizeof(dp));
        dfs(1, n, 1, n);
//        for(int i = 1; i <= n; i ++)
//        {
//            for(int ii = 1; ii <= n; ii ++)
//            {
//                for(int j = 1; j <= n; j ++)
//                {
//                    for(int jj = 1; jj <= n; jj ++)
//                    {
//                        printf("%d %d %d %d %d\n", i, ii, j, jj, dp[i][ii][j][jj]);
//                    }
//                }
//            }
//        }
        printf("%d\n", dp[1][n][1][n]);
    }
    return 0;
}
