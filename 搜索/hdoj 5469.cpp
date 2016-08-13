#include<cstdio>
#include<string.h>

int head[100005], to[100005], next[100005], fa[100005], d[100005], vis[100005];
int total_edge;
char x[100005], s[100005];

void init()
{
    memset(head, -1, sizeof(head));
    total_edge = 0;
}

void add_edge(int u, int v)
{
    to[total_edge] = v;
    next[total_edge] = head[u];
    head[u] = total_edge ++;

    to[total_edge] = u;
    next[total_edge] = head[v];
    head[v] = total_edge ++;
}

int max(int a, int b)
{
    return a > b? a : b;
}

void dfs1(int u, int f)
{
    fa[u] = f;
    d[u] = 1;
    for(int i = head[u]; i != -1; i = next[i])
    {
        int v = to[i];
        if(v != f)
        {
            dfs1(v, u);
            d[u] = max(d[u], d[v] + 1);
        }
    }
}

int dfs2(int u, int len, int id, int f)
{
    if(d[u] > len)
        for(int i = head[u]; i != -1; i = next[i])
        {
            int v = to[i];
            if(v == f || x[v] != s[id])
                continue;
            if(len == 1)
                return 1;
            if(dfs2(v, len - 1, id + 1, u))
                return 1;
        }
    else if(fa[u] != f && fa[u] != 0 && x[fa[u]] == s[id])
    {
        if(len == 1 || dfs2(fa[u], len - 1, id + 1, u))
            return 1;
    }

    return 0;
}

int main ()
{
    int T, a, b;
    scanf("%d", &T);
    for(int t = 1; t <= T; t ++)
    {
        int n;
        scanf("%d", &n);
        init();
        for(int i = 1;  i < n; i ++)
        {
            scanf("%d %d", &a, &b);
            add_edge(a, b);
        }
        dfs1(1, 0);
//        for(int i = 1; i <= n; i ++)
//            printf("%d ", d[i]);
        scanf("%s", x + 1);
        scanf("%s", s);

        int flag = 0, len = strlen(s);
        for(int i = 1; i <= n && !flag; i ++)
        {
            if(x[i] == s[0])
            {
                if(len == 1)
                {
                    flag = 1;
                    break;
                }
//                memset(vis, 0, sizeof(vis));
                if(dfs2(i, len - 1, 1, 0))
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag)
        {
            printf("Case #%d: Find\n", t);
        }
        else
            printf("Case #%d: Impossible\n", t);
    }
    return 0;
}
