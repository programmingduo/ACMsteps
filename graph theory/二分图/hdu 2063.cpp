#include<cstdio>
#include<string.h>

int graph[600][600], link[600], vis[600];

bool dfs(int i, int n)
{
    for(int j = 1; j <= n; j ++)
    {
        if(graph[i][j] && vis[j] == 0)
        {
            vis[j] = 1;
            if(link[j] == 0 || dfs(link[j], n))
            {
                link[j] = i;
                return 1;
            }
        }
    }
    return 0;
}

int search(int n, int k)
{
    memset(link, 0, sizeof(link));
    int m = 0;
    for(int i = 1; i <= n; i ++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs(i, k))
            m ++;
    }
    return m;
}

int main ()
{
    int k, n, m, a, b;
    while(~scanf("%d", &k) && k)
    {
        scanf("%d %d", &n, &m);
        memset(graph, 0, sizeof(graph));
        for(int i = 0; i < k; i ++)
        {
            scanf("%d %d", &a, &b);
            graph[a][b] = 1;
        }
        int ans = search(n, m);
        printf("%d\n", ans);
    }
    return 0;
}
