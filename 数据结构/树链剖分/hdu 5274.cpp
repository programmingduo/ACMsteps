#include<cstdio>
#include<string.h>

const int maxn = 100005;
int num[maxn], siz[maxn], top[maxn], son[maxn];
int dep[maxn], tid[maxn], _rank[maxn], fa[maxn];
int head[maxn], to[maxn * 2], _next[maxn * 2], edge;
int sum[maxn * 4], tim, n;

void init()
{
    memset(head, -1, sizeof(head));
    memset(son, -1, sizeof(son));
    tim = 1;
    edge = 0;
}

void add_edge(int a, int b)
{
    to[edge] = b;
    _next[edge] = head[a];
    head[a] = edge ++;

    to[edge] = a;
    _next[edge] = head[b];
    head[b] = edge ++;
}

void dfs1(int u, int f, int d)
{
    dep[u] = d;
    fa[u] = f;
    siz[u] = 1;
    for(int i = head[u]; i != -1; i = _next[i])
    {
        int v = to[i];
        if(v != f)
        {
            dfs1(v, u, d + 1);
            siz[u] += siz[v];
            if(son[u] == -1 || siz[v] > siz[son[u]])
                son[u] = v;
        }
    }
}

void dfs2(int u, int tp)
{
    top[u] = tp;
    tid[u] = tim;
    _rank[tim ++] = u;
    if(son[u] == -1)
        return ;
    dfs2(son[u], tp);
    for(int i = head[u]; i != -1; i = _next[i])
    {
        int v = to[i];
        if(v != son[u] && v != fa[u])
            dfs2(v, v);
    }
}


void build(int l, int r, int rt)
{
    if(l == r)
    {
        sum[rt] = num[_rank[l]];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    sum[rt] = sum[rt << 1] ^ sum[rt << 1 | 1];
}

void update(int l, int r, int po, int val, int rt)
{
    if(l == r)
    {
        sum[rt] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    if(po <= mid)
        update(l, mid, po, val, rt << 1);
    else
        update(mid + 1, r, po, val ,rt << 1 | 1);
    sum[rt] = sum[rt << 1] ^ sum[rt << 1 | 1];
}

int query(int l, int r, int rt, int ll, int rr)
{
    if(l >= ll && r <= rr)
        return sum[rt];
    int mid = (l + r) >> 1;
    int ret = 0;
    if(ll <= mid)
        ret ^= query(l, mid, rt << 1, ll, rr);
    if(rr > mid)
        ret ^= query(mid + 1, r, rt << 1 | 1, ll, rr);
    return ret;
}

void swap(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

int question(int x, int y)
{
    int ret = 0;
    while(top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]])
            swap(x, y);
        ret ^= query(1, n, 1, tid[top[x]], tid[x]);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y])
        swap(x, y);
    ret ^= query(1, n, 1, tid[x], tid[y]);
    return ret;
}

int main()
{
    int T, m, a, b, x, y, op;
    scanf("%d", &T);
    while(T --)
    {
        init();
        scanf("%d %d", &n, &m);
        for(int i = 1; i < n; i ++)
        {
            scanf("%d %d", &a, &b);
            add_edge(a, b);
        }
        for(int i = 1; i <= n; i ++)
        {
            scanf("%d", &num[i]);
            num[i] ++;
        }

        dfs1(1, 0, 0);
        dfs2(1, 1);
        build(1, n, 1);

        while(m --)
        {
            scanf("%d", &op);
            if(op)
            {
                scanf("%d %d", &x, &y);
                printf("%d\n", question(x, y) - 1);
            }
            else
            {
                scanf("%d %d", &x, &y);
                update(1, n, tid[x], y + 1, 1);
            }
        }
    }
}
