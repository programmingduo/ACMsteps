#include<cstdio>
#include<cmath>
long long a[1000005];
struct NODE
{
    int l, r, flag;
    long long sum;
}node[5000000];

long long build(int l, int r, int id)
{
    node[id].l = l;
    node[id].r = r;
    if(l == r)
    {
        if(a[l] == 1)
            node[id].flag = 1;
        else
            node[id].flag = 0;
        return node[id].sum = a[l];
    }

    int mid = (l + r) >> 1, ls = id*2, rs = id * 2 + 1;
    long long x = build(l, mid, ls);
    long long y = build(mid + 1, r, rs);

    if(node[ls].flag && node[rs].flag)
        node[id].flag = 1;
    else
        node[id].flag = 0;

    return node[id].sum = x + y;

}

long long query(int l, int r, int id)
{
    if(node[id].flag)
        return r-l+1;
    if(node[id].l >= l && node[id].r <= r)
        return node[id].sum;

    int mid = (node[id].l + node[id].r) >> 1, ls = id * 2, rs = id * 2 + 1;
    if(l >= mid + 1)
        return query(l, r, rs);
    else if(r <= mid)
        return query(l, r, ls);
    else
        return query(l, mid, ls) + query(mid+1, r, rs);
}

void update(int l, int r, int id)
{
    if(node[id].flag)
        return ;
    if(node[id].l == node[id].r)
    {
        a[l] = sqrt(a[l]);
        node[id].sum = a[l];
        if(a[l] == 1)
            node[id].flag = 1;
        return ;
    }

    int mid = (node[id].l + node[id].r) >> 1, ls = id * 2, rs = id * 2 + 1;
    if(r <= mid)
        update(l, r, ls);
    else if(l >= mid + 1)
        update(l, r, rs);
    else
    {
        update(l, mid, ls);
        update(mid + 1, r, rs);
    }

    if(node[ls].flag && node[rs].flag)
        node[id].flag = 1;
    node[id].sum = node[ls].sum + node[rs].sum;
}

int main ()
{
    int n, t = 0, q, ope, l, r;
    while(~scanf("%d", &n))
    {
        if(t)
            printf("\n");
        printf("Case #%d:\n", ++t);

        for(int i = 1; i <= n; i ++)
        {
            scanf("%lld", &a[i]);
        }
        build(1, n, 1);

        scanf("%d", &q);
        while(q --)
        {
            scanf("%d %d %d", &ope, &l, &r);
            if(l > r)
            {
                int temp = l;
                l = r;
                r = temp;
            }
            if(ope)
            {
                printf("%lld\n", query(l, r, 1));
            }
            else
            {
                update(l, r, 1);
//                for(int i = 1; i <= 9; i ++)
//                    printf("%d %d \n", i, node[i].sum);
            }
        }
    }
}
