#include<cstdio>

int main ()
{
    int N;
    int num[100][100], dp[100][100];
    for(int i = 0; i < N; i ++)
    {
        for(int j = 0; j <= i; j ++)
        {
            scanf("%d", &num[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = a[0][0];
    for(int i = )
}
