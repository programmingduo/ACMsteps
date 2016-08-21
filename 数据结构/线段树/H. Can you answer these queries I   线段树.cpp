#include<cstdio>
#include<algorithm>

using namespace std;

int n, m, limit;              //n��������������� m��m��ѯ�ʣ� limit�����ϵĽڵ���
const int maxn = 500100;     //�洢���ݵ������С
const int inf = ~0u >> 1;     //һ��������ȡ������Сֵ
int a[maxn];                  //�����洢��������

struct node
{
    int sum, opt, maxl, maxr;    //����ͣ� ���ֵ�� ǰ׺����� ��׺�����
}tree[maxn];

void init()
{
    scanf("%d", &n);
    limit = 1;
    while(limit < n)
        limit = limit << 1;
    for(int i = 0; i <= limit << 1; i ++)
        a[i] = -inf;
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
}

void update(node &x, node ls, node rs)                   //ʹ��ʱһ��ע�� ls �������
{
    x.sum = ls.sum + rs.sum;
    x.maxl = max(ls.maxl, ls.sum + rs.maxl);
    x.maxr = max(rs.maxr, ls.maxr + rs.sum);
    x.opt = max(max(ls.opt, rs.opt), ls.maxr + rs.maxl);
}

void build(int x, int ll, int rr)
{
    int ls = x << 1, rs = ls + 1;
    if(ll == rr)
    {
        if(ll <= n)
            tree[x].sum = a[ll];
        else
            tree[x].sum = 0;
        tree[x].maxl = a[ll];
        tree[x].maxr = a[ll];
        tree[x].opt = a[ll];
        return ;
    }

    int mid = ll + rr >> 1;
    build(ls, ll, mid);
    build(rs, mid + 1, rr);
    update(tree[x], tree[ls], tree[rs]);
}

node ask(int x, int ll, int rr, int l, int r)
{
    int ls = x << 1, rs = ls + 1;
    if(ll == l && rr == r)
        return tree[x];
    int mid = ll + rr >> 1;
    node p, q, ans;
    if(mid >= r)
        ans = ask(ls, ll, mid, l, r);
    else if(mid < l)                      //��Ҫ�Ҹ��ж�����
        ans = ask(rs, mid + 1, rr, l, r);
    else
    {
        p = ask(ls, ll, mid, l, mid);
        q = ask(rs, mid + 1, rr, mid + 1, r);
        update(ans, p, q);
    }
    return ans;
}

int main()
{
    init();
    build(1, 1, n);
    scanf("%d", &m);
    int p, q;
    for(int i = 0; i < m; i ++)
    {
        scanf("%d%d", &p, &q);
        printf("%d\n", ask(1, 1, n, p, q).opt);
    }
    return 0;
}
