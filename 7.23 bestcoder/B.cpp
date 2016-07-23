#include<cstdio>

int dp[100005], a[100005];

int max(int x, int y)
{
    return x>y? x: y;
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
            dp[i] = 1;
        }

        for(int i = 1; i <= n; i ++)
        {
            for(int j = i - 1; j > 0; j --)
            {
                if(a[i] == a[j]+1)
                {
                    dp[i] = dp[j] + 1;
                    break;
                }
                if(a[i] == a[j])
                {
                    dp[i] = dp[j];
                    break;
                }
                if(a[i] > a[j])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
        }

        for(int i = 1; i <= n; i ++)
        {
            if(i > 1)
                printf(" ");
            printf("%d", dp[i]);
        }
        printf("\n");

    }
    return 0;
}
