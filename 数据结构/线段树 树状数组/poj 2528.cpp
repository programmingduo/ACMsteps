#include<cstdio>
#include<string.h>
#include<algorithm>

const int maxn = 1000005;
int x[maxn * 3], value[maxn], ans, l[maxn], r[maxn];

struct node
{
    //�洢����������ɫ
    int val;
    //�洢�������˵���Ҷ˵�
    int left, right;
}tree[maxn * 10];

//����ұ�
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

//����ҿ�
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

//��������Ϊ��Ŀ�����䣬Ŀ��������ɫ���������ڽڵ�
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
        //һ��Ҫ����Ŀ�����䣬��Ȼ��Զ�������l >= L && r <= R�����
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

//     ��ɢ��������������ӣ���Ŀ������������Ϊ��λ1��һ����λ���ȣ��������
//     1   2   3   4  6   7   8   10
//     ��  ��  ��  ��  ��  ��  ��  ��
//     1   2   3   4  5   6   7   8
//��ɢ��  X[1] = 1; X[2] = 2; X[3] = 3; X[4] = 4; X[5] = 6; X[7] = 8; X[8] = 10
//���ǽ�һ���ܴ������ӳ�䵽һ����С������֮���ˣ�Ȼ���ٶ�ÿһ�ź������θ����ڿ��Ϊ1~8��ǽ��(���߶����������ͳ�Ʋ�ͬ��ɫ�Ķ�����
//����ֻ�������򵥵���ɢ���Ǵ���ģ�
//�����ź���Ϊ��1~10 1~4 6~10
//��ɢ��ʱ X[ 1 ] = 1, X[ 2 ] = 4, X[ 3 ] = 6, X[ 4 ] = 10
//��һ�ź���ʱ��ǽ��1~4��ȾΪ1��
//�ڶ��ź���ʱ��ǽ��1~2��ȾΪ2��3~4��Ϊ1��
//�����ź���ʱ��ǽ��3~4��ȾΪ3��1~2��Ϊ2��
//���գ���һ�ź�������ʾ����ȫ�����ˣ��������2����ʵ�������Բ�����������ȷ���Ϊ3��
//�µ���ɢ����Ϊ����������1�������һ����������������1 4 6 10�м��5���㷨��ʵ����1��4֮�䣬6��10֮�䶼���������ģ�
//X[ 1 ] = 1, X[ 2 ] = 4, X[ 3 ] = 5, X[ 4 ] = 6�� X[ 5 ] = 10
//����֮�󣬵�һ����1~5��Ⱦ��1���ڶ���1~2��Ⱦ��2��������4~5��Ⱦ��3
//���գ�1~2Ϊ2��3Ϊ1��4~5Ϊ3�����������ȷ���3��
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
