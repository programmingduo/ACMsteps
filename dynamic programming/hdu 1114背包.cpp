#include<cstdio>

const int maxn = 0x3fffffff;
int p[1000006], w[1000006], dp[10004];

inline int min(int a, int b)
{
    return a < b ? a: b;
}

int main ()
{
    int T, v, a, b, n;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &a, &b);
        v = b - a;
        scanf("%d", &n);
        for(int i = 0; i < n; i ++)
        {
            scanf("%d%d", &p[i], &w[i]);
        }
        for(int i = 0; i < v; i ++)
            dp[i] = maxn;
        dp[v] = 0;
        for(int j = v; j > 0; j --)
        {
            if(dp[v] == maxn)
                continue;
            for(int i = 0; i < n; i ++)
            {
                if(j - w[i] < 0)
                    continue;
                dp[j - w[i]] = min(dp[j] + p[i], dp[j - w[i]]);
            }
        }
        if(dp[0] == maxn)
            printf("This is impossible.\n");
        else
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[0]);
    }
    return 0;
}
