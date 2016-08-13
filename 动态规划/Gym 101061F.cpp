#include<cstdio>
#include<cstring>
int min (int x, int y)
{
    return x< y? x: y;
}
int max(int x, int y)
{
    return x> y? x: y;
}
int dp[104][10004][2], ans[104][10004][2], a[1000];

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = dp[0][0][1] = 1;
        for(int i = 0; i <= n; i ++)
        {
            for(int j = 0; j < 10002; j ++)
            {
                for(int k = 0; k < 2; k ++)
                    ans[i][j][k] = 0x3fffffff;
            }
        }
        ans[0][0][0] =  ans[0][0][1] = 0;
//        printf("%d\n", ans[0][0][0]);
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j <= 10000; j ++)
            {
                for(int k = 0; k < 2; k ++)
                {
                    if(dp[i][j][k])
                    {
//                        printf("%d\n", ans[i][j][k]);
                        if(j >= a[i + 1])
                        {
                            dp[i + 1][j - a[i + 1]][k] = 1;
                            int t = ans[i + 1][j - a[i + 1]][k] = min(ans[i][j][k], ans[i + 1][j - a[i + 1]][k]);
//                            printf("1 %d \n", ans[i + 1][j - a[i +1]][k]);
                        }
                        else
                        {
                            dp[i + 1][a[i + 1] - j][k ^ 1] = 1;
                            int t = ans[i + 1][a[i + 1] - j][k ^ 1] = min(max(ans[i][j][k], a[i + 1] - j), ans[i + 1][a[i + 1] - j][k ^ 1]);
                        }
                        dp[i + 1][j + a[i + 1]][k] = 1;
                        int t = ans[i + 1][j + a[i + 1]][k] = min(max(ans[i][j][k], j + a[i + 1]), ans[i + 1][j + a[i + 1]][k]);
//                        printf("2 %d \n", ans[i + 1][j + a[i +1]][k]);
                    }
                }
            }
        }
        int p = 0x3fffffff;
        for(int i = 100 * n; i > 0; i --)
        for(int k = 0; k <2; k ++)
            if(dp[n][i][k])
                p = min(p, ans[n][i][k]);

        printf("%d\n", p);
    }
}
