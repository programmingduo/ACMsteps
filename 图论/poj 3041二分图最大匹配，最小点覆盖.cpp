#include<cstdio>
#include<string.h>

int map[505][505];
int vis[505], link[505];

int dfs(int i, int N)
{
    for(int j = 1; j <= N; j ++)
    {
        if(map[i][j] && vis[j] == 0)
        {
            vis[j] = 1;
            if(link[j] == 0 || dfs(link[j], N))
            {
                link[j] = i;
                return 1;
            }
        }
    }
    return 0;
}

int search(int N)
{
    memset(link, 0, sizeof(link));
    int m = 0;
    for(int i = 1; i <= N; i ++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(i, N))
            m ++;
    }
    return m;
}

int main()
{
    int N, K;
    int a, b;
    while(~scanf("%d%d", &N, &K))
    {
        while(K --)
        {
            scanf("%d%d", &a, &b);
            map[a][b] = 1;
        }
        int ans = search(N);
        printf("%d\n", ans);
    }
    return 0;
}
