#include<cstdio>
#include<cstring>

int main ()
{
    int N, M;
    int dp[102][102];
    char a[102][102];
    scanf("%d%d", &N, &M);
    getchar();
    for(int i = 1; i <= N; i ++)
    {
        for(int j = 1; j <= M; j ++)
            scanf("%c", &a[i][j]);
        getchar();
    }
    int x1, x2, y1, y2, flag = 0;

    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i ++)
        for(int j = 1; j <= M; j ++)
            if(a[i][j] == 'S')
                x1 = i, y1 = j;
            else if(a[i][j] == 'T')
                x2 = i, y2 = j;
    dp[x1][y1] = 1;
    for(int i = x1; i >= x2; i --)
        for(int j = y1; j <= y2; j ++)
            if(a[i][j] == '.')
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
            else if(a[i][j] == 'T')
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
    printf("%d\n", dp[x2][y2] % 1908);
    return 0;
}
