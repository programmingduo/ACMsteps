#include<cstdio>
#include<string.h>

//此题利用tarjan求加多少条边可以得到双连通分量

struct node
{
    int to, next;
}edge[3000];
int dfn[1005], vis[1005], low[1004], head[1005], in[1005];
int time, n, edge_total;

void addEdge(int a, int b)
{
    edge[edge_total].to = a;
    edge[edge_total].next = head[b];
    head[b] = edge_total ++;

    edge[edge_total].to = b;
    edge[edge_total].next = head[a];
    head[a] = edge_total ++;
}

void tarjan_init()
{
    memset(vis, 0, sizeof(vis));
    memset(dfn, 0, sizeof(dfn));
    memset(in, 0, sizeof(in));
    time = 1;
}

int min(int a, int b)
{
    return a<b? a: b;
}

void dfs(int id, int fa)
{
//    printf("%d %d\n", id, fa);
    dfn[id] = low[id] = time ++;
    vis[id] = 1;
    for(int i = head[id]; i != -1; i = edge[i].next)
    {
        int t = edge[i].to;
        if(t == fa)
            continue;
        //因为建边的时候建的是双向边，因此必须检测这条边是否指向他的父亲
        if(!vis[t])
        {
            dfs(t, id);
            low[id] = min(low[id], low[t]);
        }
        else
        {
            low[id] = min(low[id], dfn[t]);
        }
    }
}

int tarjan()
{
    for(int i = 1; i <= n; i ++)
    {
        if(!vis[i])
            dfs(i, i);
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = head[i]; j != -1; j = edge[j].next)
        {
            if(low[i] != low[edge[j].to])
                in[low[i]] ++;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(in[i] == 1)
            ans ++;
    }
    return (ans + 1) / 2;
}

int main ()
{
    int r, a, b;
    while(~scanf("%d %d", &n, &r))
    {
        edge_total = 0;
        memset(head, -1, sizeof(head[0]) * (n+1));
        for(int i =  0; i < r; i ++)
        {
            scanf("%d %d", &a, &b);
            addEdge(a, b);
        }

        tarjan_init();
        printf("%d\n", tarjan());
    }
    return 0;
}
