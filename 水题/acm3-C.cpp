#include<cstdio>
int main ()
{
    int n, po, a, b, l, r;
    long long ans = 0;
    scanf("%d%d", &n, &po);
    l = r = po;
    for(long long i= 0; i < n;i ++)
    {
        scanf("%d%d", &a, &b);
        if(a <= l && b >= r)
            continue;
        else if(b < l)
        {
            ans += l - b;
            r = l;
            l = b;
        }
        else if(a > r)
        {
            ans += a - r;
            l = r;
            r = a;
        }
        else
        {
            if(a > l)
                l = a;
            if(b < r)
                r = b;
        }
    }
    printf("%I64d\n", ans);
    return 0;
}
