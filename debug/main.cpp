#include<cstdio>

long long a[100005], x[100005];

int main ()
{
    long long n, m;
    scanf("%I64d %I64d", &n, &m);
    for(int i = 1; i <= n; i ++)
    {
        scanf("%I64d", &a[i]);
    }
    a[n + 1] = a[1];
    a[0] = a[n];
    long long ans = 0;
    for(int i = 1; i <= n; i ++)
        ans += a[i] * a[i + 1];
    for(int i = 1; i <= m; i ++)
    {
        scanf("%I64d", &x[i]);
        for(int j = 1; j <= n; j ++)
        {
            ans += a[x[i]] * a[j];
        }
        ans -= (a[x[i]] * a[x[i] + 1] + a[x[i]] * a[x[i] - 1] + a[x[i]] * a[x[i]]);
        for(int j = 1; j < i; j ++)
            ans -= a[j] * a[x[i]];
    }
    printf("%I64d\n", ans);
    return 0;
}
