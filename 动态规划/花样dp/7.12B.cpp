#include<cstdio>
#include<algorithm>

int a[100008], dp[100005][3];

int min (int a, int b)
{
    return a< b? a: b;
}

int main ()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i = 0; i< n; i ++)
            scanf("%d", &a[i]);
        std::sort(a, a + n);
        dp[0][0] = -1;
        dp[0][1] = 0;
        for(int i = 1; i < n; i ++)
        {
            if(dp[i - 1][0] < 0)
                dp[i][0] = dp[i - 1][1] + a[i] - a[i - 1];
            else if(dp[i - 1][1] == -1)
                dp[i][0] = dp[i - 1][0] + a[i] - a[i - 1];
            else
                dp[i][0] = min(dp[i - 1][0] + a[i] - a[i - 1], dp[i - 1][1] + a[i] - a[i - 1]);
            if(dp[i - 1][0] == -1)
                dp[i][1] = -1;
            else
                dp[i][1] = dp[i - 1][0];
        }
        printf("%d\n", dp[n - 1][0]);
    }
    return 0;
}
