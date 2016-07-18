#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[2005][2];

int main ()
{
    int M, N, W, A, B, T, ans;
    scanf("%d", &T);
    while(T --)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &M, &N);
        for(int i = 0; i < N; i ++)
        {
            scanf("%d%d%d", &W, &A, &B);
            for(int j = 1; j <= M; j ++)
            {
                dp[j][0] = max(dp[j][0], dp[j][1]);
                if(j >= W)
                    dp[j][1] = max(dp[j - W][0] + A + B, dp[j - W][1] + A);
            }
        }

        ans = 0;
        for(int i = 1; i <= M; i ++)
            for(int j = 0; j < 2; j ++)
            ans= max(dp[i][j], ans);
        printf("%d\n", ans);
    }
}
