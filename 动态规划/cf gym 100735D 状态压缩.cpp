#include<cstdio>
#include<string.h>
#include<algorithm>

int a[20], b[20], dp[1<<16];
int n;

void mem(int x, int *c, int &cnt)
{
    for(int i = 0; i < n; i ++)
    {
        if(!(x & 1<<i))
            c[cnt ++] = i;
    }
}

int max(int a, int b)
{
    return a>b? a: b;
}

int main ()
{
    while(~scanf("%d", &n))
    {
        int ans = 0;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", a+i);
        }
        std::sort(a, a + n);
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for(int i =0 ; i < 1<<n; i ++)
        {
            if(dp[i] == -1)
                continue;
            int cnt = 0;
            mem(i, b, cnt);
            for(int j = 0; j < cnt; j ++)
            {
                for(int k = j + 1; k < cnt; k ++)
                {
                    for(int l = k + 1; l < cnt; l ++)
                    {
                        int t = i | 1<<b[j] | 1<<b[k] | 1<<b[l];
                        if(a[b[j]] + a[b[k]] <= a[b[l]])
                            break;
                        dp[t] = max(dp[t], dp[i] + 1);
                        ans = max(ans, dp[t]);
                    }
                }
            }

        }
        printf("%d\n", ans);
    }
}
