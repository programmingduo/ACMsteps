#include<cstdio>
#include<string.h>
#include<algorithm>

const int maxn = 1000005;
int x[maxn * 3], value[maxn], ans, l[maxn], r[maxn];

struct node
{
    //存储这个区间的颜色
    int val;
    //存储区间的左端点和右端点
    int left, right;
}tree[maxn * 10];

//左闭右闭
void build(int l, int r, int pos)
{
    tree[pos].val = -1;
    tree[pos].left = l;
    tree[pos].right = r;
    if(l == r)
        return ;

    int m = (l + r) >> 1;
    build(l, m, pos * 2 + 1);
    build(m + 1, r, pos * 2 + 2);
}

//左闭右开
int bSearch(int l, int r, int n)
{
    int m;
    r --;
    while(l <= r)
    {
        m = (l + r) >> 1;
        if(x[m] == n)
            return m;
        if(x[m] > n)
            r = m - 1;
        else
            l = m + 1;
    }
}

//参数依次为：目标区间，目标区间颜色，现在所在节点
void insert(int L, int R, int val, int pos)
{
    int l = tree[pos].left, r = tree[pos].right;
    if(l >= L && r <= R)
    {
        tree[pos].val = val;
        return ;
    }

    if(tree[pos].val != -1)
    {
        tree[pos*2+1].val = tree[pos].val;
        tree[pos*2+2].val = tree[pos].val;
        tree[pos].val = -1;
    }

    int m = (l+r)>>1;
    if(m >= R)
        insert(L, R, val, pos * 2 + 1);
    else if(m < L)
        insert(L, R, val, pos*2+2);
    else
    {
        //一定要更改目标区间，不然永远不会出现l >= L && r <= R的情况
        insert(L, m, val, pos * 2 + 1);
        insert(m+1, R, val, pos*2+2);
    }
}

void query(int pos)
{
    int l = tree[pos].left, r = tree[pos].right;
    if(tree[pos].val != -1)
    {
        if(!value[tree[pos].val])
        {
            ans ++;
            value[tree[pos].val] = 1;
        }
        return ;
    }
    if(l == r)
        return ;

    query(pos *2+1);
    query(pos*2+2);
}

int main ()
{
    int T, n;
    scanf("%d", &T);
    while(T--)
    {
        int temp;
        scanf("%d", &n);
        for(int i = 0; i< n; i ++)
        {
            scanf("%d%d", &l[i], &r[i]);
            x[i * 2] = l[i];
            x[i * 2 + 1] = r[i];
        }

//     离散化，如下面的例子（题目的样例），因为单位1是一个单位长度，将下面的
//     1   2   3   4  6   7   8   10
//     —  —  —  —  —  —  —  —
//     1   2   3   4  5   6   7   8
//离散化  X[1] = 1; X[2] = 2; X[3] = 3; X[4] = 4; X[5] = 6; X[7] = 8; X[8] = 10
//于是将一个很大的区间映射到一个较小的区间之中了，然后再对每一张海报依次更新在宽度为1~8的墙上(用线段树），最后统计不同颜色的段数。
//但是只是这样简单的离散化是错误的，
//如三张海报为：1~10 1~4 6~10
//离散化时 X[ 1 ] = 1, X[ 2 ] = 4, X[ 3 ] = 6, X[ 4 ] = 10
//第一张海报时：墙的1~4被染为1；
//第二张海报时：墙的1~2被染为2，3~4仍为1；
//第三张海报时：墙的3~4被染为3，1~2仍为2。
//最终，第一张海报就显示被完全覆盖了，于是输出2，但实际上明显不是这样，正确输出为3。
//新的离散方法为：在相差大于1的数间加一个数，例如在上面1 4 6 10中间加5（算法中实际上1，4之间，6，10之间都新增了数的）
//X[ 1 ] = 1, X[ 2 ] = 4, X[ 3 ] = 5, X[ 4 ] = 6， X[ 5 ] = 10
//这样之后，第一次是1~5被染成1；第二次1~2被染成2；第三次4~5被染成3
//最终，1~2为2，3为1，4~5为3，于是输出正确结果3。
        temp = n * 2;
        int m = 1;
        std::sort(x, x + temp);
        for(int i = 1; i < temp; i ++)
            if(x[i] != x[i - 1])
                x[m ++] = x[i];
        for(int i = m - 1; i > 0; i --)
            if(x[i] - x[i - 1] > 1)
                x[m ++] = x[i] - 1;
        std::sort(x, x + m);

        build(0, m - 1, 0);
        int li, ri;
        for(int i = 0; i < n; i ++)
        {
//            printf("%d ", i);
            li = bSearch(0, m, l[i]);
            ri = bSearch(0, m, r[i]);
            insert(li, ri, i, 0);
        }

        memset(value, 0, sizeof(value));
        ans = 0;
        query(0);
        printf("%d\n", ans);
    }
    return 0;
}

/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
//#define LL rt<<1
//#define RR rt<<1|1
//#define lson l,m,LL
//#define rson m+1,r,RR
#define bug puts("bugbug");
const int maxn = 11111;
bool hash[10010];
int col[maxn<<4];
struct node{
    int l,r;
}q[10010];
int ans;
int x[maxn<<2];

void pushdown(int rt){
    if(col[rt] != -1){
        col[rt<<1] = col[rt>>1] = col[rt];
        col[rt] = -1;
    }
}
void update(int L,int R,int c,int l,int r,int rt){
    if(L <= l && r <= R){
        col[rt] = c;
        return ;
    }
    pushdown(rt);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, c, 1, m, rt<<1);
    if(R > m)  update(L, R, c, m + 1, r, rt>>1|1);
}
void query(int l,int r,int rt){
    if(col[rt] != -1){
        if(!hash[col[rt]]) ans++;
        hash[col[rt]] = true;
        return;
    }
    if(l == r) return;
    int m = (l + r)>>1;
    query(1, m, rt<<1);
    query(m+1, r, rt>>1|1);
}
int main(){
    int n,i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        memset(col,-1,sizeof(col));
        memset(hash,false,sizeof(hash));
        int cnt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%d",&q[i].l,&q[i].r);
            x[cnt++]=q[i].l;
            x[cnt++]=q[i].r;
        }
        sort(x,x+cnt);
        int m=1;
        for(i=1;i<cnt;i++)
            if(x[i]!=x[i-1])
                x[m++]=x[i];
        for(i=m-1;i>=1;i--)
            if(x[i]!=x[i-1]+1)
                x[m++]=x[i-1]+1;
        sort(x,x+m);

        for(i=0;i<n;i++){
            int l=lower_bound(x,x+m,q[i].l)-x;
            int r=lower_bound(x,x+m,q[i].r)-x;
            update(l,r,i,0,m,1);
        }
        ans=0;
        query(0,m,1);
        printf("%d\n",ans);
    }
    return 0;
}
*/
