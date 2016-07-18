#include<cstdio>
#include<algorithm>
#include<string.h>

int n;
int color[205], graph[206][205], vis[205], link[205];

bool dfs(int index, int val)
{
    color[index] = val;
    bool flag = 1;
    for(int i = 1; i <= n && flag; i ++)
    {
        if(graph[i][index])
        {
            if(color[i] == 0)
                flag = dfs(i, -val);
            else if(color[i] == color[index])
                return false;
        }
    }
    return flag;
}

bool dfs1(int index)
{
    for(int i = 1; i <= n; i ++)
    {
        if(graph[index][i] && !vis[i])
        {
            vis[i] = 1;
            if(link[i] == 0 || dfs1(link[i]))
            {
                link[i] = index;
                return 1;
            }
        }
    }
    return 0;
}

int search()
{
    memset(link, 0, sizeof(link));
    int m = 0;
    for(int i = 1; i <= n; i ++)
    {
        memset(vis, 0, sizeof(vis));
        if(dfs1(i))
            m ++;
    }
    return m;
}

int main ()
{
    int m, t, a, b;
    while(~scanf("%d %d", &n, &m))
    {
        memset(graph, 0, sizeof(graph));
        memset(color, 0, sizeof(color));
        for(int i = 0; i < m; i ++)
        {
            scanf("%d %d", &a, &b);
            graph[a][b] = graph[b][a] = 1;
        }

        int flag = 1;
        for(int i = 1; i <= n && flag; i ++)
        {
            if(color[i])
                continue;
            flag = dfs(i, 1);
        }

        if(!flag)
        {
            printf("No\n");
            continue;
        }

        int ans = search();
        printf("%d\n", ans / 2);
    }
    return 0;
}
