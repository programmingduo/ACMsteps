#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;

const int maxn = 100005;
int n, head[maxn], cnt, tot;
int dep[maxn], fa[maxn], son[maxn], siz[maxn], top[maxn], w[maxn];
int sum[maxn<< 2];
struct node
{
    int u, v, w, next;
}edge[maxn << 1];

void add(int u, int v, int w)
{
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt ++;
}

void init()
{
    memset(head, -1, sizeof(head));
    memset(dep, 0, sizeof(dep));
    memset(son, 0, sizeof(son));
    memset(sum, 0, sizeof(sum));
    tot = 0;
    cnt = 0;
}


void dfs1(int u, int p)
{
    siz[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v == p)
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
//        fa[v] = u;
//        dep[v] = dep[u] + 1;
        siz[u] += siz[v];
        if(siz[son[u]] < siz[v])
            son[u] = v;
    }
}

void dfs2(int u, int tp)
{
    w[u] = ++ tot;
    top[u] = tp;
    if(son[u])
        dfs2(son[u], tp);
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v != son[u] && v != fa[u])
            dfs2(v, v);
    }
}

struct Line_Tree
{
    void pushUp(int rt)
    {
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    }

    void update(int p, int x, int l, int r, int rt)
    {
        if(l == r)
        {
            sum[rt] = x;
            return ;
        }
        int mid = (l + r) >> 1;
        if(p <= mid)
            update(p, x, l, mid, rt << 1);
        else
            update(p, x, mid + 1, r, rt << 1 | 1);
        pushUp(rt);
    }

    int query(int ll, int rr, int l, int r, int rt)
    {
        if(ll <= l && rr >= r)
            return sum[rt];
        int mid = (l + r) >> 1;
        int ans = 0;
        if(ll <= mid)
            ans += query(ll, rr, l, mid, rt << 1);
        if(rr >= mid + 1)
            ans += query(ll, rr, mid + 1, r, rt << 1 | 1);
        return ans;
    }
}lt;

int solve(int u, int v)
{
    int f1 = top[u], f2 = top[v], ans = 0;
    while(f1 != f2)
    {
        if(dep[f1] < dep[f2])
        {
            swap(u, v);
            swap(f1, f2);
        }
        ans += lt.query(w[f1], w[u], 1, n, 1);
        u = fa[f1];
        f1 = top[u];
    }
    if(u == v)
        return ans;
    if(dep[u] < dep[v])
        swap(u, v);
    return ans + lt.query(w[son[v]], w[u], 1, n, 1);
}

int main()
{
    int q, s, c, u, v, x;
    while(~scanf("%d %d %d", &n, &q, &s))
    {
        init();
        for(int i =1; i < n; i ++)
        {
            scanf("%d %d %d", &u, &v, &c);
            add(u, v, c);
            add(v, u, c);
        }
        dfs1(1, -1);
        dfs2(1, 1);
        for(int i = 0; i < cnt; i += 2)
        {
            u = edge[i].u;
            v = edge[i].v;
            if(dep[u] < dep[v])
                swap(u, v);
            lt.update(w[u], edge[i].w, 1, n, 1);
        }

        while(q --)
        {
            scanf("%d", &x);
            if(!x)
            {
                scanf("%d", &v);
                printf("%d\n", solve(s, v));
                s = v;
            }
            else
            {
                scanf("%d %d", &x, &c);
                u = edge[(x - 1) << 1].u;
                v = edge[(x - 1) << 1].v;
                if(dep[u] < dep[v])
                    swap(u, v);
                lt.update(w[u], c, 1, n, 1);
            }
        }
    }
}
