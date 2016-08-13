#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

const int N = 50015;

//树上节点的权值，以该节点为根的子树节点个数，节点所在重链的头，节点重链上的子节点
int num[N], siz[N], top[N], son[N];
//节点的深度，节点对应线段树上的位置下标，线段树上位置对应的节点下标，节点的父节点
int dep[N], tid[N], _rank[N], fa[N];
//建图所用
int head[N], to[N * 2], _next[N * 2], edge;
//线段树上每个节点所需维护的值，线段树上节点是否有更改操作
int sum[N * 4], col[N * 4];
//当前深度，树的总结点树（线段树的最右端点）
int tim, n;

void init()
{
    memset(head, -1, sizeof(head));
    memset(son, -1, sizeof(son));
    tim = 1;
    edge = 0;
}

void add_edge(int u, int v)
{
    to[edge] = v;
    _next[edge] = head[u];
    head[u] = edge ++;
    to[edge] = u;
    _next[edge] = head[v];
    head[v] = edge ++;
}

//当前结点，父节点，深度
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

//当前节点，所在重链
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

//由ｒｔ节点的两个儿子节点更新ｒｔ
void push_up(int rt)
{
    sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
}

//rt 点的lazy 操作
void push_down(int rt, int m)
{
    if(col[rt])
    {
        col[rt << 1] += col[rt];
        col[rt << 1 | 1] += col[rt];
        sum[rt << 1] += (m - (m >> 1)) * col[rt];
        sum[rt << 1 | 1] += (m >> 1) * col[rt];
        col[rt] = 0;
    }
}

//线段树建树
void build(int l, int r, int rt)
{
    col[rt] = 0;
    if(l == r)
    {
        sum[rt] = num[_rank[l]];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    push_up(rt);
}

//线段树更新
void update(int l, int r, int v, int ll, int rr, int rt)
{
    if(l <= ll && r >= rr)
    {
        col[rt] += v;
        sum[rt] += v * (rr - ll + 1);
        return ;
    }
    push_down(rt, rr - ll + 1);
    int mid = (ll + rr ) >> 1;
    if(l <= mid)
        update(l, r, v, ll, mid, rt << 1);
    if(r > mid)
        update(l, r, v, mid + 1, rr, rt << 1 | 1);
    push_up(rt);
}

//线段树查询
int query(int l, int r, int rt, int val)
{
    if(l == r)
        return sum[rt];
    push_down(rt, r - l + 1);
    int mid = (l + r) >> 1;
    int ret = 0;
    if(val <= mid)
        ret = query(l, mid, rt << 1, val);
    if(val > mid)
        ret = query(mid + 1, r, rt << 1 | 1, val);
    push_up(rt);
    return ret;
}

//树链更新
void change(int x, int y, int val)
{
    while(top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]])
            swap(x, y);
        update(tid[top[x]], tid[x], val, 1, n, 1);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y])
        swap(x, y);
    update(tid[x], tid[y], val, 1, n, 1);
}

int main ()
{
    int a, b, c, m, q;
    while(~scanf("%d %d %d", &n, &m, &q))
    {
        init();
        memset(num, 0, sizeof(num));
        for(int i = 1; i<= n; i ++)
            scanf("%d", &num[i]);
        for(int i = 1; i <= m; i ++)
        {
            scanf("%d %d", &a, &b);
            add_edge(a, b);
        }
        dfs1(1, 0, 0);
        dfs2(1, 1);
        build(1, n, 1);

        char op[20];
        while(q --)
        {
            scanf("%s", op);
            if(op[0] == 'Q')
            {
                scanf("%d", &a);
                printf("%d\n", query(1, n, 1, tid[a]));
            }
            else
            {
                scanf("%d %d %d", &a, &b, &c);
                if(op[0] == 'D')
                    c = -c;
                change(a, b, c);
            }
        }
    }
}
