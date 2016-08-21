#include<cstdio>
#include<cstring>

using namespace std;

int a[100][1000];
int dp[1000];

int main ()
{
    int n, c;
    while(~scanf("%d%d", &n, &c))
    {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(int ) * n);
        int w[100], v;
        for(int i = 0; i < n; i ++)
        {
            scanf("%d%d", &w[i], &v);
            for(int j = c; j > 0; j --)
            {
                if(j >= w[i] && dp[j] < dp[j - w[i]] + v)
                {
                    a[i][j] = 1;
                    dp[j] = dp[j - w[i]] + v;
                }
            }
        }

        printf("%d", dp[c]);
        for(int i = n - 1; i >= 0; i --)
        {
            if(a[i][c])
            {
                printf(" %d", i);
                c -= w[i];
            }
        }
        printf("\n");
    }
    return 0;
}
