#include<cstdio>
#include<string.h>

const int maxn = 1000005;
int a[maxn], in[maxn], sum[maxn];
int pre[maxn], num[maxn];
long long dp[maxn];

int main ()
{
    int n, m, w;
    while(~scanf("%d", &n) && n)
    {
        for(int i = 0; i< n; i ++)
        {
            scanf("%d", &a[i]);
        }


        memset(in, 0, sizeof(in));
        num[0] = 0;
        for(int i = n - 1; i >= 0; i --)
        {
            if(!in[a[i]])
                num[n - i] = num[n - i - 1] + 1;
            else
                num[n - i] = num[n - i - 1];
            in[a[i]] ++;
        }

        memset(pre, -1, sizeof(pre));
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n; i ++)
        {
            sum[i - pre[a[i]]] ++;
            pre[a[i]] = i;
        }

        for(int i = n - 1; i > 0; i --)
        {
            sum[i] += sum[i + 1];
        }

        dp[1] = n;
        for(int i = 2; i <= n; i ++)
        {
            dp[i] = dp[i - 1] + sum[i] - num[i - 1];
        }
        scanf("%d", &m);
        while(m --)
        {
            scanf("%d", &w);
            printf("%I64d\n", dp[w]);
        }
    }
    return 0;
}


