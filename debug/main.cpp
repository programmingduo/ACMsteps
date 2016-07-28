#include<cstdio>

long long l, r, n;
long long a[20], b[20], vis[20];

int get1(int i)
{
    int total = 0;
    int x = 0;
    while(i)
    {
        if(i&1)
        {
            vis[total ++] = x;
        }
        x++;
        i >>= 1;
    }
    return total;
}

long long GCD(long long x, long long y)
{
    return y==0? x: GCD(y, x % y);
}

long long max(long long x, long long y)
{
    return x>y? x: y;
}

long long min(long long x, long long y)
{
    return x<y? x: y;
}

long long LCA(long long x, long long y)
{
    return x / GCD(x, y) * y;
}

long long cal(int total)
{
    long long lca = 7;
    long long tl = l, tr = r;
    if(total)
    {
        tl = l - b[0];
        tr = r - b[0];
    }
    for(int i = 0; i < total; i ++)
    {
        int temp = vis[i];
        tl = max(tl, l - b[temp]);
        tr = max(tr, r - b[temp]);
        lca = LCA(lca, a[temp]);
    }
    return (tr - tl) / lca;
}

int main ()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t ++)
    {
        scanf("%I64d %I64d %I64d", &n, &l, &r);
        for(int i = 0; i < n; i ++)
        {
            scanf("%I64d %I64d", &a[i], &b[i]);
        }
        long long ans = 0;
        for(int i = 0; i < (1<<n); i ++)
        {
            int total = get1(i);
            if(total % 2)
            {
                ans -= cal(total);
            }
            else
                ans+= cal(total);
//            printf("%lld\n", ans);
        }

        printf("Case #%d: %I64d\n", t, ans);

    }
}
