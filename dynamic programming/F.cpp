#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;

int main ()
{
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i ++)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int p[1005], h[1005], c[1005];
        int dp[100001];
        memset(dp, 0, sizeof(dp));
        int total = 0;
        for(int j = 0; j < m; j ++)
        {
            int a, b, x;
            scanf("%d%d%d", &a, &b, &x);
            for(int k = 0; k < x; k ++)
            {
                p[total] = a;
                h[total ++] = b;
            }
        }

        for(int j = 0; j < total; j ++)
            for(int k = n; k >= p[j]; k --)
                dp[k] = max(dp[k], dp[k - p[j]] + h[j]);

        printf("%d\n", dp[n]);
    }
}
