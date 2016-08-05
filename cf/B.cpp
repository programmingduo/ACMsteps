#include<cstdio>

long long a[100005], n, x, is[100005];
int left(int x)
{
    if(x == 1)
        return n;
    return x - 1;
}

int right(int x)
{
    if(x == n)
        return 1;
    return n + 1;
}
int main ()
{
    long long  m, total = 0, totalc = 0;
    scanf("%I64d %I64d", &n, &m);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%I64d", &a[i]);
        total += a[i];
    }
    for(int i = 1; i <= m; i ++)
    {
        scanf("%I64d", &x);
        totalc += a[x];
        is[x] = 1;
    }

    long long ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        if(is[i])
        {
            ans += a[i] * (total - a[i]);
        }
        else
        {
            long long temp = totalc;
            if(is[left(i)]) temp -= a[left(i)];
            if(is[right(i)]) temp -= a[right(i)];
            ans += a[i] * (temp + a[left(i)] + a[right(i)]);
        }

    }
    printf("%I64d\n", ans / 2);
    return 0;
}
