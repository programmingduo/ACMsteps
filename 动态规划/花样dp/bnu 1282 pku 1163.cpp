#include<cstdio>
#include<algorithm>

int main ()
{
    int N, num[105][105], dp[105][105];
    scanf("%d", &N);
    for(int i = 0; i < N; i ++)
        for(int j = 0; j <= i; j ++)
    {
        scanf("%d", &num[i][j]);
    }

    for(int i = 0; i < N; i ++)
        dp[N - 1][i] = num[N - 1][i];
    for(int i = N - 2; i >= 0; i --)
        for(int j = 0; j <= i; j ++)
    {
        dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j + 1]) + num[i][j];
    }

    printf("%d\n", dp[0][0]);
    return 0;
}
