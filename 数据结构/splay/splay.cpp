#define N 500000
#define lc (tr[id].c[0])
#define rc (tr[id].c[1])
#define KEY (tr[tr[root].c[1]].c[0])//根的右孩子的左孩子

struct Tr {
    int fa, sum, val, c[2], lz;
}tr[N];

int newtr(int k, int f) {//新建立一个节点
    tr[tot].sum = 1, tr[tot].val =  k;
    tr[tot].c[0] = tr[tot].c[1] = -1;
    tr[tot].lz = 0;
    tr[tot].fa = f;
    return tot++;
}

void Push(int id) {
    int lsum, rsum;
    lsum = (lc == -1)?0:tr[lc].sum;
    rsum = (rc == -1)?0:tr[rc].sum;
    tr[id].sum = lsum+rsum+1;
}

void lazy(int id) {//懒操作
    if (tr[id].lz) {
        swap(lc, rc);
        tr[lc].lz ^= 1, tr[rc].lz ^= 1;
        tr[id].lz = 0;
    }
}

int build(int l, int r, int f) {//建树
    if (r < l) return-1;
    int mid = l+r>>1;
    int ro = newtr(data[mid], f);
    tr[ro].c[0] = build(l, mid-1, ro);
    tr[ro].c[1] = build(mid+1, r, ro);
    Push(ro);
    return ro;
}

void Rotate(int x, int k) {//k=1右旋,k=0左旋
    if (tr[x].fa == -1) return;
    int fa = tr[x].fa, w;
    lazy(fa), lazy(x);
    tr[fa].c[!k] = tr[x].c[k];
    if (tr[x].c[k] != -1) tr[tr[x].c[k]].fa = fa;
    tr[x].fa = tr[fa].fa, tr[x].c[k] = fa;
    if (tr[fa].fa != -1) {
        w = tr[tr[fa].fa].c[1]==fa;
        tr[tr[fa].fa].c[w] = x;
    }
    tr[fa].fa = x;
    Push(fa);
    Push(x);
}

void Splay(int x, int goal) {//将x节点转到goal的儿子上
    if (x == -1) return;
    lazy(x);
    while (tr[x].fa != goal) {
        int y = tr[x].fa;
        lazy(tr[y].fa), lazy(y), lazy(x);
        bool w = x==tr[y].c[1];
        if (tr[y].fa != goal && w == (y==tr[tr[y].fa].c[1]))
            Rotate(y, !w);
        Rotate(x, !w);
    }
    if (goal == -1) root = x;
    Push(x);
}

int find(int k) {//找到第k个节点的ID
    int id = root;
    while (id != -1) {
        lazy(id);
        int lsum = (lc==-1)?0:tr[lc].sum;
        if (lsum >= k) {
            id = lc;
        }
        else if (lsum+1 == k) break;
        else {
            k = k-lsum-1;
            id = rc;
        }
    }
    return id;
}

int Index(int l, int r) {//将区间(l+1, r-1)化成一颗子树
    Splay(find(l), -1);
    Splay(find(r),root);
}

int Getnext(int id) {//寻找后继节点
    lazy(id);
    int p = tr[id].c[1];
    if (p == -1) return id;
    lazy(p);
    while (tr[p].c[0] != -1) {
        p = tr[p].c[0];
        lazy(p);
    }
    return p;
}

int del(int l, int r) {//将【l,r】切掉,返回切掉子树的根节点
    Index(l-1, r+1);
    int ro = KEY;
    tr[KEY].fa = -1;
    KEY = -1;
    Push(tr[root].c[1]);
    Push(root);
    return ro;
}

void cut(int k, int ro) {//将子树ro接到第k个树之后
    Index(k, k+1);
    KEY = ro;
    tr[ro].fa = tr[root].c[1];
    Push(tr[root].c[1]);
    Push(root);
}

void filp(int l, int r) {//对区间【l,r】反转
    Index(l-1, r+1);
    lazy(root), lazy(tr[root].c[1]);
    tr[KEY].lz ^= 1;
}

void Add(int l, int r, int d) {//区间【l,r】的数加上d
    Index(l-1, r+1);
    tr[KEY].add += d;
    tr[KEY].mi += d;
    tr[KEY].val += d;
    Push(tr[root].c[1]);
    Push(root);
}

void Delete(int x) {//删除第x个数
    Index(x-1, x+1);
    tr[KEY].fa = -1;
    tr[tr[root].c[1]].c[0] = -1;
    Push(tr[root].c[1]);
    Push(root);
}

void Insert(int l, int x) {//在l之后插入x
    Index(l, l+1);
    int ro;
    ro = newtr(x, tr[root].c[1]);
    KEY = ro;
    Push(tr[root].c[1]);
    Push(root);
}

void Revolve(int l, int r, int d) {//【l, r】整体右移d位
    int ro = del(r+1-d, r);
    cut(l-1, ro);
}
