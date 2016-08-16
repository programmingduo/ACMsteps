#include<cstdio>
#include<string.h>

const int maxn = 500005;
int head[maxn], to[maxn], next[maxn], ef[maxn], fa[maxn], d[maxn], vis[maxn], val[maxn], num[26];
int total_edge;
char s[maxn];

void init()
{
    memset(head, -1, sizeof(head));
    total_edge = 0;
    memset(val, -1, sizeof(vis));
    memset(num, 0, sizeof(num));
}

void add_edge(int a, int b, int c)
{
    int &t = total_edge;
    to[t] = b;
    val[t] = c;
    next[t] = head[a];
    head[a] = t ++;

    to[t] = a;
    val[t] = c;
    next[t] = head[b];
    head[b] = t ++;
}

int max(int a, int b)
{
    return a>b ?a :b;
}

void dfs1(int u, int f)
{
//    printf("%d %d\n", u, f);
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
        else
            ef[u] = i;
    }
}

int dfs2(int u, int len, int id, int f)
{
    int ans = 0;
    if(d[u] > len)
    {
        for(int i = head[u]; i != -1; i = next[i])
        {
            int v = to[i];
            if(v == f || val[i] != s[id])
                continue;
            if(len == 1)
                return v;
            if(ans = dfs2(v, len - 1, id + 1, u))
                return ans;
        }
    }
    else if(fa[u] != f && fa[u] != 0 && val[ef[u]] == s[id])
    {
        if(len == 1)
            return u;
        ans = dfs2(fa[u], len - 1, id + 1, u);
        if(ans)
            return ans;
    }
    return 0;
}

int main ()
{
    int n, m, a, b, ans, anss;
    char c;
    while(~scanf("%d %d", &n, &m))
    {
        init();
        for(int i = 1; i < n; i ++)
        {
            scanf("%d %d %c", &a, &b, &c);
            add_edge(a, b, c - 'a');
        }
        scanf("%s", s);

        dfs1(1, 0);
//        printf("123\n");
        int flag = 0, len = m;
        for(int i = 1; i <= n && !flag; i ++)
        {
            for(int j = head[i]; j != -1 && !flag; j = next[j])
            {
                if(val[j] == s[0])
                {
                    if(len == 1)
                    {
                        ans = i;
                        flag = 1;
                    }
                    ans = dfs2(to[j], len - 1, 1, 0);
                    if(ans)
                    {
                        flag = 1;
                    }
                    if(flag)
                        anss = i;
                }
            }
        }

        if(flag)
        {
            printf("%d %d\n", anss, ans);
        }
        else
            printf("-1 -1\n");
    }
    return 0;
}
