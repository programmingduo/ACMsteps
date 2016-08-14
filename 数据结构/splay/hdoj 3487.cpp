#include<cstdio>
#include<cstring>

#define lc (tr[id].c[0])
#define rc (tr[id].c[1])
#define KEY (tr[tr[root].c[1]].c[0])
int root, tot, ans;
const int N = 300006;
int a[N];
struct Tr
{
    int fa, sum, val, c[2], lz;
}tr[N];

inline void swap(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

int newtr(int k, int f)
{
    tr[tot].sum = 1;
    tr[tot].val = k;
    tr[tot].lz = 0;
    tr[tot].c[0] = tr[tot].c[1] = -1;
    tr[tot].fa = f;
    return tot ++;
}

void push(int id)
{
    int lsum, rsum;
    lsum = (lc == -1) ?0 : tr[lc].sum;
    rsum = (rc == -1) ?0 : tr[rc].sum;
    tr[id].sum = lsum + rsum + 1;
}

void lazy(int id)
{
    if(tr[id].lz)
    {
        int t = lc;
        lc = rc;
        rc = t;
        tr[lc].lz ^= 1;
        tr[rc].lz ^= 1;
        tr[id].lz = 0;
    }
}

int build (int l, int r, int f)
{
    if(r < l)
        return -1;
    int mid = (l + r) >> 1;
    int ro = newtr(mid, f);
    tr[ro].c[0] = build(l, mid - 1, ro);
    tr[ro].c[1] = build(mid + 1, r, ro);
    push(ro);
    return ro;
}

//k=1, 右旋，　k=0左旋
void Rotate(int x, int k)
{
    if(tr[x].fa == -1)
        return;
    int fa = tr[x].fa, w;
    lazy(fa), lazy (x);
    tr[fa].c[!k] = tr[x].c[k];
    if(tr[x].c[k] != -1)
        tr[tr[x].c[k]].fa = fa;
    tr[x].fa = tr[fa].fa, tr[x].c[k] = fa;
    if(tr[fa].fa != -1)
    {
        w = tr[tr[fa].fa].c[1] == fa;
        tr[tr[fa].fa].c[w] = x;
    }
    tr[fa].fa = x;
    push(fa);
    push(x);
}

void splay(int x, int goal)
{
    if(x == -1)
        return;
    lazy(x);
    while(tr[x].fa != goal)
    {
        int y = tr[x].fa;
        lazy(tr[y].fa), lazy(y), lazy(x);
        bool w = x == tr[y].c[1];
        if(tr[y].fa != goal && w == (y == tr[tr[y].fa].c[1]))
            Rotate(y, !w);
        Rotate(x, !w);
    }
    if(goal == -1)
        root = x;
    push(x);
}

int find(int k)
{
    int id = root;
    while(id != -1)
    {
        lazy(id);
        int lsum = (lc == -1) ? 0: tr[lc].sum;
        if(lsum >= k)
            id = lc;
        else if(lsum + 1 == k)
            break;
        else
        {
            k = k - lsum - 1;
            id = rc;
        }
    }
    return id;
}

int Index(int l, int r)
{
    splay(find(l), -1);
    splay(find(r), root);
}

int del(int l, int r)
{
    Index(l - 1, r + 1);
    int ro = KEY;
    tr[KEY].fa = -1;
    KEY = -1;
    push(tr[root].c[1]);
    push(root);
    return ro;
}

void cut(int k, int ro)
{
    Index(k, k + 1);
    KEY = ro;
    tr[ro].fa = tr[root].c[1];
    push(tr[root].c[1]);
    push(root);
}

void flip(int l, int r)
{
    Index(l - 1, r + 1);
    lazy(root), lazy(tr[root].c[1]);
    tr[KEY].lz ^= 1;
}

void dfs(int ro)
{
    lazy(ro);
    if(tr[ro].c[0] != -1)
    {
        dfs(tr[ro].c[0]);
    }
    a[ans ++] = tr[ro].val;
    if(tr[ro].c[1] != -1)
        dfs(tr[ro].c[1]);
}

int main()
{
    int n, m, l, r, c;
    char s[10];
    while(~scanf("%d %d", &n, &m))
    {
        if(n == -1 && m == -1)
            break;
        tot = 0;
        root = build(0, n + 1, -1);
        while(m --)
        {
//            printf("%d", m);
            scanf("%s", s);

            if(strcmp(s, "CUT") == 0)
            {
                scanf("%d %d %d", &l, &r, &c);
                int t = del(l + 1, r + 1);
                cut(c + 1, t);
            }
            else
            {
                scanf("%d %d", &l, &r);
                flip(l + 1, r + 1);
            }
        }
        ans = 0;
        dfs(root);
        for(int i = 1; i <= n; i ++)
        {
            if(i > 1)
                printf(" ");
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
