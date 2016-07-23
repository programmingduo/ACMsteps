#include<cstdio>
#include<string.h>

int dp[6006][2], a[20000];
int vis[6006], fa[60006];
int N;

int max(int x, int y)
{
    return x>y? x: y;
}

void dfs(int n)
{
    vis[n] = 1;
    for(int i = 1; i <= N; i ++)
    {
        if(fa[i] == n)
        {
            if(!vis[i])
                dfs(i);
            dp[n][1] = max(dp[n][1], dp[i][0]+dp[n][1]);
            dp[n][0] = max(dp[i][0], dp[i][1]) + dp[n][0];
        }
    }
    return ;
}

int main ()
{
    int x, y;
    memset(fa, 0, sizeof(fa));
    scanf("%d", &N);
    for(int i = 1; i <= N; i ++)
    {
        vis[i] = 0;
        scanf("%d", a+i);
        dp[i][0] = 0;
        dp[i][1] = a[i];
    }

    while(~scanf("%d %d", &x, &y))
    {
        if(x == 0 && y == 0)
            break;
        fa[x] = y;
    }
    for(int i = 1; i <= N; i ++)
    {
        if(fa[i] == 0)
        {
            dfs(i);
            printf("%d\n", max(dp[i][0], dp[i][1]));
            break;
        }

    }
    return 0;
}
